#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 10
#define MAX_H 30

using namespace std;

typedef struct pos {
    int y, x;
} pos;
typedef struct node {
    int y, x, dist;
    pos horizLadders[3]{};
} node;

int N, H;
int ladder[MAX_H + 1][2 * MAX_N];
void input();
int bfs();

int main() {
    input();
    printf("%d", bfs());
    return 0;
}

int indexToVert(int i) {
    return (i + 1) / 2;
}

int vertToIndex(int v) {
    return 2 * v - 1;
}

int indexToHoriz(int i) {
    return i / 2;
}

int horizToIndex(int h) {
    return h * 2;
}

void input() {
    int M, a, b;
    scanf(" %d %d %d", &N, &M, &H);
    for (int i = 0; i < M; ++i) {
        scanf(" %d %d", &a, &b);
        ladder[a][horizToIndex(b)] = 1;
    }
}

bool goDown(int startX, int ladderBackUp[MAX_H + 1][2 * MAX_N]) {
    int nowY = 1;
    int nowX = startX;

    while (nowY <= H) {
        if (vertToIndex(2) <= nowX) { // left
            if (ladderBackUp[nowY][nowX - 1]) {
                nowX -= 2;
                nowY++;
                continue;
            }
        }
        if (nowX <= vertToIndex(N - 1)) { // right
            if (ladderBackUp[nowY][nowX + 1]) {
                nowX += 2;
                nowY++;
                continue;
            }
        }
        nowY++;
    }
    return nowX == startX;
}

int bfs() {
    queue<node> willVisit;
    node start;
    start.y = 1;
    start.x = 2;
    start.dist = 0;
    willVisit.push(start);

    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();

        // 사다리 수가 3을 넘어가면 종료합니다.
        if (nowVisit.dist > 3) {
            break;
        }

        for (int i = 0; i < nowVisit.dist; i++) {
            // cout << nowVisit.horizLadders[i].y << " " << indexToHoriz(nowVisit.horizLadders[i].x) << ", ";
            ladder[nowVisit.horizLadders[i].y][nowVisit.horizLadders[i].x] = 1;
        }
        //    cout << endl;
        int k = 1;
        for (; k <= N; k++) {
            if (!goDown(vertToIndex(k), ladder))
                break;
        }
        for (int i = 0; i < nowVisit.dist; i++) {
            ladder[nowVisit.horizLadders[i].y][nowVisit.horizLadders[i].x] = 0;
        }

        if (k > N)
            return nowVisit.dist;

        if (nowVisit.dist == 3)
            continue;
        int initialX = nowVisit.x;
        for (int i = nowVisit.y; i <= H; ++i) {
            for (int j = initialX; j <= horizToIndex(N - 1); j += 2) {
                node adj = nowVisit;
                bool possible = false;
                // 사다리를 놓는 것이 가능한지 확인합니다.
                if (!ladder[i][j]) { // 현재 위치에 사다리가 없을 경우
                    if (N == 2) // 세로줄이 딸랑 두 개면 무조건 가능합니다.
                        possible = true;
                    else if (j == horizToIndex(1)) // 현재 열이 왼쪽 끝일 경우
                        possible = !ladder[i][j + 2]; // 오른쪽에 사다리가 없어야 가능합니다.
                    else if (j == horizToIndex(N - 1)) // 현재 열이 오른쪽 끝일 경우
                        possible = !ladder[i][j - 2]; // 왼쪽에 사다리가 없어야 가능합니다.
                    else // 중간 쯤 있을 경우엔 왼쪽 오른쪽 둘 다 없어야 가능합니다.
                        possible = (!ladder[i][j - 2] && !ladder[i][j + 2]);
                }
                // 불가능하다 판단되면 다음 사다리 위치로 옮깁니다.
                if (!possible)
                    continue;
                // 이제 현 위치 (i, j)에 사다리를 놓을 수 있습니다.

                adj.y = i; // 다음에 사다리 위치를 정할 곳
                adj.x = j + 4; // 연속되지 않아야 하므로 다음엔 현재 위치의 옆옆에서 시작합니다.
                if (adj.x > horizToIndex(N-1)) {  // 2칸을 옮겼을 때 사다리 범위에서 벗어나게 된다면
                    adj.x = 2; // 그 다음 시작은 x가 2부터, y는 한 줄 밑에서입니다.
                    adj.y ++;
                }
                adj.horizLadders[adj.dist] = {i, j}; // 사다리를 놓았으므로 추가해줍니다.
                adj.dist = nowVisit.dist + 1; // 거리를 늘립니다.
                willVisit.push(adj); // 다음 탐색을 위해 큐에 추가합니다.
            }
            initialX = 2;
        }
    }
    return -1;
}