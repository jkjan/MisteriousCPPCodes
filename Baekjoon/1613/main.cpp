#include <iostream>
#define MAX_SIZE 401
#define INF 400

int N;
int graph[MAX_SIZE][MAX_SIZE];

void init();
void input();
void floyd();
void answer();

int main() {
    init();
    input();
    floyd();
    answer();
    return 0;
}

void init() {
    std::fill(&(graph[0][0]), &(graph[MAX_SIZE-1][MAX_SIZE]), INF);
    for (int i = 1; i <= N; ++i)
        graph[i][i] = 0;
}

void input() {
    int K, former, latter;
    scanf(" %d %d", &N, &K);
    for (int i = 1; i <= K; ++i) {
        scanf(" %d %d", &former, &latter);
        graph[former][latter] = 1;
    }
}

void floyd() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                graph[i][j] = std::min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
}

int query(int a, int b) {
    if (graph[a][b] != INF)
        return -1;
    else if (graph[b][a] != INF)
        return 1;
    else
        return 0;
}

void answer() {
    int s, a, b;
    scanf(" %d", &s);
    for (int i = 0; i < s; ++i) {
        scanf(" %d %d", &a, &b);
        printf("%d\n", query(a, b));
    }
}