#include <iostream>
#include <queue>
#include <vector>
#define INF 100 * 100
#define MAX_SIZE 100
using namespace std;

typedef struct node {
    int y, x, dist;
} node;

int N;
int map[MAX_SIZE][MAX_SIZE];
void input();
int getShortestBridge();

int main() {
    input();
    printf("%d", getShortestBridge());
    return 0;
}

void input() {
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d", &(map[i][j]));
        }
    }
}

int bfs(deque<node>* willVisit, bool visited[][MAX_SIZE], int num, bool extend) {
    // 좌표를 움직일 변화량
    node deltas[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<node> outerNodes; // 외곽 노드
    visited[willVisit->front().y][willVisit->front().x] = true;
    // 더이상 방문할 노드가 없을 때까지
    while (!willVisit->empty()) {
        node nowVisit = willVisit->front();
        willVisit->pop_front();
        if (!extend)
            map[nowVisit.y][nowVisit.x] = num;
        bool outer = false;

        // 상하좌우 돌아보며
        for (auto d : deltas) {
            node moved = {nowVisit.y + d.y, nowVisit.x + d.x};
            // 새로 볼 노드가 지도의 범위를 넘어설 경우 넘어가기
            if (!(-1 < moved.y && moved.y < N && -1 < moved.x && moved.x < N))
                continue;
            // 새로 볼 노드가 이미 방문한 노드였다면 넘어가기
            if (visited[moved.y][moved.x])
                continue;
            // 새 노드의 거리는 이전 거리 + 1
            moved.dist = nowVisit.dist + 1;

            // 첫번째 bfs 라면 0이 아닐 때만, 두번째 bfs 라면 같은 섬 덩어리가 아닐 때만
            if ((!extend && map[moved.y][moved.x]) || (extend && map[moved.y][moved.x] != num)) {
                // 다른 섬 발견
                if (extend && (map[moved.y][moved.x] != 0)) {
                    return moved.dist;
                }
                visited[moved.y][moved.x] = true;
                willVisit->push_back(moved);
            }
            // 첫번째 bfs 라면 외곽 노드임을 표시
            else if (!extend && !map[moved.y][moved.x])
                outer = true;
        }

        // 외곽 노드에 추가
        if (outer) {
            outerNodes.push_back(nowVisit);
        }
    }

    // 다음 번에 쓸 큐에 현재 섬의 외곽 노드를 전부 추가
    if (!extend) {
        for (auto & o : outerNodes) {
            o.dist = 0;
            willVisit->push_back(o);
        }
    }

    return INF;
}

int getShortestBridge() {
    int island = 1; // 섬의 시작 번호
    bool visited[MAX_SIZE][MAX_SIZE] = {false, }; // 방문 표시
    int shortest = INF; // 가장 짧은 다리
    vector< deque<node> > outerNodes; // i번 섬의 외곽 노드
    outerNodes.emplace_back(); // outerNodes[i] 는 1부터 시작

    // 섬 라벨링 하기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && map[i][j]) {
                outerNodes.emplace_back();
                outerNodes[island].push_back({i, j});
                bfs(&(outerNodes[island]), visited, island, false);
                island++;
            }
        }
    }

    // 각 섬의 외곽 노드에서부터, 타 섬을 발견할 때까지 확장
    for (int i = 1; i < outerNodes.size(); ++i) {
        bool newVisited[MAX_SIZE][MAX_SIZE] = {false, };
        shortest = min(shortest, bfs(&(outerNodes[i]), newVisited, i, true));
    }

    return shortest - 1;
}