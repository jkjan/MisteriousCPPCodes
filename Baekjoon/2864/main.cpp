#include <iostream>
#define MAX_SIZE 1000001

void input(char* small, char* big);

int main() {
    char smallA[MAX_SIZE], bigA[MAX_SIZE], smallB[MAX_SIZE], bigB[MAX_SIZE];
    input(smallA, bigA);
    input(smallB, bigB);
    printf("%d %d", atoi(smallA) + atoi(smallB), atoi(bigA) + atoi(bigB));
    return 0;
}

void input(char* small, char* big) {
    char c;
    int i = 0;
    while ((c = (char)getchar()) != ' ' && c != '\n') {
        if (c == '6' || c == '5') {
            small[i] = '5';
            big[i] = '6';
        }
        else
            small[i] = big[i] = c;
        i++;
    }
    small[i] = big[i] = 0;
}
