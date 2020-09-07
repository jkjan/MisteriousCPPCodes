#include <iostream>
#include <cmath>
typedef long long ll;
ll attach(int a, int b);
int main() {
    int A, B, C, D;
    scanf(" %d %d %d %d", &A, &B, &C, &D);
    printf("%lld", attach(A, B) + attach(C, D));
    return 0;
}

ll attach(int a, int b) {
    int digit = (int)log10(b) + 1;
    return a * (ll)pow(10, digit) + b;
}
