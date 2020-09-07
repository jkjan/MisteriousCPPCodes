#include <iostream>
#include <queue>

bool isPrime[10000];
int number[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void getPrime();
void tc();

int main() {
    std::fill(isPrime + 2, isPrime + 10000, true);
    getPrime();
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        tc();
    }

    return 0;
}

void getPrime() {
    for (int i = 2; i <= 9999; ++i) {
        for (int j = i + i; j <= 9999; j += i) {
            isPrime[j] = false;
        }
    }
}

typedef struct node {
    int num, dist;
} node;

int bfs(int start, int end) {
    std::queue<node> willVisit;
    bool visited[10000] = {false, };
    willVisit.push({start, 0});
    visited[start] = true;
    while (!willVisit.empty()) {
        auto nowVisit = willVisit.front();
        willVisit.pop();
        int digit = 1;
        while (digit <= 1000) {
            for (auto ud : number) {
                int newPW = nowVisit.num - ((nowVisit.num / digit) % 10) * digit + ud * digit;
                if (1000 <= newPW && newPW <= 9999) {
                    if (!visited[newPW] && isPrime[newPW]) {
                        int newDist = nowVisit.dist + 1;
                        if (newPW == end)
                            return newDist;
                        visited[newPW] = true;
                        willVisit.push({newPW, newDist});
                    }
                }
            }
            digit *= 10;
        }
    }
    return -1;
}

void tc() {
    int start, end;
    scanf(" %d %d", &start, &end);
    int dist = start == end ? 0 : bfs(start, end);
    printf(dist == -1 ? "Impossible\n" : "%d\n", dist);
}