#include <iostream>
#include <vector>
#define MAX_SIZE 101
using namespace std;

int N;
vector<int> graph[MAX_SIZE];
int height[MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][501];

void input();
int lowest(int A, int K);
void dfs(int start, int v, int k);

int main() {
    int T, A, K;
    input();
    scanf(" %d", &T);

    for (int j = 1; j <= N; ++j) {
        dfs(j, j, 0);
    }

    for (int i = 0; i < T; ++i) {
        scanf(" %d %d", &A, &K);
        printf("%d\n", lowest(A, K));
    }

    return 0;
}

void input() {
    int M, X, Y;
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", height + i);
    }
    for (int j = 0; j < M; ++j) {
        scanf(" %d %d", &X, &Y);
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }
}

void dfs(int start, int v, int k) {
    if (k > 500)
        return;
    visited[start][v][k] = true;
    for (auto adj : graph[v]) {
        if (!visited[start][adj][k+1])
            dfs(start, adj, k+1);
    }
}

int lowest(int A, int K) {
    int low = 10001;
    for (int i = 1; i <= N; i++) {
        if (visited[A][i][K])
            low = min(low, height[i]);
    }
    return low == 10001 ? -1 : low;
}