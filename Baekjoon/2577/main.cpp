#include <iostream>

int main() {
    int num[10] = {0, };
    int A, B, C;
    scanf(" %d %d %d", &A, &B, &C);
    int N = A * B * C;
    while (N != 0) {
        num[N % 10]++;
        N /= 10;
    }
    for (int n : num)
        printf("%d\n", n);
    return 0;
}