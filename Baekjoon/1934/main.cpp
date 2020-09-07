#include <iostream>

int lcm(int a, int b);

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++) {
        int A, B;
        scanf(" %d %d", &A, &B);
        printf("%d\n", lcm(A, B));
    }

    return 0;
}

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}