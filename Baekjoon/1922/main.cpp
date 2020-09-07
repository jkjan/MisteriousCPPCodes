#include <iostream>
#include <queue>

#define MAX_SIZE 100001
using namespace std;

typedef struct _edge {
    int node1, node2, weight;
} edge;

bool operator < (edge a, edge b) {
    return a.weight > b.weight;
}

int N, M;
int label[MAX_SIZE];
priority_queue<edge> edgeQueue;

void input();
int kruskal();

int main() {
    input();
    cout << kruskal();

    return 0;
}

void input() {
    cin >> N >> M;
    int a, b, c;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> c;
        edgeQueue.push(edge{a, b, c});
        label[i] = i;
    }
}

int getParent(int x) {
    if (label[x] == x)
        return x;
    return label[x] = getParent(label[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b)
        label[b] = a;
    else
        label[a] = b;
}

bool find(int a, int b) {
    return getParent(a) == getParent(b);
}

int kruskal() {
    int cost = 0;

    while (!edgeQueue.empty()) {
        edge cand = edgeQueue.top();
        edgeQueue.pop();

        if (!find(cand.node1, cand.node2)) {
            cost += cand.weight;
            unionParent(cand.node1, cand.node2);
        }
    }

    return cost;
}
