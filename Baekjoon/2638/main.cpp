#include <iostream>
#include <vector>
#define MAX_SIZE 100
#define INVALID -1
#define CHEESE 1
#define OUTER 2
using namespace std;

typedef struct pos {
    short y, x;
} pos;

pos operator+(pos a, pos b) {
    return {short(a.y + b.y), short(a.x + b.x)};
}

pos movingIndex[] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

short N, M;
short space[MAX_SIZE][MAX_SIZE];
void input();
int getTime();

int main() {
    input();
    printf("%d", getTime());
    return 0;
}

void input() {
    scanf(" %hd %hd", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %hd", &(space[i][j]));
        }
    }
}

bool isValid(pos p) {
    return (-1 < p.y && p.y < N) && (-1 < p.x && p.x < M);
}

short getSpace(pos p) {
    if (!isValid(p))
        return -1;
    else
        return space[p.y][p.x];
}

void dfs(pos p, bool visited[][MAX_SIZE]) {
    visited[p.y][p.x] = true;
    space[p.y][p.x] = OUTER;
    for (auto m : movingIndex) {
        pos adj = p + m;
        short adjSpace = getSpace(adj);
        if (adjSpace != CHEESE && adjSpace != INVALID) {
            if (!visited[adj.y][adj.x]) {
                dfs(adj, visited);
            }
        }
    }
}

bool isMelting(pos p) {
    short cnt = 0;
    for (auto m : movingIndex) {
        pos adj = m + p;
        if (getSpace(adj) == OUTER) {
            cnt++;
        }
    }
    return cnt >= 2;
}

void melt(vector<pos>* melted) {
    for (auto m : *melted) {
        space[m.y][m.x] = OUTER;
    }
}

int melt() {
    int cheese = 0;
    vector<pos> melted;
    for (short i = 0; i < N; ++i) {
        for (short j = 0; j < M; ++j) {
            if (space[i][j] == CHEESE) {
                if (isMelting({i, j}))
                    melted.push_back({i, j});
                cheese++;
            }
        }
    }
    melt(&melted);
    return cheese;
}

int getTime() {
    int time = 0;
    do {
        bool visited[MAX_SIZE][MAX_SIZE] = {false, };
        dfs(pos{0, 0}, visited);
        time++;
    } while (melt());
    return time - 1;
}