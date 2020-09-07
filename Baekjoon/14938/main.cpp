#include <iostream>
#define MAX_SIZE 101
#define INF 100 * 15 + 1

void input(int* n, int* m, int* item, int dist[][MAX_SIZE]);
void floyd(int n, int dist[][MAX_SIZE]);
int getMaxItem(int n, int m, int* item, int dist[][MAX_SIZE]);

int main() {
    int n, m;
    int item[MAX_SIZE];
    int dist[MAX_SIZE][MAX_SIZE];

    input(&n, &m, item, dist);
    floyd(n, dist);
    printf("%d", getMaxItem(n, m, item, dist));

    return 0;
}

void input(int* n, int* m, int* item, int dist[][MAX_SIZE]) {
    int r, a, b, l;
    scanf(" %d %d %d", n, m, &r);
    std::fill(&(dist[0][0]), &(dist[MAX_SIZE-1][MAX_SIZE]), INF);
    for (int i = 1; i <= *n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 1; i <= *n; ++i)
        scanf(" %d", item + i);
    for (int j = 0; j < r; ++j) {
        scanf(" %d %d %d", &a, &b, &l);
        dist[a][b] = dist[b][a] = (dist[a][b] > l ? l : dist[a][b]);
    }
}

void floyd(int n, int dist[][MAX_SIZE]) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = std::min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
}

int getMaxItem(int n, int m, int* item, int dist[][MAX_SIZE]) {
    int maxItem = 0;
    for (int i = 1; i <= n; ++i) {
        int temp = 0;
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] <= m)
                temp += item[j];
        }
        maxItem = std::max(maxItem, temp);
    }
    return maxItem;
}