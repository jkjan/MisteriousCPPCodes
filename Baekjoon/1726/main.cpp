#include <iostream>
#include <queue>

using namespace std;
typedef struct node {
    int y, x, head, dist;
} node;

int N, M;
int factory[101][101];

void input(node *start, node *end);

int bfs(node start, node end);

int main() {
    node start, end;
    input(&start, &end);
    printf("%d", bfs(start, end));
    return 0;
}

void input(node *start, node *end) {
    scanf(" %d %d", &M, &N);
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf(" %d", factory[i] + j);
        }
    }
    scanf(" %d %d %d", &(start->y), &(start->x), &(start->head));
    scanf(" %d %d %d", &(end->y), &(end->x), &(end->head));
    start->dist = end->dist = 0;
}

int bfs(node start, node end) {
    bool visited[5][101][101] = {false,};
    queue<node> willVisit;
    willVisit.push(start);
    visited[start.head][start.y][start.x] = true;
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();
        if (nowVisit.head == end.head && nowVisit.y == end.y && nowVisit.x == end.x)
            return nowVisit.dist;

        if (nowVisit.head < 3) {
            if (!visited[3][nowVisit.y][nowVisit.x]) {
                visited[3][nowVisit.y][nowVisit.x] = true;
                willVisit.push({nowVisit.y, nowVisit.x, 3, nowVisit.dist + 1});
            }
            if (!visited[4][nowVisit.y][nowVisit.x]) {
                visited[4][nowVisit.y][nowVisit.x] = true;
                willVisit.push({nowVisit.y, nowVisit.x, 4, nowVisit.dist + 1});
            }
        }
        if (nowVisit.head >= 3) {
            if (!visited[1][nowVisit.y][nowVisit.x]) {
                visited[1][nowVisit.y][nowVisit.x] = true;
                willVisit.push({nowVisit.y, nowVisit.x, 1, nowVisit.dist + 1});
            }
            if (!visited[2][nowVisit.y][nowVisit.x]) {
                if (!factory[nowVisit.y][nowVisit.x]) {
                    visited[2][nowVisit.y][nowVisit.x] = true;
                    willVisit.push({nowVisit.y, nowVisit.x, 2, nowVisit.dist + 1});
                }
            }
        }

        if (nowVisit.head == 3) {
            for (int i = nowVisit.y + 1; i <= nowVisit.y + 3 && i <= M; ++i) {
                if (factory[i][nowVisit.x])
                    break;
                if (!visited[nowVisit.head][i][nowVisit.x]) {
                    if (!factory[i][nowVisit.x]) {
                        visited[nowVisit.head][i][nowVisit.x] = true;
                        willVisit.push({i, nowVisit.x, nowVisit.head, nowVisit.dist + 1});
                    }
                }
            }
        }

        if (nowVisit.head == 4) {
            for (int i = nowVisit.y - 1; i >= nowVisit.y - 3 && i >= 1; --i) {
                if (factory[i][nowVisit.x])
                    break;
                if (!visited[nowVisit.head][i][nowVisit.x]) {
                    if (!factory[i][nowVisit.x]) {
                        visited[nowVisit.head][i][nowVisit.x] = true;
                        willVisit.push({i, nowVisit.x, nowVisit.head, nowVisit.dist + 1});
                    }
                }
            }
        }
        if (nowVisit.head == 1) {
            for (int i = nowVisit.x + 1; i <= nowVisit.x + 3 && i <= N; ++i) {
                if (factory[nowVisit.y][i])
                    break;
                if (!visited[nowVisit.head][nowVisit.y][i]) {
                    if (!factory[nowVisit.y][i]) {
                        visited[nowVisit.head][nowVisit.y][i] = true;
                        willVisit.push({nowVisit.y, i, nowVisit.head, nowVisit.dist + 1});
                    }
                }
            }
        }
        if (nowVisit.head == 2) {
            for (int i = nowVisit.x - 1; i >= nowVisit.x - 3 && i >= 1; --i) {
                if (factory[nowVisit.y][i])
                    break;
                if (!visited[nowVisit.head][nowVisit.y][i]) {
                    if (!factory[nowVisit.y][i]) {
                        visited[nowVisit.head][nowVisit.y][i] = true;
                        willVisit.push({nowVisit.y, i, nowVisit.head, nowVisit.dist + 1});
                    }
                }
            }
        }
    }
    return -1;
}