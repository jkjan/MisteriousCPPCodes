#include <iostream>
#include <queue>

#define MAX_SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define EMPTY '.'
#define HOLE 'O'

typedef struct marvel {
    char color; // 구슬 색
    int y, x; // 구슬 위치
} marvel;

typedef struct node {
    int dist; // 시작 노드로부터의 최소 횟수
    int former; // 직전에 시도한 방향
    marvel blue, red; // 빨간, 파란 구슬
    char board[MAX_SIZE][MAX_SIZE]; // 현 상태의 보드
} node;

void input(node *init);
int bfs(node init);

int main() {
    node init; // 시작 노드

    // 시작 노드의 최소 횟수는 0, 이전 시도는 -1
    init.dist = 0;
    init.former = -1;

    input(&init); // 입력 받아서 시작 노드 상태 저장하기
    printf("%d ", bfs(init)); // 최소 횟수 출력
    return 0;
}

void input(node *init) {
    int N, M; // 세로, 가로 크기
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf(" %c", &(init->board[i][j]));
            // 시작 노드의 구슬 정보 기록하기
            if (init->board[i][j] == 'R')
                init->red = {'R', i, j};
            else if (init->board[i][j] == 'B')
                init->blue = {'B', i, j};
        }
    }
}

void move(char board[][MAX_SIZE], marvel *m, int *moving, int delta, char fill) {
    // 현 위치를 구슬 혹은 빈칸으로 채우기
    board[m->y][m->x] = fill;
    *moving -= delta;

    // 구슬이 있던 부분을 다시 빈 공간으로 바꾸기
    board[m->y][m->x] = EMPTY;
    *moving += delta;
}

void move(node *newNode, marvel *m, int *moving, int delta, bool *moved, bool *holeIn) {
    // 구멍에 들어간 상태가 아니라면 구슬 옮기기
    if (!(*holeIn))
        *moving += delta;

    *moved = false; // 현 차례에 움직였는지 확인 위함

    switch (newNode->board[m->y][m->x]) {
        case EMPTY: {
            // 현 위치가 빈 공간일 경우 구슬 위치 픽스하고 움직였다고 표시
            move(newNode->board, m, moving, delta, m->color);
            *moved = true;
            break;
        }
        case HOLE: {
            // 빠져나간다면 구슬을 지우고 구슬이 빠져나감을 표시
            move(newNode->board, m, moving, delta, HOLE);
            *holeIn = true;
            break;
        }
        default:
            // 움직이지 못한다면 구슬 위치 다시 되돌리기
            *moving -= delta;
    }
}

int move(node *newNode, int to) {
    // 구슬들의 원래 y, x
    int originalRY = newNode->red.y;
    int originalRX = newNode->red.x;
    int originalBY = newNode->blue.y;
    int originalBX = newNode->blue.x;

    // 변화량 => 위, 왼쪽은 -1, 아래, 오른쪽은 1
    int delta = to % 2 ? 1 : -1;

    // 빨간, 파란 구슬이 움직였는지 여부
    bool movedR = true;
    bool movedB = true;

    // 빨간, 파란 구슬이 빠져나갔는지 여부
    bool holeInR = false;
    bool holeInB = false;

    // 위, 아래라면 y값이 변화, 왼쪽, 오른쪽이라면 x값이 변화
    int *movingR, *movingB;
    if (to < 2) {
        movingR = &(newNode->red.y);
        movingB = &(newNode->blue.y);
    } else {
        movingR = &(newNode->red.x);
        movingB = &(newNode->blue.x);
    }

    // 두 구슬 모두 더 이상 움직이지 않거나, 파란 구슬이 빠져나갔을 때까지
    // 두 구슬을 계속해서 움직임
    do {
        move(newNode, &(newNode->red), movingR, delta, &movedR, &holeInR);
        move(newNode, &(newNode->blue), movingB, delta, &movedB, &holeInB);
    } while ((movedR || movedB) && !holeInB);

    // 두 구슬이 전혀 움직이지 않았다면
    if (newNode->red.y == originalRY && newNode->red.x == originalRX &&
        newNode->blue.y == originalBY && newNode->blue.x == originalBX) {
        return -2;
    }
    // 파란 구슬이 빠져나갔다면 실패
    else if (holeInB) {
        return -1;
    }
    // 빨간 구슬만 빠져나갔다면 성공
    else if (holeInR) {
        return 1;
    }
    // 두 구슬이 움직였고, 아직 판 위에 있으면 또 움직여보기
    else
        return 0;
}

int bfs(node init) {
    // 구슬 위치 중복 확인
    bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE] = {false,};

    std::queue<node> willVisit; // 앞으로 방문할 노드들의 큐
    int direction[] = {UP, DOWN, LEFT, RIGHT}; // 방향들
    willVisit.push(init); // 시작 노드를 방문 예약

    // 더이상 방문할 노드가 없을 때까지
    while (!willVisit.empty()) {
        // 큐에서 지금 방문할 노드를 뽑고 방문 표시하기
        node nowVisit = willVisit.front();
        visited[nowVisit.red.y][nowVisit.red.x][nowVisit.blue.y][nowVisit.blue.x] = true;
        willVisit.pop();

        // 위 아래 왼쪽 오른쪽 네 방향을 시도하면서
        for (auto dir : direction) {
            // 지금 시도할 방향이 바로 직전에 시도한 방향이라면 통과
            if (dir == nowVisit.former)
                continue;

            auto newNode = nowVisit;
            newNode.dist = nowVisit.dist + 1;

            // 최소 횟수가 10을 넘었다면 -1 을 리턴
            if (newNode.dist > 10)
                return -1;

            int ret = move(&newNode, dir);
            if (ret != -2) {
                if (!visited[newNode.red.y][newNode.red.x][newNode.blue.y][newNode.blue.x]) {
                    // 현재 상태에서 시도할 가치가 있다면 큐에 현재 상태를 추가
                    if (ret == 0) {
                        newNode.former = dir;
                        willVisit.push(newNode);
                    }
                    // 빨간 구슬만 성공적으로 들어갔다면 현재까지의 최소 횟수 리턴
                    else if (ret == 1)
                        return newNode.dist;
                }
            }
        }
    }
    return -1;
}