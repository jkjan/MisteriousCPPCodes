#include <iostream>
#include <map>
#include <string>
#define MAX_SIZE 1025
using namespace std;

int N;
int table[MAX_SIZE][MAX_SIZE];
void input();

int main() {
    input();
    return 0;
}

int valid(int x, int y) {
    if ((1 <= x && x <= N) && (1 <= y && y <= N))
        return table[x][y];
    return 0;
}

int subSum(int x1, int y1, int x2, int y2) {
    return table[x2][y2] - table[x2][y1-1] - table[x1-1][y2] + table[x1-1][y1-1];
}

void input() {
    int M, x1, y1, x2, y2;
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf(" %d", &(table[i][j]));
            table[i][j] += (valid(i-1, j) + valid(i, j-1) - valid(i-1, j-1));
        }
    }
    for (int i = 0; i < M; ++i) {
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", subSum(x1, y1, x2, y2));
    }
}