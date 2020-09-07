#include <iostream>
#include <queue>
#include <stack>
#define MAX_SIZE 13
#define MAX_HORSE 11
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;
typedef struct pos {
    int y, x;
} pos;
typedef struct horse {
    int num, dir;
} horse;
typedef struct turn {
    bool isAble;
    pos p;
} turn;
typedef struct block {
    int floor{};
    deque<horse> horses;
} block;

int N, K;
bool flag = false;
turn whatToMove[MAX_HORSE];
block board[MAX_SIZE][MAX_SIZE];

void input();
void moveHorse(pos from, pos to);
void moveAllPossibleHorses();

int main() {
    int cnt = 0;
    fill(whatToMove, whatToMove+MAX_HORSE, turn{false, {0, 0}});
    input();
    while (!flag && cnt <= 1000) {
        moveAllPossibleHorses();
        cnt++;
    }
    printf("%d", cnt <= 1000 ? cnt : -1);
    return 0;
}

pos delta[] = {
        {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}
};

pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}

bool isValid(pos p) {
    return 1 <= p.y && p.y <= N && 1 <= p.x && p.x <= N;
}

void input() {
    int info, r, c, dir;
    scanf(" %d %d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf(" %d", &info);
            board[i][j].floor = info;
        }
    }
    for (int i = 1; i <= K; ++i) {
        scanf(" %d %d %d", &r, &c, &dir);
        whatToMove[i] = {true, r, c};
        board[r][c].horses.push_back({i, dir});
    }
}

void hitWhiteBlock(pos from, pos to) {
    auto blockFrom = &(board[from.y][from.x].horses);
    auto blockTo = &(board[to.y][to.x].horses);
    if (!blockTo->empty())
        whatToMove[blockFrom->front().num].isAble = false;
    else
        whatToMove[blockFrom->front().num].p = to;

    while (!blockFrom->empty()) {
        auto aHorse = blockFrom->front();
        blockTo->push_back(aHorse);
        if (blockTo->size() >= 4)
            flag = true;
        blockFrom->pop_front();
    }
}

void hitRedBlock(pos from, pos to) {
    stack<horse> temp;
    auto horses = &board[from.y][from.x].horses;
    whatToMove[horses->front().num].isAble = false;
    whatToMove[horses->back().num].isAble = true;
    whatToMove[horses->back().num].p = from;
    while (!horses->empty()) {
        auto horseFromFront = horses->front();
        temp.push(horseFromFront);
        horses->pop_front();
    }
    while (!temp.empty()) {
        auto horseFromTop = temp.top();
        horses->push_back(horseFromTop);
        temp.pop();
    }
    hitWhiteBlock(from, to);
}

void hitBlueBlock(pos p) {
    auto horses = &board[p.y][p.x].horses;
    auto horseFromFront = horses->front();
    horses->pop_front();
    horseFromFront.dir += horseFromFront.dir % 2 ? 1 : -1;
    horses->push_front(horseFromFront);
    pos reversed = p + delta[horses->front().dir];
    if (isValid(reversed)) {
        if (board[reversed.y][reversed.x].floor != BLUE) {
            moveHorse(p, reversed);
        }
    }
}

void moveHorse(pos from, pos to) {
    if (isValid(to)) {
        int floor = board[to.y][to.x].floor;
        if (floor == RED)
            hitRedBlock(from, to);
        else if (floor == BLUE)
            hitBlueBlock(from);
        else if (floor == WHITE)
            hitWhiteBlock(from, to);
    }
    else
        hitBlueBlock(from);
}

void moveAllPossibleHorses() {
    for (int i = 1; i <= K; ++i) {
        if (whatToMove[i].isAble) {
            pos from = whatToMove[i].p;
            int dir = board[from.y][from.x].horses.front().dir;
            pos to = from + delta[dir];
            moveHorse(whatToMove[i].p, to);
            if (flag)
                break;
        }
    }
}