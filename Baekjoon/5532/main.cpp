#include <iostream>
#include <cmath>
int main() {
    double L, A, B, C, D, H;
    scanf(" %lg %lg %lg %lg %lg", &L, &A, &B, &C, &D);
    std::cout << L - std::max(ceil(A/C), ceil(B/D));
    return 0;
}
