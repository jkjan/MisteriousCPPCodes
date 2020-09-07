#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 20001
#define INF 300000 * 10 + 1
using namespace std;

typedef struct edge {
    int node, weight;
} edge;

bool operator<(edge a, edge b) {
    return a.weight > b.weight;
}

int V, E, K;
vector<edge> graph[MAX_SIZE];

void input();
vector<int> dijkstra();

int main() {
    input();
    vector<int> result = dijkstra();
    for (int i = 1; i <= V; i++) {
        if (result[i] != INF)
            printf("%d\n", result[i]);
        else
            printf("INF\n");
    }
}

void input() {
    int u, v, w;
    scanf(" %d %d", &V, &E);
    scanf(" %d", &K);
    for (int i = 0; i < E; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }
}

vector<int> dijkstra() {
    priority_queue<edge> willVisit;
    vector<int> dist(MAX_SIZE, INF);
    dist[K] = 0;
    willVisit.push({K, 0});
    while (!willVisit.empty()) {
        edge nowVisit = willVisit.top();
        willVisit.pop();
        for (auto adj : graph[nowVisit.node]) {
            int newDist = adj.weight + dist[nowVisit.node];
            if (dist[adj.node] > newDist) {
                dist[adj.node] = newDist;
                willVisit.push({adj.node, dist[adj.node]});
            }
        }
    }
    return dist;
}