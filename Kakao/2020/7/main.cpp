#include <vector>
#include <queue>
#include <iostream>
#define MAX_N 100
#define VERTICAL 0
#define HORIZONTAL 1
using namespace std;
typedef struct vector<vector<int>> arr2d;
typedef struct node {
    int dist;
    int y, x, dir;
} node;
int N;

bool isWall(int y, int x, arr2d* board) {
    if (-1 < y && y < N && -1 < x && x < N)
        return board->at(y)[x];
    else
        return true;
}

void moveRobot(int y, int x, int headY, int headX, int dist, int dir, queue<node>* willVisit, arr2d* board, bool visited[][MAX_N][MAX_N]) {
    if (!isWall(y, x, board) && !visited[dir][headY][headX]) {
        visited[dir][headY][headX] = true;
        willVisit->push({dist + 1, headY, headX, dir});
    }
}

void rotateRobot(int y1, int x1, int y2, int x2, int headY, int headX, int dist, int toDir, queue<node>* willVisit, arr2d* board, bool visited[][MAX_N][MAX_N]) {
    if (!isWall(y1, x1, board) && !isWall(y2, x2, board) && !visited[toDir][headY][headX]) {
        visited[toDir][headY][headX] = true;
        willVisit->push({dist + 1, headY, headX, toDir});
    }
}

void upDownRobot(int headY, int headX, int y, int x, int dist, int dir, queue<node>* willVisit, arr2d* board, bool visited[][MAX_N][MAX_N]) {
    if (!isWall(headY, headX, board) && !isWall(y, x, board) && !visited[dir][headY][headX]) {
        visited[dir][headY][headX] = true;
        willVisit->push({dist + 1, headY, headX, dir});
    }
}

int bfs(arr2d board) {
    bool visited[2][MAX_N][MAX_N] = {false, };
    queue<node> willVisit;
    willVisit.push({0, 0, 0, HORIZONTAL});
    visited[HORIZONTAL][0][0] = true;
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();

        int y = nowVisit.y;
        int x = nowVisit.x;
        int dir = nowVisit.dir;
        int dist = nowVisit.dist;

        if (dir == VERTICAL) {
            if (y+1 == N-1 && x == N-1)
                return dist;
            moveRobot(y-1, x, y-1, x, dist, dir, &willVisit, &board, visited);
            moveRobot(y+2, x, y+1, x, dist, dir, &willVisit, &board, visited);
            upDownRobot(y, x-1, y+1, x-1, dist, dir, &willVisit, &board, visited);
            upDownRobot(y, x+1, y+1, x+1, dist, dir, &willVisit, &board, visited);
            rotateRobot(y, x+1, y+1, x+1, y+1, x, dist, HORIZONTAL, &willVisit, &board, visited);
            rotateRobot(y, x+1, y+1, x+1, y, x, dist, HORIZONTAL, &willVisit, &board, visited);
            rotateRobot(y, x-1, y+1, x-1, y+1, x-1, dist, HORIZONTAL, &willVisit, &board, visited);
            rotateRobot(y, x-1, y+1, x-1, y, x-1, dist, HORIZONTAL, &willVisit, &board, visited);
        }

        else if (dir == HORIZONTAL) {
            if (y == N-1 && x+1 == N-1)
                return dist;
            moveRobot(y, x-1, y, x-1, dist, dir, &willVisit, &board, visited);
            moveRobot(y, x+2, y, x+1, dist, dir, &willVisit, &board, visited);
            upDownRobot(y-1, x, y-1, x+1, dist, dir, &willVisit, &board, visited);
            upDownRobot(y+1, x, y+1, x+1, dist, dir, &willVisit, &board, visited);
            rotateRobot(y+1, x, y+1, x+1, y, x+1, dist, VERTICAL, &willVisit, &board, visited);
            rotateRobot(y+1, x, y+1, x+1, y, x, dist, VERTICAL, &willVisit, &board, visited);
            rotateRobot(y-1, x, y-1, x+1, y-1, x+1, dist, VERTICAL, &willVisit, &board, visited);
            rotateRobot(y-1, x, y-1, x+1, y-1, x, dist, VERTICAL, &willVisit, &board, visited);
        }
    }
    return -1;
}

int solution(vector<vector<int>> board) {
    N = board.size();
    return bfs(board);
}

int main() {
    arr2d board = {{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}};
    cout << solution(board);
    return 0;
}
