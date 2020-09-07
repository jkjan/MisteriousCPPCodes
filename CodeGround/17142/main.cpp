#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 50 * 50 + 1
#define ACTIVE 3
#define DEAD 2
#define WALL 1
#define MAX_SIZE 50
#define MAX_VIRUS 10
using namespace std;
typedef struct pos {
    int y, x;
} pos;
typedef struct node {
    pos visit, from;
} node;

int N, M, wall, virusCnt, blank, lab[MAX_SIZE][MAX_SIZE];
pos viruses[MAX_VIRUS];

void input();
int getN();

int main() {
    input();
    printf("%d", getN());
    return 0;
}

void input() {
    virusCnt = wall = blank = 0;
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %d", &lab[i][j]);
            if (lab[i][j] == 2) {
                viruses[virusCnt++] = {i, j};
            }
            else if (lab[i][j] == 1)
                wall++;
            else if (lab[i][j] == 0)
                blank++;
        }
    }
}

pos deltas[] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}

bool isValid(pos p) {
    return -1 < p.y && p.y < N && -1 < p.x && p.x < N;
}

int bfs(queue<node>* willVisit, int dist[][MAX_SIZE]) {
    // bool visited[y1][x1][y2][x2] -> y1, x1 에서 y2, x2 까지 도달한 적이 있는가?
    bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE] = {false, };
    int maxDist = 0;        // 바이러스가 최대한 퍼진 시간
    int toActivate = blank; // 바이러스가 퍼져야할 수

    while (!(willVisit->empty()) && toActivate != 0) {
        auto nowVisit = willVisit->front();
        willVisit->pop();

        for (auto d : deltas) {
            pos adj = nowVisit.visit + d;
            // 움직인 곳이 유효하지 않거나 벽이거나 이미 방문한 곳일 땐 패스
            if (!isValid(adj))
                continue;
            if (visited[nowVisit.from.y][nowVisit.from.x][adj.y][adj.x])
                continue;
            if (lab[adj.y][adj.x] == WALL)
                continue;
            // 빈 칸을 새로 밟았을 경우 퍼뜨려야 할 수는 1 감소
            if (dist[adj.y][adj.x] == INF && lab[adj.y][adj.x] == 0) {
                toActivate--;
            }
            // 거리는 최소값으로 갱신
            dist[adj.y][adj.x] = min(dist[adj.y][adj.x], dist[nowVisit.visit.y][nowVisit.visit.x] + 1);
            // 최대한 퍼졌을 때의 시간을 갱신
            maxDist = max(maxDist, dist[adj.y][adj.x]);
            // 방문 표시
            visited[nowVisit.from.y][nowVisit.from.x][adj.y][adj.x] = true;
            willVisit->push({adj, nowVisit.from});
        }
    }

    if (toActivate == 0)
        return maxDist;
    else
        return INF;
}

int getN() {
    bool* mark = new bool[virusCnt];
    int i;
    int minDist = INF;
    for (i = 0; i < virusCnt - M; i++)
        mark[i] = false;
    for (; i < virusCnt; i++)
        mark[i] = true;
    do {
        int k = 0;
        pos* putViruses = new pos[M];
        queue<node> willVisit;
        int dist[MAX_SIZE][MAX_SIZE];
        fill(&dist[0][0], &dist[MAX_SIZE-1][MAX_SIZE], INF);

        for (i = 0; i < virusCnt; i++) {
            // 순열로 바이러스 선택 후, 선택된 바이러스들을 큐에 넣고 거리를 0으로 만들고 활성화하기
            if (mark[i]) {
                putViruses[k++] = viruses[i];
                willVisit.push({viruses[i], viruses[i]});
                dist[viruses[i].y][viruses[i].x] = 0;
                lab[viruses[i].y][viruses[i].x] = ACTIVE;
            }
        }

        minDist = min(minDist, bfs(&willVisit, dist));

        // 선택된 바이러스 다시 비활성화
        for (i = 0; i < M; i++)
            lab[putViruses[i].y][putViruses[i].x] = DEAD;

    } while(next_permutation(mark, mark + virusCnt));

    if (minDist == INF)
        return -1;
    else
        return minDist;
}
