#include <iostream>
#define MAX_SIZE 500

typedef struct node {
    int y, x;
} node;
node operator+(const node a, const node b) {
    return {a.y + b.y, a.x + b.x};
}
node deltas[] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
int N, M;
int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

void input();
int dfs(node v);

int main() {
    input();
    std::fill(dp[0], dp[MAX_SIZE-1]+MAX_SIZE, -1);
    printf("%d", dfs({0, 0}));
    return 0;
}

void input() {
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf(" %d", map[i]+j);
}

bool isValid(node n, int now) {
    if ((-1 < n.y && n.y < N) && (-1 < n.x && n.x < M))
        return map[n.y][n.x] < now;
    else
        return false;
}

int dfs(node v) {
    if (v.y == N-1 && v.x == M-1) {
        return 1;
    }
    int ret = 0;
    for (auto d : deltas) {
        auto moved = v + d;
        if (isValid(moved, map[v.y][v.x])) {
            if (dp[moved.y][moved.x] == -1)
                ret += dfs(moved);
            else
                ret += dp[moved.y][moved.x];
        }
    }
    dp[v.y][v.x] = ret;
    return ret;
}