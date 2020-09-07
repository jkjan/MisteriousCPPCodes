#include <iostream>
#define MAX_SIZE 250
typedef struct node {
    int y, x;
}node;
int R, C;
char field[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE] = {false, };
node deltas[] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int terrSheep = 0;
int terrWolves = 0;
int sheep = 0;
int wolves = 0;

void input();
void dfs(node v);

int main() {
    input();
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (!visited[i][j]) {
                terrSheep = terrWolves = 0;
                dfs({i, j});
                if (terrSheep > terrWolves) {
                    terrWolves = 0;
                }
                else
                    terrSheep = 0;
                sheep += terrSheep;
                wolves += terrWolves;
            }
        }
    }
    printf("%d %d", sheep, wolves);
    return 0;
}

node operator+(node a, node b) {
    return {a.y + b.y, a.x + b.x};
}

bool isValid(node a) {
    return -1 < a.y && a.y < R && -1 < a.x && a.x < C;
}

void input() {
    scanf(" %d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            scanf(" %c", field[i] + j);
        }
    }
}

void dfs(node v) {
    visited[v.y][v.x] = true;
    if (field[v.y][v.x] == 'o')
        terrSheep++;
    else if (field[v.y][v.x] == 'v')
        terrWolves++;
    for (auto d : deltas) {
        node newNode = v + d;
        if (isValid(newNode)) {
            if (!visited[newNode.y][newNode.x]) {
                if (field[newNode.y][newNode.x] != '#') {
                    dfs(newNode);
                }
            }
        }
    }
}