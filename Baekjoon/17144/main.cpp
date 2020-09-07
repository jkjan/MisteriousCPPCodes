#include <iostream>
#include <vector>
#include <map>
#define MAX_SIZE 50+1
using namespace std;

typedef struct pos {
    int r, c;
} pos;

typedef struct spreader {
    pos center;
    int amount;
    vector<pos> spreadTo;
} spreader;

int R, C, T;
pos mask[4] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
};

pos operator+(pos a, pos b) {
    return pos{a.r + b.r, a.c + b.c};
}

int room[MAX_SIZE][MAX_SIZE];
void input(pos* refiner);
void spread();
void sweep(pos* refiner);
int getSum();

int main() {
    pos refiner = {-1, -1};
    input(&refiner);
    for (int i = 0; i < T; i++) {
        spread();
        sweep(&refiner);
    }
    printf("%d", getSum());

    return 0;
}

void input(pos* refiner) {
    scanf(" %d %d %d", &R, &C, &T);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf(" %d", &room[i][j]);
            if (room[i][j] == -1) {
                if (refiner->r == -1) {
                    *refiner = {i, j};
                }
            }
        }
    }
}

bool isValid(pos p) {
    return (1 <= p.r && p.r <= R) && (1 <= p.c && p.c <= C);
}

void spread(vector<spreader>* newlySpread) {
    for (auto spread : *newlySpread) {
        for (auto to : spread.spreadTo) {
            room[to.r][to.c] += spread.amount;
        }
        room[spread.center.r][spread.center.c] -= spread.amount * spread.spreadTo.size();
    }
}

void spread() {
    vector<spreader> newlySpread;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            pos center = {i, j};
            int amount;
            if ((amount = room[center.r][center.c]) >= 5) {
                amount /= 5;
                vector<pos> spreadTo;
                for (auto m : mask) {
                    pos adj = center + m;
                    if (isValid(adj)) {
                        if (room[adj.r][adj.c] != -1) {
                            spreadTo.push_back(adj);
                        }
                    }
                }
                newlySpread.push_back({center, amount, spreadTo});
            }
        }
    }
    spread(&newlySpread);
}

void sweep(bool isHorizontal, int l, int from, int to) {
    bool(*end)(int, int) = [](int a, int b){return a > b;};
    int (*iterate)(int) = [](int a){return a-1;};
    int* (*get)(int, int) = [](int i, int j){return &(room[i][j]);};

    if (from > to) {
        end = [](int a, int b){return a < b;};
        iterate = [](int a){return a+1;};
    }
    if (!isHorizontal)
        get = [](int i, int j){return &(room[j][i]);};

    for (int i = to; end(i, from); i = iterate(i)) {
        *get(l, i) = *get(l, iterate(i));
    }

    *get(l, from) = 0;
}

void sweep(pos* refiner) {
    sweep(false, 1, 1, refiner->r-1);
    sweep(true, 1, C, 1);
    sweep(false, C, refiner->r, 1);
    sweep(true, refiner->r, 2, C);

    sweep(false, 1, R, refiner->r+2);
    sweep(true, R, C, 1);
    sweep(false, C, refiner->r+1, R);
    sweep(true, refiner->r+1, 2, C);
}

int getSum() {
    int sum = 0;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            if (room[i][j] > 0)
                sum += room[i][j];
    return sum;
}