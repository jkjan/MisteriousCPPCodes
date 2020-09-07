#include <cstdio>
#include <queue>
#include <set>

#define MAX_SIZE 1001
#define INF 100000000

using namespace std;

typedef struct _edge {
    int node, weight;
} edge;

bool operator < (edge a, edge b) {
    return a.weight > b.weight;
}

typedef priority_queue<edge> eq;
typedef vector<edge> ev;

void input(int* N, int* M, ev* graph);
ev* dijkstra(int N, ev* graph);

int main() {
    int N, M;
    eq edgeQueue;
    ev graph[MAX_SIZE];
    set<edge> distinguish;

    input(&N, &M, graph);
    ev* path = dijkstra(N, graph);

    for(int i = 1; i <= N; i++) {
        for (auto p : path[i]) {
            distinguish.insert(p);
        }
    }

    printf("%d\n", distinguish.size());
    for(auto p : distinguish) {
        printf("%d %d\n", p.node, p.weight);
    }

    return 0;
}

void input(int* N, int* M, ev* graph){
    scanf(" %d %d", N, M);
    for (int i = 0; i < *M; i++) {
        int A, B, C;
        scanf(" %d %d %d", &A, &B, &C);
        graph[A].push_back(edge{B, C});
        graph[B].push_back(edge{A, C});
    }
}

ev* dijkstra(int N, ev* graph){
    int dist[MAX_SIZE];
    eq edgeQueue;
    bool visited[MAX_SIZE] = {false, };
    ev* path = new ev[MAX_SIZE];

    fill(dist+2, dist+N+1, INF);
    dist[1] = 0;
    visited[1] = true;

    edgeQueue.push(edge{1, 0});

    while (!edgeQueue.empty()) {
        edge cand = edgeQueue.top();
        edgeQueue.pop();
        visited[cand.node] = true;
        for (auto g : graph[cand.node]) {
            int alternative = dist[cand.node] + g.weight;
            if (dist[g.node] > alternative) {
                dist[g.node] = alternative;
                path[g.node].clear();
                for (auto p : path[cand.node]) {
                    path[g.node].push_back(p);
                }
                if (!visited[g.node]) {
                    edgeQueue.push(edge{g.node, dist[g.node]});
                }
                path[g.node].push_back(edge{cand.node, g.node});
            }
        }
    }

    return path;
}
