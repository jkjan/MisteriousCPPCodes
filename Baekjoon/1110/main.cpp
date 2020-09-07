#include <iostream>

int next(int n);

int main() {
    int N, copied, cnt;
    cnt = 0;
    scanf(" %d", &N);
    copied = N;
    do {
        cnt++;
        copied = next(copied);
    } while (N != copied);
    printf("%d", cnt);
    return 0;
}

int next(int n) {
    int tens = n / 10;
    int ones = n % 10;
    return ones * 10 + (tens + ones) % 10;
}