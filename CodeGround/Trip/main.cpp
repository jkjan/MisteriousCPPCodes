#include <iostream>
#include <vector>
#define MAX_SIZE 1000 + 2

typedef struct delta {
    int y, x;
} delta;
delta d[] = {
        {1, 0}, {0, 1}
};
void tc();
int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case # %d\n", i);
        tc();
    }
    return 0;
}
void input(int* H, int* W, int* N, bool board[][MAX_SIZE]) {
    scanf(" %d %d %d", H, W, N);
    for (int i = 1; i <= *H; ++i) {
        for (int j = 1; j <= *W; ++j) {
            scanf(" %d", board[i] + j);
        }
    }
}
bool isValid(int i, int j, int H, int W) {
    return 1 <= i && i <= H && 1 <= j && j <= W;
}
void tc() {
    int H, W, N, a, b;
    bool board[MAX_SIZE][MAX_SIZE];
    input(&H, &W, &N, board);
    for (int i = 0; i < N; ++i) {
        a = b = 1;
        while (isValid(a, b, H, W)) {
            int y = a;
            int x = b;
            a = a + d[board[y][x]].y;
            b = b + d[board[y][x]].x;
            board[y][x] = !board[y][x];
        }
    }
    printf("%d %d\n", a, b);
}