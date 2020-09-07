#include <iostream>
#include <set>
#include <queue>
#define MAX_SIZE 1001
using namespace std;

int N, M, V;
set<int> graph[MAX_SIZE];

void input();
void dfs(int v, bool* visited);
void bfs(int start);

int main() {
    bool visited[MAX_SIZE] = {false, };
    input();
    dfs(V, visited);
    printf("\n");
    bfs(V);
    return 0;
}

void input() {
    int from, to;
    scanf(" %d %d %d", &N, &M, &V);
    for (int i = 0; i < M; ++i) {
        scanf(" %d %d", &from, &to);
        graph[from].insert(to);
        graph[to].insert(from);
    }
}

void dfs(int v, bool* visited) {
    visited[v] = true;
    printf("%d ", v);
    for (auto adj : graph[v]) {
        if (!visited[adj]) {
            visited[adj] = true;
            dfs(adj, visited);
        }
    }
}

void bfs(int start) {
    queue<int> willVisit;
    bool visited[MAX_SIZE] = {false, };
    willVisit.push(start);
    visited[start] = true;
    printf("%d ", start);
    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto adj : graph[nowVisit]) {
            if (!visited[adj]) {
                printf("%d ", adj);
                visited[adj] = true;
                willVisit.push(adj);
            }
        }
    }
}
