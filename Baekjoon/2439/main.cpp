#include <iostream>
int main() {
    int N, i, blank, star;
    scanf(" %d", &N);
    i = N;
    while (i--) {
        blank = i;
        star = N-i;
        while (blank--)
            printf(" ");
        while (star--)
            printf("*");
        printf("\n");
    }
    return 0;
}
