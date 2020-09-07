#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <lcd.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define LED1 4
#define LED2 5
#define LED3 6
#define delay_ms delay
#define delay_us delayMicroseconds
#define acc_value 0.00390625
#define OFSX        0x1E
#define OFSY        0x1F
#define OFSZ        0x20
#define BW_RATE     0x2C
#define POWER_CTL   0x2D
#define DATA_FORMAT 0x31

void I2C_INIT(int sensor) {
    wiringPiI2CWriteReg8(sensor, OFSX, 0);  // 나중에는 세부적으로 설정해야함
    wiringPiI2CWriteReg8(sensor, OFSY, 0);
    wiringPiI2CWriteReg8(sensor, OFSZ, 0);
    wiringPiI2CWriteReg8(sensor, POWER_CTL, 0x08);
    wiringPiI2CWriteReg8(sensor, DATA_FORMAT, 0x0B);
}

char* ftoa(float f);

// Main Function
int main() {
    int i, sensor, fd;
    short x, y, z;
    float acc_x, acc_y, acc_z, roll, pitch, yaw;

    fd = lcdInit(2, 16, 4, 2, 3, 6, 5, 4, 1, 0, 0, 0, 0);

    wiringPiSetup();

    if ((sensor = wiringPiI2CSetup(0x53)) == -1) {
        fprintf(stderr, "sensor: Unable to initialise I2C: %s\n", strerror(errno));
        return 1;
    }

    printf("I2C device ID: %d\n", sensor);
    printf("ADXL345 Digital Accelerometer Test.....\n");

    I2C_INIT(sensor);  // Sensor init
    delay_ms(500);

    while (1) {
        x = y = z = 0;

        for (i = 0; i < 8; i++) {
            x += ((wiringPiI2CReadReg8(sensor, 0x33) << 8) & 0xFF00) | (wiringPiI2CReadReg8(sensor, 0x32) & 0xFF);
            y += ((wiringPiI2CReadReg8(sensor, 0x35) << 8) & 0xFF00) | (wiringPiI2CReadReg8(sensor, 0x34) & 0xFF);
            z += ((wiringPiI2CReadReg8(sensor, 0x37) << 8) & 0xFF00) | (wiringPiI2CReadReg8(sensor, 0x36) & 0xFF);
            delay_ms(10);  // Default Output Date Rate 100Hz
        }

        x /= 8;
        y /= 8;
        z /= 8;

        acc_x = (float) x * acc_value;
        acc_y = (float) y * acc_value;
        acc_z = (float) z * acc_value;

        roll = atan(acc_y / sqrt(acc_x * acc_x + acc_z * acc_z)) * 180.0 / M_PI;
        pitch = atan(acc_x / sqrt(acc_y * acc_y + acc_z * acc_z)) * 180.0 / M_PI;
        yaw = atan(sqrt(acc_x * acc_x + acc_y * acc_y) / acc_z) * 180.0 / M_PI;

        char *buf = ftoa(roll);

        lcdPuts(fd, buf);
        free(buf);

        if (roll <= 10) {
            if (SegCode[number] == 0x06) {
                digitalWrite(LED1, 0);
                digitalWrite(LED2, 0);
                digitalWrite(LED3, 0);
            }
        }
        else if (roll <= 20) {
            if (SegCode[number] == 0x06) {
                digitalWrite(LED1, 1);
                digitalWrite(LED2, 0);
                digitalWrite(LED3, 0);
            }
        }
        else if (roll <= 30) {
            if (SegCode[number] == 0x06) {
                digitalWrite(LED1, 1);
                digitalWrite(LED2, 1);
                digitalWrite(LED3, 0);
            }

        }
        else {
            if (SegCode[number] == 0x06) {
                digitalWrite(LED1, 1);
                digitalWrite(LED2, 1);
                digitalWrite(LED3, 1);
            }
        }
    }

    return 0;
}


char *ftoa(float f) {
    char *buf = (char *) malloc(sizeof(char) * 50);
    char *cp = buf;
    unsigned long l, rem;

    if (f < 0) {
        *cp++ = '-';
        f = -f;
    }
    l = (unsigned long) f;
    f -= (float) l;
    rem = (unsigned long) (f * 1e6);
    sprintf(cp, "%lu.%6.6lu", l, rem);
    return buf;
}
