#include <iostream>
#include <vector>
#define MAX_N 100
using namespace std;
int N;
typedef struct node {
    int y, x;
} node;
typedef long long int ll;
vector<node> graph[MAX_N][MAX_N];
ll visited[MAX_N][MAX_N] = {0, };

void input();
ll dfs(node v);

int main() {
    input();
    printf("%lld", dfs({0, 0}));
    return 0;
}

void input() {
    int jump;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d", &jump);
            if (jump != 0) {
                if (i+jump < N)
                    graph[i][j].push_back({i+jump, j});
                if (j+jump < N)
                    graph[i][j].push_back({i, j+jump});
            }
        }
    }
}

ll dfs(node v) {
    ll ret = 0;
    if (v.y == N-1 && v.x == N-1)
        return 1;

    for (auto adj : graph[v.y][v.x])
        ret += visited[adj.y][adj.x] ? visited[adj.y][adj.x] : dfs(adj);

    visited[v.y][v.x] = ret;
    return ret;
}