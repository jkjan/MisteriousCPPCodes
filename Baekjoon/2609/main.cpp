#include <iostream>

int gcd(int a, int b);

int main() {
    int a, b;
    scanf(" %d %d", &a, &b);
    int g = gcd(a, b);
    int l = a * b / g;
    printf("%d\n%d");
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