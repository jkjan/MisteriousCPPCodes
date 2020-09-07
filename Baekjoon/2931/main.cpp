#include <iostream>
#include <queue>
#include <map>
#include <bitset>
#define MAX_SIZE 25 * 25 + 1

using namespace std;

typedef struct node {
    int y, x;
} node;
int R, C;
node moscow;
char europe[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
map<char, vector<node>> connection;

void input();
node whereWasIt();
char whatWasIt(node where);

int main() {
    // 모스크바, 자그레브, 그리고 블록들이 갈 수 있는 방향들
    connection['M'] = connection['Z'] = connection['+'] =
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    connection['|'] =
            {{-1, 0}, {1, 0}};
    connection['-'] =
            {{0, -1}, {0, 1}};
    connection['1'] =
            {{1, 0}, {0, 1}};
    connection['2'] =
            {{-1, 0}, {0, 1}};
    connection['3'] =
            {{-1, 0}, {0, -1}};
    connection['4'] =
            {{1, 0}, {0, -1}};
    connection['.'] = {};

    input();
    node where = whereWasIt();   // 블록이 없는 위치
    char what = whatWasIt(where); // 그 위치에 있어야 할 블록
    cout << where.y << " " << where.x << " " << what << endl;
    return 0;
}

void input() {
    scanf(" %d %d", &R, &C);
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            scanf(" %c", &(europe[i][j]));
            if (europe[i][j] != '.') {
                // 탐색 시 출발할 위치인 모스크바의 위치를 저장
                if (europe[i][j] == 'M')
                    moscow = {i, j};
            }
        }
    }
}

node operator+(node a, node b) {
    return {a.y + b.y, a.x + b.x};
}

bool isValid(node a) {
    return (1 <= a.y && a.y <= R) && (1 <= a.x && a.x <= C);
}

node whereWasIt() {
    queue<node> willVisit;
    willVisit.push(moscow);
    visited[moscow.y][moscow.x] = true;
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();
        // 현재 방문하고 있는 위치인 nowVisit 의 유형따라 연결된 곳을 훑으며
        for (auto delta : connection[europe[nowVisit.y][nowVisit.x]]) {
            node moved = nowVisit + delta;
            // 유효한 좌표가 아니거나, 이미 방문한 곳인 경우 패스
            if (!isValid(moved))
                continue;
            if (visited[moved.y][moved.x])
                continue;
            // 모스크바와 자그레브가 아닌 블록인데 빈 칸과 연결돼있으면 이는 해커가 지운 곳
            if (europe[nowVisit.y][nowVisit.x] != 'M' &&
                europe[nowVisit.y][nowVisit.x] != 'Z' &&
                europe[moved.y][moved.x] == '.') {
                    return {moved.y, moved.x};
            }
            // 빈 칸이 아니라면 다음 번 방문할 곳의 큐에 넣음
            else if (europe[moved.y][moved.x] != '.') {
                visited[moved.y][moved.x] = true;
                willVisit.push(moved);
            }
        }
    }
    return {-1, -1};
}

bool isIn(vector<node> con, node dir) {
    for (auto c : con) {
        if (c.y == dir.y && c.x == dir.x)
            return true;
    }
    return false;
}

char whatWasIt(node where) {
    int bits = 0;
    int i = 1;
    // 파이프가 지워진 것으로 판단되는 곳의 사방을 살피며
    for (auto delta : connection['+']) {
        node moved = where + delta;
        bool looking = false;
        if (isValid(moved)) {
            if (europe[moved.y][moved.x] != 'M' && europe[moved.y][moved.x] != 'Z')
                // 위 아래 왼쪽 오른쪽을 살피며 그 위의 공간이 자신을 보고 있는지를 살핌
                // -delta => (내가 그쪽을 보는 방향의 역)
                // 단, 문제 조건 중, 모스크바와 자그레브는 항상 블록과 연결돼있으므로
                // 둘을 볼 필요가 없음
                // M과 Z가 파이프로 직접 연결되면 불필요한 블록이 생겨버리기 때문
                /* 3 7
                   .14....
                   .M.Z...
                   ..23...
                   answer : 2 3 |    -> 둘을 연결하면 + 블록으로 판단하게 됨
                 * */
                looking = isIn(connection[europe[moved.y][moved.x]], {-delta.y, -delta.x});
        }
        // 비트마스크로 빠진 블록이 보고 있어야 할 방향 마크
        bits = bits | (looking << (4 - i));
        i++;
    }

    // 위 아래 왼쪽 오른쪽 +
    if (bits == 0b1111)
        return '+';
    // 위 아래
    else if (bits == 0b1100)
        return '|';
    // 왼쪽 오른쪽
    else if (bits == 0b0011)
        return '-';
    // 아래 오른쪽 「
    else if (bits == 0b0101)
        return '1';
    // 위 오른쪽 ㄴ
    else if (bits == 0b1001)
        return '2';
    // 위 왼쪽 」
    else if (bits == 0b1010)
        return '3';
    // 아래 왼쪽 ㄱ
    else
        return '4';
}