#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 10001
using namespace std;

typedef struct _edge {
    int node1, node2;
} edge;

typedef struct queue<edge> eq;

int testCase();
void input(int* N, int* label, eq* edges);
int kruskal(int* label, eq* edges);

int main() {
    int T;
    scanf(" %d", &T);
    for(int i = 0; i < T; i++) {
        printf("%d\n", testCase());
    }
    return 0;
}

int testCase() {
    eq edges;
    int N;
    int label[MAX_SIZE];
    input(&N, label, &edges);
    return kruskal(label, &edges);
}

void input(int* N, int* label, eq* edges) {
    int M;
    scanf(" %d %d", N, &M);
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf(" %d %d", &a , &b);
        edges->push(edge{a, b});
    }
    for (int i = 1; i <= *N; i++) {
        label[i] = i;
    }
}

int getParent(int* label, int a) {
    if (label[a] == a)
        return a;
    return label[a] = getParent(label, label[a]);
}

void unionParent(int* label, int a, int b) {
    a = getParent(label, a);
    b = getParent(label, b);
    if (a < b)
        label[b] = a;
    else
        label[a] = b;
}

bool find(int* label, int a, int b) {
    return getParent(label, a) == getParent(label, b);
}

int kruskal(int* label, eq* edges){
    int types = 0;
    while(!edges->empty()) {
        edge cand = edges->front();
        edges->pop();
        if (!find(label, cand.node1, cand.node2)) {
            types++;
            unionParent(label, cand.node1, cand.node2);
        }
    }
    return types;
}
