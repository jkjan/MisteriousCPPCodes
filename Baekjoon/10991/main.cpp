#include <iostream>

void printLine(int n);

int main() {
    int N;
    scanf(" %d", &N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < N - i; ++j) {
            printf(" ");
        }
        printLine(i);
    }
    return 0;
}

void printLine(int n) {
    for (int i = 0; i < n; ++i) {
        printf("* ");
    }
    printf("\n");
}
