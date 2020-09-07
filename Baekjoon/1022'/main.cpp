#include <iostream>
#include <cmath>

int r1, c1, r2, c2;
int board[50][50];
void init();
void printBoard(int maxD);
int maxDigit();

int main() {
    scanf(" %d %d %d %d", &r1, &c1, &r2, &c2);
    init();
    int maxD = maxDigit();
    printBoard(maxD);
    return 0;
}

int maxDigit() {
    int maxSoFar = -1;
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            maxSoFar = std::max(maxSoFar, board[i-r1][j-c1]);
        }
    }
    return (int)log10(maxSoFar) + 1;
}

void printBoard(int maxD) {
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            int digit = (int)log10(board[i-r1][j-c1]) + 1;
            for (int k = 0; k < maxD - digit; ++k) {
                printf(" ");
            }
            printf("%d ", board[i - r1][j - c1]);
        }
        printf("\n");
    }
}

void setBoard(int i, int j, int x) {
    if (-1 < i-r1 && i-r1 < 50 && -1 < j-c1 && j-c1 < 50) {
        board[i - r1][j - c1] = x;
    }
}

void line(int* now, int dist, int* row, int* col, bool isRow, int dir) {
    if (isRow) {
        int i;
        for (i = 0; i < dist; ++i) {
            setBoard(*row + dir * i, *col, (*now)++);
        }
        *row = *row + dir * (i-1);
    }
    else {
        int i;
        for (i = 0; i < dist; ++i) {
            setBoard(*row, *col + dir * i, (*now)++);
        }
        *col = *col + dir * (i-1);
    }
}

void init() {
    bool isRow = false;
    int dir = 1;
    int now = 1;
    int dist = 2;
    int row, col;
    row = col = 0;

    while (true) {
        line(&now, dist, &row, &col, isRow, dir);
        now--;
        isRow = !isRow;

        dir *= -1;

        if (row == 5000 && col == 5001)
            break;

        line(&now, dist, &row, &col, isRow, dir);
        now--;
        isRow = !isRow;

        dist++;
    }
}