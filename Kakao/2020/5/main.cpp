#include <iostream>
#include <vector>
#define MAX_N 100
#define POLL false
#define STEP true
using namespace std;

int N;
typedef struct frame {
    bool poll, step;
} frame;

frame wall[MAX_N + 1][MAX_N + 1];

bool safe(int y, int x, bool step) {
    if (step) {
        if (0 <= y && y < N && 0 <= x && x <= N-1)
            return wall[y][x].step;
        else
            return false;
    }
    else {
        if (0 < y && y <= N && 0 <= x && x <= N)
            return wall[y][x].poll;
        else
            return false;
    }
}

bool buildIf(int x, int y, bool step) {
    if (step) {
        // 한쪽 끝 부분이 기둥 위에 있거나,
        if (safe(y+1, x, POLL) || safe(y+1, x+1, POLL)) {
            return true;
        }
            // 또는 양쪽 끝 부분이 다른 보와 동시에 연결
        else {
            if (1 <= x && x <= N-2)
                return safe(y, x-1, STEP) && safe(y, x+1, STEP);
            else
                return false;
        }
    }
    else {
        // 바닥 위에 있거나,
        if (y == N)
            return true;
        else // 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
            return ((safe(y, x, STEP) || safe(y, x-1, STEP)) || safe(y+1, x, POLL));
    }
}

bool deleteIf(int x, int y, bool step) {
    if (step) {
        wall[y][x].step = false;
        if (safe(y, x-1, STEP)) {
            if (!buildIf(x-1, y, STEP)) {
                wall[y][x].step = true;
                return false;
            }
        }
        if (safe(y, x+1, STEP)) {
            if (!buildIf(x+1, y, STEP)) {
                wall[y][x].step = true;
                return false;
            }
        }
        if (safe(y, x, POLL)) {
            if (!buildIf(x, y, POLL)) {
                wall[y][x].step = true;
                return false;
            }
        }
        if (safe(y, x+1, POLL)) {
            if (!buildIf(x+1, y, POLL)) {
                wall[y][x].step = true;
                return false;
            }
        }
        return true;
    }
    else {
        wall[y][x].poll = false;
        if (safe(y-1, x, POLL)) {
            if (!buildIf(x, y-1, POLL)) {
                wall[y][x].poll = true;
                return false;
            }
        }
        if (safe(y-1, x, STEP)) {
            if (!buildIf(x, y-1, STEP)) {
                wall[y][x].poll = true;
                return false;
            }
        }
        if (safe(y-1, x-1, STEP)) {
            if (!buildIf(x-1, y-1, STEP)) {
                wall[y][x].poll = true;
                return false;
            }
        }
        return true;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    fill(&wall[0][0], &wall[MAX_N-1][MAX_N], frame{false, false});
    N = n;
    for (auto f : build_frame) {
        if (f[3]) {
            if (buildIf(f[0], N-f[1], f[2])) {
                if (f[2])
                    wall[N-f[1]][f[0]].step = true;
                else
                    wall[N-f[1]][f[0]].poll = true;
            }
        }
        else {
            deleteIf(f[0], N-f[1], f[2]);
        }
    }

    vector<vector<int>> answer;
    for (int j = 0; j <= N; ++j) {
        for (int i = N; i >= 0; i--) {
            if (wall[i][j].poll)
                answer.push_back({j, N-i, POLL});
            if (wall[i][j].step)
                answer.push_back({j, N-i, STEP});
        }
    }
    return answer;
}