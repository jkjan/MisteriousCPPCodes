#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 102
using namespace std;

typedef struct pos {
    int x, y;
}pos;

void tc();

int main() {
    int t;
    scanf(" %d", &t);
    for (int i = 0; i < t; i++) {
        tc();
    }
    return 0;
}

void input(int* n, pos* spots) {
    scanf(" %d", n);
    for (int i = 0; i < *n + 2; i++) {
        scanf(" %d %d", &(spots[i].x), &(spots[i].y));
    }
    *n += 2;
}

int distance(pos a, pos b) {
    return (abs(a.x - b.x) + abs(a.y - b.y));
}

void makeGraph(int n, vector<int>* graph, pos* spots) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int newDist = distance(spots[i], spots[j]);
            if (newDist <= 1000) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}

bool bfs(int n, vector<int>* graph) {
    bool visited[MAX_SIZE] = {false, };
    queue<int> willVisit;

    visited[0] = true;
    willVisit.push(0);

    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();

        if (nowVisit == n)
            return true;

        willVisit.pop();

        for (auto g : graph[nowVisit]) {
            if (!visited[g]) {
                willVisit.push(g);
                visited[g] = true;
            }
        }
    }

    return false;
}

void tc() {
    int n;
    pos spots[MAX_SIZE];
    vector<int> graph[MAX_SIZE];

    input(&n, spots);
    makeGraph(n, graph, spots);

    printf("%s\n", bfs(n-1, graph) ? "happy" : "sad");
}