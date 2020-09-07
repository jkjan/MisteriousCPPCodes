#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 10001

using namespace std;
typedef struct node {
    int v, dist;
} node;

vector<node> graph[MAX_SIZE];
void input();
int binarySearch(int start, int end);

int main() {
    input();
    int start, end;
    scanf("%d %d", &start, &end);
    printf("%d ", binarySearch(start, end));
    return 0;
}

int maxLimit = 0;

void input() {
    int N, M, A, B, C;
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf(" %d %d %d", &A, &B, &C);
        maxLimit = max(maxLimit, C);
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
}

bool bfs(int start, int end, int limit) {
    queue<int> willVisit;
    bool visited[MAX_SIZE] = {false, };
    willVisit.push(start);
    visited[start] = true;
    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();

        if (nowVisit == end)
            return true;

        for (auto adj : graph[nowVisit]) {
            if (!visited[adj.v]) {
                if (adj.dist >= limit) {
                    visited[adj.v] = true;
                    willVisit.push(adj.v);
                }
            }
        }
    }
    return false;
}

int binarySearch(int start, int end) {
    int up = maxLimit;
    int down = 1;
    while (down <= up) {
        int mid = (up + down)/2;
        if (bfs(start, end, mid))
            down = mid + 1;
        else
            up = mid - 1;
    }
    return up;
}