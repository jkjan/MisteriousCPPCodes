#include <iostream>
#include <queue>
#define MAX_SIZE 10001
#define INF 9999 * 100 + 1
using namespace std;

typedef struct edge {
    int node, weight;
} edge;

bool operator<(edge a, edge b) {
    return a.weight > b.weight;
}

int n;
vector<edge> graph[MAX_SIZE];

void input();
vector<int> dijkstra(int start);
edge getMax(vector<int> dist);

int main() {
    input();
    vector<int> fromX = dijkstra(1);
    int y = getMax(fromX).node;
    vector<int> fromY = dijkstra(y);
    printf("%d", getMax(fromY).weight);
    return 0;
}

void input() {
    scanf(" %d", &n);
    for (int i = 0; i < n-1; ++i) {
        int root, child, weight;
        scanf(" %d %d %d", &root, &child, &weight);
        graph[root].push_back({child, weight});
        graph[child].push_back({root, weight});
    }
}

vector<int> dijkstra(int start) {
    priority_queue<edge> willVisit;
    vector<int> dist(MAX_SIZE, INF);
    dist[start] = 0;
    willVisit.push({start, 0});
    while (!willVisit.empty()) {
        edge nowVisit = willVisit.top();
        willVisit.pop();
        for (auto g : graph[nowVisit.node]) {
            int newDist = dist[nowVisit.node] + g.weight;
            if (dist[g.node] > newDist) {
                dist[g.node] = newDist;
                willVisit.push({g.node, newDist});
            }
        }
    }
    return dist;
}

edge getMax(vector<int> dist) {
    edge maxDist = {-1, -1};
    for (int i = 1; i <= n; i++)
        if (dist[i] > maxDist.weight && dist[i] != INF)
            maxDist = {i, dist[i]};
    return maxDist;
}