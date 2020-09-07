#include <iostream>

void printRepeatedly(char c, int n);

int main() {
    int N;
    scanf(" %d", &N);
    for (int i = 1; i <= N; ++i) {
        printRepeatedly(' ', i - 1);
        printRepeatedly('*', 2 * N - 2 * i + 1);
        printf("\n");
    }
    return 0;
}

void printRepeatedly(char c, int n) {
    for (int i = 0; i < n; ++i) {
         printf("%c", c);
    }
}