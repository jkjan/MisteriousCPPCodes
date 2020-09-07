#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#define MAX_SIZE 100001 * 2
using namespace std;
void bfs(int N, int K);

int main() {
    int N, K;
    scanf(" %d %d", &N, &K);
    bfs(N, K);
    return 0;
}

void bfs(int N, int K) {
    queue<pair<int, int>> willVisit;
    bool visited[MAX_SIZE] = {false, };
    willVisit.push({N, 0});
    int min = MAX_SIZE;
    while (!willVisit.empty()) {
        int nowVisit = willVisit.front().first;
        int depth = willVisit.front().second;
        willVisit.pop();
        visited[nowVisit] = true;

        if (nowVisit == K)
            min = std::min(min, depth);

        if (nowVisit < K && !visited[nowVisit+1])
            willVisit.push({nowVisit+1, depth+1});
        if (0 < nowVisit && !visited[nowVisit-1])
            willVisit.push({nowVisit-1, depth+1});
        if (nowVisit <= 2*K/3 && !visited[nowVisit*2])
            willVisit.push({nowVisit*2, depth});
    }
    printf("%d", min);
}