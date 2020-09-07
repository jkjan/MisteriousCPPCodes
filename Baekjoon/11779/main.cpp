#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 1001
#define INF 999 * 99999 + 1
using namespace std;
typedef struct edge {
    int node, cost;
} edge;
bool operator<(edge a, edge b) {
    return a.cost > b.cost;
}

void input(int* departure, int* arrival, vector<edge>* graph);
vector<int> dijkstra(int departure, int arrival, vector<edge>* graph);

int main() {
    int departure, arrival;
    vector<edge> graph[MAX_SIZE];
    input(&departure, &arrival, graph);
    vector<int> path = dijkstra(departure, arrival, graph);
    printf("%d\n", path.size());
    for (auto p : path) {
        printf("%d ", p);
    }

    return 0;
}

void input(int* departure, int* arrival, vector<edge>* graph) {
    int n, m, from, to, cost;
    scanf(" %d", &n);
    scanf(" %d", &m);
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &from, &to, &cost);
        graph[from].push_back({to, cost});
    }
    scanf(" %d %d", departure, arrival);
}

vector<int> dijkstra(int departure, int arrival, vector<edge>* graph) {
    priority_queue<edge> willVisit;
    int dist[MAX_SIZE];
    vector<int> path[MAX_SIZE];
    for (int i = 1; i < MAX_SIZE; ++i) {
        path[i].push_back(departure);
    }
    fill(dist, dist+MAX_SIZE, INF);
    dist[departure] = 0;
    willVisit.push({departure, 0});
    while (!willVisit.empty()) {
        edge nowVisit = willVisit.top();
        willVisit.pop();
        for (auto g : graph[nowVisit.node]) {
            int newDist = dist[nowVisit.node] + g.cost;
            if (dist[g.node] > newDist) {
                dist[g.node] = newDist;
                path[g.node].clear();
                for (auto another : path[nowVisit.node]) {
                    path[g.node].push_back(another);
                }
                path[g.node].push_back(g.node);
                willVisit.push({g.node, newDist});
            }
        }
    }
    printf("%d\n", dist[arrival]);
    return path[arrival];
}