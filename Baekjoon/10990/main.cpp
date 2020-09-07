#include <iostream>

void printRepeatedly(char c, int n);

int main() {
    int N;
    scanf(" %d", &N);
    printRepeatedly(' ', N-1);
    printf("*\n");
    for (int i = 2; i <= N; ++i) {
        printRepeatedly(' ', N-i);
        printf("*");
        printRepeatedly(' ', 2 * i - 3);
        printf("*");
        printf("\n");
    }
    return 0;
}
void printRepeatedly(char c, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
}
