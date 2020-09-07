#include <iostream>
#include <vector>
#include <queue>
#define V1 1
#define V2 2
#define MAX_SIZE 801
#define INF 100000000

using namespace std;

class edge{
public:
    int to;
    int weight;
    edge(int to, int weight) {
        this->to = to;
        this->weight = weight;
    }
    edge() = default;
};

bool operator < (edge a, edge b) {
    return a.weight > b.weight;
}

int N;
vector<edge> graph[MAX_SIZE];

void makeGraph();
long long* dijkstra(int start);

int main() {
    makeGraph();

    int v1, v2;
    scanf(" %d %d", &v1, &v2);
    auto** distChart = new long long *[3];
    distChart[V1] = dijkstra(v1);
    distChart[V2] = dijkstra(v2);

    long long h1 = distChart[V1][1] + distChart[V1][v2] + distChart[V2][N];
    long long h2 = distChart[V2][1] + distChart[V2][v1] + distChart[V1][N];
    long long result = min(h1, h2);

    printf("%lld", ((result < INF) ? result : -1));

    delete[] (distChart);

    return 0;
}

void makeGraph() {
    int E;
    int from, to, weight;
    scanf(" %d %d", &N, &E);

    for (int i = 0; i < E; i++) {
        scanf(" %d %d %d", &from, &to, &weight);
        graph[from].emplace_back(edge(to, weight));
        graph[to].emplace_back(edge(from, weight));
    }
}

long long* dijkstra(int start) {
    priority_queue<edge> distQueue;
    auto* distChart = new long long [N+1];
    bool* visited = new bool[N+1];
    edge closest{};

    fill(distChart+1, distChart+N+1, INF);
    distChart[start] = 0;

    for (int i = 1; i <= N; i++) {
        distQueue.push(edge(i, distChart[i]));
    }

    while (!distQueue.empty()) {
        closest = distQueue.top();
        distQueue.pop();
        visited[closest.to] = true;

        for (edge & e: graph[closest.to]) {
            int alternative = closest.weight + e.weight;
            if (distChart[e.to] > alternative) {
                distChart[e.to] = alternative;
                distQueue.push(edge(e.to, distChart[e.to]));
            }
        }
    }

    delete[] (visited);

    return distChart;
}