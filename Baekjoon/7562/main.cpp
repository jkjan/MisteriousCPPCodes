#include <iostream>
#include <queue>
#define MAX_SIZE 300

typedef struct blank {
    int y, x;
} blank;

int l;
blank deltas[] = {
        {-2, 1}, {-1, 2}, {1,  2}, {2,  1},
        {2,  -1}, {1,  -2}, {-1, -2}, {-2, -1}
};

int tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        printf("%d\n", tc());
    }
    return 0;
}

bool isValid(blank b) {
    return (-1 < b.y && b.y < l) && (-1 < b.x && b.x < l);
}

int bfs(blank start, blank end) {
    int dist[MAX_SIZE][MAX_SIZE] = {0,};
    bool visited[MAX_SIZE][MAX_SIZE] = {false,};
    std::queue<blank> willVisit;
    visited[start.y][start.x] = true;
    willVisit.push(start);
    while (!willVisit.empty()) {
        blank nowVisit = willVisit.front();
        willVisit.pop();
        for (auto d : deltas) {
            blank moved = {nowVisit.y + d.y, nowVisit.x + d.x};
            if (isValid(moved)) {
                if (!visited[moved.y][moved.x]) {
                    dist[moved.y][moved.x] = dist[nowVisit.y][nowVisit.x] + 1;
                    if (moved.y == end.y && moved.x == end.x) {
                        return dist[end.y][end.x];
                    }
                    visited[moved.y][moved.x] = true;
                    willVisit.push(moved);
                }
            }
        }
    }
    return 0;
}

int tc() {
    scanf(" %d", &l);
    blank start, end;
    scanf(" %d %d %d %d", &(start.y), &(start.x), &(end.y), &(end.x));
    return bfs(start, end);
}
