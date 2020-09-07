#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 1001
using namespace std;

int tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        printf("%d\n", tc());
    }
    return 0;
}

int input(bool prior[][MAX_SIZE], int* S, int* D, vector<int>* graph) {
    int N, K, X, Y, W;
    bool isStart[MAX_SIZE] = {false, };
    scanf(" %d %d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", D+i);
    }
    for (int j = 0; j < K; ++j) {
        scanf(" %d %d", &X, &Y);
        graph[X].push_back(Y);
        prior[Y][X] = true;
        isStart[Y] = true;
    }
    for (int k = 1; k <= N; ++k) {
        if (!isStart[k]) {
            *S = k;
            break;
        }
    }
    scanf(" %d", &W);
    return W;
}


int bfs(bool prior[][MAX_SIZE], int S, int* D, int W, vector<int>* graph) {
    int till[MAX_SIZE] = {0, };
    bool visited[MAX_SIZE] = {false, };
    queue<int> willVisit;
    willVisit.push(S);
    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();

        for (auto adj : graph[nowVisit]) {
            if (!visited[adj]) {
                visited[adj] = true;
                willVisit.push(adj);
            }
            if (prior[adj][nowVisit]) {
                till[adj] = max(till[adj], till[nowVisit] + D[nowVisit]);
            }
        }
    }

    return till[W] + D[W];
}

int tc() {
    int S;
    int D[MAX_SIZE];
    bool prior[MAX_SIZE][MAX_SIZE] = {false, };
    vector<int> graph[MAX_SIZE];
    int W = input(prior, &S, D, graph);
    return bfs(prior, S, D, W, graph);
}
