#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 2000
using namespace std;
vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE] = {false, };
int level[MAX_SIZE] = {0, };
int input();
bool dfs(int v, int depth);
bool compare(int a, int b) {
    return level[a] < level[b];
}
int main() {
    int N = input();
    bool exists = false;
    for (int i = 0; i < N; ++i) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }
    for (int i = 0; i < N; ++i) {
        fill(visited, visited + MAX_SIZE, false);
        if (dfs(i, 1))
            exists = true;
    }
    printf("%d", exists);
    return 0;
}
int input() {
    int N, M, a, b;
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf(" %d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        level[a]++;
        level[b]++;
    }
    return N;
}
bool dfs(int v, int depth) {
    visited[v] = true;
    if (depth == 5)
        return true;
    for (auto adj : graph[v]) {
        if (!visited[adj]) {
            if (dfs(adj, depth + 1))
                return true;
        }
    }
    return false;
}