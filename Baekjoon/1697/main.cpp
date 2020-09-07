#include <iostream>
#include <queue>
#include <set>
#define MAX 100000

using namespace std;

set<int> position[MAX + 1];

void makeGraph(int N);
int bfs(int N, int M);

int main() {
    int N, M;
    cin >> N >> M;
    if (N == M) {
        cout << 0;
        return 0;
    }
    makeGraph(0);
    cout << bfs(N, M);
    return 0;
}

void makeGraph(int N) {
    if (N != 0 && N * 2 <= MAX) {
        int possiblePosition = N * 2;
        if (position[N].count(possiblePosition) == 0) {
            position[N].insert(possiblePosition);
            makeGraph(possiblePosition);
        }
    }

    if (0 <= N - 1) {
        int possiblePosition = N - 1;
        if (position[N].count(possiblePosition) == 0) {
            position[N].insert(possiblePosition);
            makeGraph(possiblePosition);
        }
    }

    if (N + 1 <= MAX) {
        int possiblePosition = N + 1;
        if (position[N].count(possiblePosition) == 0) {
            position[N].insert(possiblePosition);
            makeGraph(possiblePosition);
        }
    }
}

int bfs(int N, int M) {
    bool visited[MAX+1] = {false, };
    int dist[MAX+1];
    queue<int> willVisit;
    int nowVisit;
    dist[N] = 0;
    visited[N] = true;
    willVisit.push(N);

    while (!willVisit.empty()) {
        nowVisit = willVisit.front();
        willVisit.pop();
        for (auto itor = position[nowVisit].begin(); itor != position[nowVisit].end(); itor++) {
            if (!visited[*itor]) {
                visited[*itor] = true;
                willVisit.push(*itor);
                dist[*itor] = dist[nowVisit] + 1;
                if (*itor == M)
                    return dist[*itor];
            }
        }
    }

    return MAX + 1;
}