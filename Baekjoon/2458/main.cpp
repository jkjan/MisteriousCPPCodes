#include <iostream>
#define MAX_SIZE 501
#define INF 124751
using namespace std;

int N;
int dist[MAX_SIZE][MAX_SIZE];

void init();
void input();
void floyd();
void output();

int main() {
    init();
    input();
    floyd();
    output();
    return 0;
}

void init() {
    fill(&(dist[1][1]), &(dist[MAX_SIZE-1][MAX_SIZE]), INF);
    for (int i = 1; i < MAX_SIZE; i++) {
        dist[i][i] = 0;
    }
}

void input() {
    int M;
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        dist[a][b] = 1;
    }
}

void floyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int newDist = dist[i][k] + dist[k][j];
                if (dist[i][j] > newDist)
                    dist[i][j] = newDist;
            }
        }
    }
}

bool isPossible(int student) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i][student] != INF || dist[student][i] != INF) {
            cnt++;
        }
    }
    return cnt == N;
}

void output() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cnt += isPossible(i);
    }
    printf("%d", cnt);
}