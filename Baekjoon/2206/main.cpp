#include <iostream>
#include <queue>
#define MAX_SIZE 1000
using namespace std;

typedef struct pos {
    int y, x;
}pos;
typedef struct visit {
    pos p;
    int cnt;
    bool crashed;
}visit;

int N, M;
char map[MAX_SIZE][MAX_SIZE];

void input();
int bfs(pos start);

int main() {
    input();
    printf("%d", bfs({0, 0}));
    return 0;
}

void input() {
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &(map[i][j]));
        }
        getchar();
    }
}

pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}

bool isValid(pos p) {
    return ((-1 < p.y && p.y < N) && (-1 < p.x && p.x < M));
}

template <class T> T* get(T a[][MAX_SIZE], pos p) {
    return &(a[p.y][p.x]);
}

int bfs(pos start) {
    pos indexMover[] = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    queue<visit> willVisit;
    willVisit.push({start, 1, false});
    bool visited[2][MAX_SIZE][MAX_SIZE] = {false, };

    while (!willVisit.empty()) {
        visit now = willVisit.front();
        willVisit.pop();

        if (now.p.y == N-1 && now.p.x == M-1)
            return now.cnt;

        for (auto m : indexMover) {
            pos adj = now.p + m;

            if (!isValid(adj)   // 좌표가 유효하지 않거나
            || *get(visited[now.crashed], adj)  // 현 상태에서 방문했던 곳이거나
            || (now.crashed && (*get(map, adj) == '1')))    // 이미 벽을 부순 상태인데, 벽일 경우
                continue;

            /* 여기 들어오는 경우는
             * 1. 벽을 부순 적이 없는데 벽을 만남
             * 2. 벽을 부순 적이 없는데 길임
             * 3. 벽을 부순 적이 있는데 길임 */
            bool crashed = now.crashed;
            *get(visited[crashed], adj) = true;

            /* 2번 경우에 해당
             * 벽을 부순 상태에서 탐색 재개 */
            if (*get(map, adj) == '1') {
                crashed = true;
                *get(visited[crashed], adj) = true;
            }
            willVisit.push({adj, now.cnt + 1, crashed});
        }
    }

    return -1;
}