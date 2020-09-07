#include <iostream>

int main() {
    int x, y;
    scanf(" %d %d", &x, &y);
    if (0 < x && 0 < y)
        printf("1");
    else if (0 > x && 0 < y)
        printf("2");
    else if (0 > x && 0 > y)
        printf("3");
    else if (0 < x && 0 > y)
        printf("4");
    return 0;
}
