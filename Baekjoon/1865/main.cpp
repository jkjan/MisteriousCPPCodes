#include <iostream>
#include <vector>
#define MAX_SIZE 501
#define INF 500 * 10000 + 1
using namespace std;

typedef struct edge {
    int node, weight;
} edge;

void tc();

int main() {
    int TC;
    scanf(" %d", &TC);
    for (int i = 0; i < TC; ++i) {
        tc();
    }
    return 0;
}

void connect(vector<edge>* graph, bool isWorm) {
    int from, to, weight;
    scanf(" %d %d %d", &from, &to, &weight);
    if (!isWorm) {
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    else
        graph[from].push_back({to, -weight});
}

void input(vector<edge>* graph, int* N, int* M, int* W) {
    scanf(" %d %d %d", N, M, W);
    for (int i = 0; i < *M; ++i) {
        connect(graph, false);
    }
    for (int j = 0; j < *W; ++j) {
        connect(graph, true);
    }
}

void bellmanFord(vector<edge>* graph, int N) {
    int dist[MAX_SIZE];
    fill(dist, dist+MAX_SIZE, INF);
    dist[1] = 0;
    int isCycle = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (auto g : graph[j]) {
                int newDist = dist[j] + g.weight;
                if (dist[g.node] > newDist) {
                    dist[g.node] = newDist;
                    if (i == N)
                        isCycle = 1;
                }
            }
        }
    }
    isCycle ? printf("YES\n") : printf("NO\n");
}

void tc() {
    int N, M, W;
    vector<edge> graph[MAX_SIZE];
    input(graph, &N, &M, &W);
    bellmanFord(graph, N);
}