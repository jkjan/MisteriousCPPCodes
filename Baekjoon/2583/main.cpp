#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
bool visited[10001] = {false,};
vector<int> graph[10001];

void makeGraph();
int bfs(int start);
void drawSquare(int x1, int y1, int x2, int y2);

int main() {
    int x1, y1, x2, y2;
    int area;
    vector<int> areaCnt;
    cin >> M >> N >> K;
    makeGraph();

    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        drawSquare(x1, y1, x2, y2);
    }

    for (int i = 1; i <= M*N; i++) {
        if (!visited[i]) {
            area = bfs(i);
            areaCnt.push_back(area);
        }
    }

    sort(areaCnt.begin(), areaCnt.end());

    cout << areaCnt.size() << endl;

    for (int & itor : areaCnt) {
        cout << itor << " ";
    }

    return 0;
}

void connect(int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

int indexToNum(int i, int j) {
   return (i-1)*N + j;
}

void makeGraph() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (i > 1) {
                connect(indexToNum(i, j), indexToNum(i-1, j));
            }

            if (j > 1) {
                connect(indexToNum(i, j), indexToNum(i, j-1));
            }
        }
    }
}

void drawSquare(int x1, int y1, int x2, int y2) {
    int start = (M-y2)*N + x1 + 1;
    int h = y2 - y1;
    int w = x2 - x1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            visited[start + j] = true;
        }
        start += N;
    }
}

int bfs(int start) {
    queue<int> willVisit;
    int nowVisit;
    willVisit.push(start);
    visited[start] = true;
    int visitCnt = 1;
    while(!willVisit.empty()) {
        nowVisit = willVisit.front();
        willVisit.pop();
        for (int & itor : graph[nowVisit]) {
            if (!visited[itor]) {
                willVisit.push(itor);
                visited[itor] = true;
                visitCnt++;
            }
        }
    }

    return visitCnt;
}