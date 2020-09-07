#include <iostream>
#define MAX_SIZE 17
#define HORIZONTAL 0
#define VERTICAL 1

typedef struct pos {
    int y, x;
} pos;

typedef struct pipe {
    pos p;
    short type;
} pipe;

typedef struct move {
    int y, x;
    short method[3];
} move;

int N;
int house[MAX_SIZE][MAX_SIZE];
int cases = 0;

move m[3] = {
        {0, 1, {0, 2, -1}},
        {1, 0, {1, 2, -1}},
        {1, 1, {0, 1, 2}}
};

void input();
void trial(pipe p);

int main() {
    input();
    trial({{1, 1}, HORIZONTAL});
    printf("%d", cases);
    return 0;
}

void input() {
    scanf(" %d", &N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf(" %d", &(house[i][j]));
        }
    }
}

bool validCheck(pos p) {
    if ((1 <= p.y && p.y <= N) && (1 <= p.x && p.x <= N)) {
        return !house[p.y][p.x];
    }
    return false;
}

bool validCheck(pos p, short method) {
    if (method == HORIZONTAL)
        return validCheck({p.y, p.x+1});
    else if (method == VERTICAL)
        return validCheck({p.y+1, p.x});
    else
        return (validCheck({p.y, p.x+1}) &&
                validCheck({p.y+1, p.x}) &&
                validCheck({p.y+1, p.x+1}));
}

void moveIfPossible(pos p, short* method) {
    for (int i = 0; i < 3; ++i) {
        if (method[i] >= 0) {
            if (validCheck(p, method[i])) {
                trial({p, method[i]});
            }
        }
    }
}

bool isDestination(pos p) {
    if (p.y == N && p.x == N) {
        cases++;
        return true;
    }
    return false;
}

void trial(pipe p) {
    pos tip = {p.p.y + m[p.type].y, p.p.x + m[p.type].x};
    if (isDestination(tip)) return;
    moveIfPossible(tip, m[p.type].method);
}