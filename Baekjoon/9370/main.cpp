#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define MAX_SIZE 2001
#define INF 50000 * 1000 + 4

using namespace std;

class edge {
public:
    int to, weight;
    edge(int to, int weight) {
        this->to = to;
        this->weight = weight;
    }
    edge() = default;
};

bool operator < (edge a, edge b) {
    return a.weight >  b.weight;
}

void makeGraph(vector<edge>* graph, int m, int g, int h);
int* dijkstra(vector<edge>* graph, int n, int s);
set<int>* test();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++) {
        set<int>* cand = test();
        for(int iter : *cand){
            printf("%d ", iter);
        }
        printf("\n");
        free(cand);
    }

    return 0;
}

set<int>* test() {
    int n, m, t;
    int s, g, h;
    vector<edge> graph[MAX_SIZE];
    scanf(" %d %d %d", &n, &m, &t);
    scanf(" %d %d %d", &s, &g, &h);
    makeGraph(graph, m, g, h);
    auto* cand = new set<int>;
    int* distFromS = dijkstra(graph, n, s);

    for(int j = 1; j <= t; j++) {
        int x;
        scanf(" %d", &x);
        if (distFromS[x] % 2 == 1) {
            cand->insert(x);
        }
    }

    delete[] distFromS;

    return cand;
}

void makeGraph(vector<edge>* graph, int m, int g, int h){
    int a, b, d;
    for(int i = 0; i < m; i++) {
        scanf(" %d %d %d", &a, &b, &d);
        if ((a==g && b==h) || (a==h && b==g)) {
            d = d*2-1;
        }
        else {
            d *= 2;
        }
        graph[a].emplace_back(edge(b, d));
        graph[b].emplace_back(edge(a, d));
    }
}

int* dijkstra(vector<edge>* graph, int n, int s){
    int* distChart = new int[MAX_SIZE];
    bool visited[MAX_SIZE] = {false, };
    priority_queue<edge> distQueue;

    fill(distChart+1, distChart+n+1, INF);
    distChart[s] = 0;

    distQueue.push(edge(s, 0));

    while(!distQueue.empty()) {
        edge closest = distQueue.top();
        distQueue.pop();
        visited[closest.to] = true;

        for(edge & e : graph[closest.to]) {
            int alternative = e.weight + closest.weight;
            if (distChart[e.to] > alternative) {
                if (distChart[e.to] > alternative) {
                    distChart[e.to] = alternative;
                    if (!visited[e.to]) {
                        distQueue.push(edge(e.to, distChart[e.to]));
                    }
                }
            }
        }
    }

    return distChart;
}