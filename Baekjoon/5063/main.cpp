#include <iostream>

void judge();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        judge();
    }
    return 0;
}

void judge() {
    int r, e, c;
    scanf(" %d %d %d", &r, &e, &c);
    int j = e - c;
    if (j > r)
        printf("advertise\n");
    else if (j == r)
        printf("does not matter\n");
    else
        printf("do not advertise\n");
}