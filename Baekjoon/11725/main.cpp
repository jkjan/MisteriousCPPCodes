#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 100001
using namespace std;

void input(int* N, vector<int>* graph);
void bfs(int* N, vector<int>* graph);

int main() {
    int N;
    vector<int> graph[MAX_SIZE];
    input(&N, graph);
    bfs(&N, graph);
    return 0;
}

void input(int* N, vector<int>* graph) {
    int a, b;
    scanf(" %d", N);
    for (int i = 0; i < *N - 1; ++i) {
        scanf(" %d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void bfs(int* N, vector<int>* graph) {
    queue<int> willVisit;
    int parent[MAX_SIZE];
    bool visited[MAX_SIZE] = {false, };
    willVisit.push(1);
    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto g : graph[nowVisit]) {
            if (!visited[g]) {
                parent[g] = nowVisit;
                visited[g] = true;
                willVisit.push(g);
            }
        }
    }
    for (int i = 2; i <= *N; i++) {
        printf("%d\n", parent[i]);
    }
}