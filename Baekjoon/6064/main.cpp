#include <iostream>

int tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        printf("%d\n", tc());
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

int tc() {
    int M, N, x, y;
    scanf(" %d %d %d %d", &M, &N, &x, &y);
    int limit = lcm(M, N);
    while (x <= limit) {
        if (x % N == y || ((x % N == 0) && (y == N)))
            return x;
        x += M;
    }
    return -1;
}