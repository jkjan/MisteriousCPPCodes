#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define MAX_SIZE 21
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;
typedef struct node {
    int board[MAX_SIZE][MAX_SIZE];
    int dist;
} node;
typedef struct pos {
    int y, x;
} pos;
typedef struct delta {
    pos start;
    pos deltaY, deltaX;
} delta;
int N;
delta policy[4];
void input(node* start);
int bfs(node start);
void move(int dir, int board[][MAX_SIZE]);
set<string> visited;

int main() {
    node start;
    input(&start);
    if (N == 1) {
        printf("%d", start.board[1][1]);
        return 0;
    }
    policy[UP] = {{2, 1}, {1, 0}, {0, 1}};
    policy[DOWN] = {{N-1, 1}, {-1, 0}, {0, 1}};
    policy[LEFT] = {{N, 2}, {0, 1}, {-1, 0}};
    policy[RIGHT] = {{1, N-1}, {0, -1}, {1, 0}};
    printf("%d", bfs(start));

    return 0;
}

void input(node* start) {
    scanf(" %d", &N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf(" %d", &(start->board[i][j]));
        }
    }
    start->dist = 0;
}

pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}

pos operator-(pos a, pos b) {
    return {a.y - b.y, a.x - b.x};
}

bool isValid(pos a) {
    return (1 <= a.y && a.y <= N) && (1 <= a.x && a.x <= N);
}

void move(int dir, int board[][MAX_SIZE]) {
    pos now = policy[dir].start;
    int cnt = 0;
    int* first;
    vector<int*> changed;
    int to;

    if (dir < 2) {
        first = &(now.x);
        to = policy[dir].start.x;
    }
    else {
        first = &(now.y);
        to = policy[dir].start.y;
    }

    while (true) {
        for (int i = 0; i < N; ++i) {
            cnt++;
            pos temp = now;

            if (board[now.y][now.x] != 0) {
                do {
                    temp = temp - policy[dir].deltaY;
                } while (isValid(temp) && (board[temp.y][temp.x] == 0));

                if (!isValid(temp) || board[temp.y][temp.x] != board[now.y][now.x]) {
                    temp = temp + policy[dir].deltaY;
                    int t = board[now.y][now.x];
                    board[now.y][now.x] = 0;
                    board[temp.y][temp.x] = t;
                }

                else {
                    board[now.y][now.x] = 0;
                    board[temp.y][temp.x] *= -2;
                    changed.push_back(&(board[temp.y][temp.x]));
                }
            }
            now = now + policy[dir].deltaX;
        }
        if (cnt == N * (N-1))
            break;
        *first = to;
        now = now + policy[dir].deltaY;
    }
    for (auto c : changed) {
        *c *= -1;
    }
}

int getMax(int board[][MAX_SIZE]) {
    string s;
    int maxBlock = board[1][1];
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            maxBlock = max(maxBlock, board[i][j]);
            s += (to_string(board[i][j]) + "|");
        }
    }
    if (visited.count(s))
        return -1;
    visited.insert(s);
    return maxBlock;
}

int bfs(node start) {
    queue<node> willVisit;
    willVisit.push(start);
    int ret = getMax(start.board);
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();

        for (int i = UP; i <= RIGHT; i++) {
            node moved = nowVisit;
            moved.dist = nowVisit.dist + 1;
            if (moved.dist > 5)
                return ret;
            move(i, moved.board);

            int maxBlock = getMax(moved.board);
            if (maxBlock != -1) {
                ret = max(ret, maxBlock);
                willVisit.push(moved);
            }
        }
    }
    return ret;
}