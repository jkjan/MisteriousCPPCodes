#include <cstdio>
#include <queue>
#define MAX_SIZE 100001
using namespace std;
typedef struct _edge {
    int node1, node2, weight;
} edge;
bool operator < (edge a, edge b) {
    return a.weight > b.weight;
}

typedef struct priority_queue<edge> eq;

void input(int* N, int* M, int* label, eq* edgeQueue);
int kruskal(int* label, eq* edgeQueue);

int main() {
    int N, M;
    int label[MAX_SIZE];
    eq edgeQueue;
    input(&N, &M, label, &edgeQueue);
    printf("%d\n", kruskal(label, &edgeQueue));
    return 0;
}

void input(int* N, int* M, int* label, eq* edgeQueue) {
    scanf(" %d %d", N, M);
    for (int i = 0; i < *M; i++) {
        int A, B, C;
        scanf(" %d %d %d", &A, &B, &C);
        edgeQueue->push(edge{A, B, C});
    }
    for (int i = 1; i <= *N; i++) {
        label[i] = i;
    }
}

int getParent(int* label, int x) {
    if (label[x] == x)
        return x;
    return label[x] = getParent(label, label[x]);
}

void unionParent(int* label, int a, int b) {
    a = getParent(label, a);
    b = getParent(label, b);
    if (a > b)
        label[a] = b;
    else
        label[b] = a;
}

bool find(int* label, int a, int b) {
    return getParent(label, a) == getParent(label, b);
}

int kruskal(int* label, eq* edgeQueue) {
    int cnt = 0;

    while (!edgeQueue->empty()) {
        edge cand = edgeQueue->top();
        edgeQueue->pop();
        if (!find(label, cand.node1, cand.node2)) {
            cnt += cand.weight;
            printf("%d %d : %d 연결\n", cand.node1, cand.node2, cand.weight);
            unionParent(label, cand.node1, cand.node2);
        }
    }

    return cnt;
}