#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 10000 + 1
#define INF 100000 * 1000 + 1

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
    return a.weight > b.weight;
}

void makeGraph(vector<edge> *graph, int d);
int* dijkstra(vector<edge>* graph, int start, int n);

int main() {
    int t;
    scanf(" %d", &t);

    for (int i = 0; i < t; i++) {
        int n, d, c;
        vector<edge> graph[MAX_SIZE];
        scanf(" %d %d %d", &n, &d, &c);
        makeGraph(graph, d);
        int* distChart = dijkstra(graph, c, n);
        int last = -1;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (distChart[j] < INF) {
                cnt++;
                last = max(last, distChart[j]);
            }
        }
        printf("%d %d\n", cnt, last);
    }

    return 0;
}

void makeGraph(vector<edge>* graph, int d) {
    int a, b, s;
    for (int i = 0; i < d; i++) {
        cin >> a >> b >> s;
        graph[b].emplace_back(edge(a, s));
    }
}

int* dijkstra(vector<edge>* graph, int start, int n) {
   int* distChart = new int[n];
   priority_queue<edge> distQueue;
   edge closest{};
   bool visited[MAX_SIZE] = {false, };
   fill(distChart+1, distChart+n+1, INF);
   distChart[start] = 0;

   for (int i = 1; i <= n; i++) {
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
              if (!visited[e.to])
                  distQueue.push(edge(e.to, distChart[e.to]));
          }
      }
   }

   return distChart;
}
