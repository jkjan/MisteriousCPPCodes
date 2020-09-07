#include <iostream>
#include <set>
#include <queue>
#define MAX_SIZE 1001
using namespace std;

int N, M, V;
set<int> graph[MAX_SIZE];
bool visited[MAX_SIZE] = {false, };

void input();
void dfs(int v);
void bfs(int start);

int main() {
    input();
    dfs(V);
    printf("\n");
    fill(visited, visited + MAX_SIZE, false);
    bfs(V);
    return 0;
}

void input() {
    int A, B;
    scanf(" %d %d %d", &N, &M, &V);
    for (int i = 0; i < M; ++i) {
        scanf(" %d %d", &A, &B);
        graph[A].insert(B);
        graph[B].insert(A);
    }
}

void dfs(int v) {
    visited[v] = true;
    printf("%d ", v);
    for (auto adj : graph[v]) {
        if (!visited[adj]) {
            dfs(adj);
        }
    }
}

void bfs(int start) {
    queue<int> willVisit;
    willVisit.push(start);
    visited[start] = true;
    printf("%d ", start);
    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto adj : graph[nowVisit]) {
            if (!visited[adj]) {
                visited[adj] = true;
                printf("%d ", adj);
                willVisit.push(adj);
            }
        }
    }
}
