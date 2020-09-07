#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 5001
#define INF 1000000001
using namespace std;
typedef struct node {
    int num, dist;
} node;
int N, Q;
vector<node> graph[MAX_SIZE];
void input();
int query();

int main() {
    input();
    for (int i = 0; i < Q; ++i) {
        printf("%d\n", query());
    }
    return 0;
}

void input() {
    int p, q, r;
    scanf(" %d %d", &N, &Q);
    for (int i = 0; i < N-1; ++i) {
        scanf(" %d %d %d", &p, &q, &r);
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }
}

int query() {
    int k, v;
    scanf(" %d %d", &k, &v);
    queue<int> willVisit;
    int dist[MAX_SIZE];
    bool visited[MAX_SIZE] = {false, };
    fill(dist, dist+MAX_SIZE, INF);
    visited[v] = true;
    willVisit.push(v);
    int cnt = 0;
    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto adj : graph[nowVisit]) {
            if (!visited[adj.num]) {
                dist[adj.num] = min(adj.dist, dist[nowVisit]);
                willVisit.push(adj.num);
                visited[adj.num] = true;
                if (dist[adj.num] >= k)
                    cnt++;
            }
        }
    }
    return cnt;
}