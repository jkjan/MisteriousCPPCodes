#include <iostream>
#include <cmath>

int main() {
    double R;
    scanf(" %lg", &R);
    printf("%6f\n", R * R * 2 * acos(0.0));
    printf("%6f", R * R * 2);
    return 0;
}
