#include <iostream>
#define MAX_SIZE 101

bool blank[MAX_SIZE][MAX_SIZE] = {false, };

void paper(int x, int y);
int area();

int main() {
    int T, a, b;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        scanf(" %d %d", &a, &b);
        paper(a, b);
    }
    printf("%d", area());
    return 0;
}

int area() {
    int cnt = 0;
    for (int i = 1; i < MAX_SIZE; ++i) {
        for (int j = 1; j < MAX_SIZE; ++j) {
            cnt += blank[i][j];
        }
    }
    return cnt;
}

void paper(int x, int y) {
    for (int i = y; i < y + 10; ++i) {
        for (int j = x; j < x + 10; ++j) {
            blank[i][j] = true;
        }
    }
}