#include <iostream>

int main() {
    int N;
    scanf(" %d", &N);
    for (int i = N; i >= 1; i--) {
        for (int k = 0; k < N - i; ++k) {
            printf(" ");
        }
        for (int j = 0; j < i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
