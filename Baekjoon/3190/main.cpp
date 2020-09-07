#include <iostream>
#include <vector>
#define MAX_SIZE 101
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

typedef struct _pos {
    int r, c;
} pos;

bool operator == (pos a, pos b) {
    return a.r == b.r && a.c == b.c;
}

void input(int* N, int* K, bool board[][MAX_SIZE], char* change);
bool move(int* N, int* dir, vector<pos>* body, bool board[][MAX_SIZE]);
void changeDir(int* dir, char shift);

int main() {
    bool board[MAX_SIZE][MAX_SIZE] = {false, };
    int dir;
    int N, K;
    char change[10001] = {0, };
    vector<pos> body;
    int sec = 0;

    body.push_back(pos{1, 1});
    input(&N, &K, board, change);

    while (move(&N, &dir, &body, board)) {
        changeDir(&dir, change[++sec]);
    }

    printf("%d", sec+1);

    return 0;
}

void input(int* N, int* K, bool board[][MAX_SIZE], char* change) {
    int x, y, L;

    cin >> *N;
    cin >> *K;

    for (int i = 0; i < *K; i++) {
        cin >> x >> y;
        board[x][y] = true;
    }

    cin >> L;

    for (int i = 0; i < L; i++) {
        int sec;
        char dir;
        cin >> sec >> dir;
        change[sec] = dir;
    }
}

void changeDir(int* dir, char shift) {
    // 왼쪽
    if (shift == 'L')
        *dir > 0 ? *dir-- : (*dir = LEFT);
    // 오른쪽
    else if (shift == 'D')
        *dir = (++*dir)%4;
}

bool move(int* N, int* dir, vector<pos>* body, bool board[][MAX_SIZE]) {
    int dif[][4] = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
    };

    // 머리가 움직이기로 예정된 곳
    int newR = body->at(0).r + dif[*dir][0];
    int newC = body->at(0).c + dif[*dir][1];

    // 1. 범위 넘어가거나
    if (!((1 <= newR && newR <= *N) && (1 <= newC && newC <= *N))) {
        return false;
    }

    // 2. 자기 몸에 닿을 시 false 반환 후 종료
    else {
        for (auto i : *body) {
            if (i == pos{newR, newC})
                return false;
        }
    }

    // 사과 먹었다면 꼬리 추가
    if (board[newR][newC]) {
        board[newR][newC] = false;
        body->push_back(pos{0, 0});
    }

    // 몸 움직이기
    for (int i = body->size()-1; i >= 1; i--) {
        body->at(i) = body->at(i-1);
    }

    // 머리 움직이기
    body->at(0) = pos{newR, newC};

    return true;
}