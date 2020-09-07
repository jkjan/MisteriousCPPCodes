#include <iostream>

int main() {
    int one, two;
    scanf(" %d %d", &one, &two);
    int three = one * (two % 10);
    int four = one * ((two % 100) / 10);
    int five = one * (two / 100);
    int six = three + four * 10 + five * 100;
    printf("%d\n%d\n%d\n%d", three, four, five, six);
    return 0;
}