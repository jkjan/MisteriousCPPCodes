#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 50
using namespace std;
typedef struct pos {
    int y, x;
} pos;
pos delta[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}
int N, L, R;
int land[MAX_SIZE][MAX_SIZE];
void input();
bool bfs(pos start, bool visited[][MAX_SIZE]);

int main() {
    int cnt = 0;
    bool united = true;
    input();
    while (united) {
        united = false;
        bool visited[MAX_SIZE][MAX_SIZE] = {false, };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j]) {
                    if (bfs({i, j}, visited)) {
                        united = true;
                    }
                }
            }
        }
        cnt += united;
    }
    printf("%d", cnt);
    return 0;
}

void input() {
    scanf(" %d %d %d", &N, &L, &R);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d", land[i] + j);
        }
    }
}

bool isValid(pos p) {
    return -1 < p.y && p.y < N && -1 < p.x && p.x < N;
}

bool bfs(pos start, bool visited[][MAX_SIZE]) {
    vector<int*> united;
    united.push_back(&(land[start.y][start.x]));
    queue<pos> willVisit;
    int sum = land[start.y][start.x];
    int cnt = 1;
    willVisit.push(start);
    visited[start.y][start.x] = true;
    while (!willVisit.empty()) {
        pos nowVisit = willVisit.front();
        willVisit.pop();
        for (auto d : delta) {
            pos adj = nowVisit + d;
            if (isValid(adj)) {
                if (!visited[adj.y][adj.x]) {
                    int diff = abs(land[nowVisit.y][nowVisit.x] - land[adj.y][adj.x]);
                    if (L <= diff && diff <= R) {
                        visited[adj.y][adj.x] = true;
                        sum += land[adj.y][adj.x];
                        willVisit.push(adj);
                        cnt++;
                        united.push_back(&(land[adj.y][adj.x]));
                    }
                }
            }
        }
    }
    if (united.size() == 1)
        return false;
    int moved = sum / cnt;
    for (auto u : united)
        *u = moved;
    return true;
}