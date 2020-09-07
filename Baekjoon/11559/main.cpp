#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 12 * 6
using namespace std;

vector<int> graph[MAX_SIZE];
char board[MAX_SIZE];

void input();
int chain();

int main() {
    input();
    printf("%d", chain());
    return 0;
}

int indexToNode(int i, int j) {
    return i*6 + j;
}

void connect(int i, int j, bool isI) {
    int criterion = isI ? i : j;
    if (criterion > 0) {
        int thatNode = indexToNode(i - isI, j - !isI);
        if (board[thatNode] != '.') {
            int thisNode = indexToNode(i, j);
            graph[thisNode].push_back(thatNode);
            graph[thatNode].push_back(thisNode);
        }
    }
    if (isI) {
        connect(i, j, false);
    }
}

void input() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            int thisNode = indexToNode(i, j);
            scanf(" %c", board + thisNode);
            if (board[thisNode] != '.') {
                connect(i, j, true);
            }
        }
        getchar();
    }
}

vector<int> bfs(int start, bool *visited) {
    char color = board[start];
    vector<int> cand;
    queue<int> willVisit;
    visited[start] = true;
    willVisit.push(start);
    cand.push_back(start);

    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto g : graph[nowVisit]) {
            if (!visited[g] && board[g] == color) {
                visited[g] = true;
                willVisit.push(g);
                cand.push_back(g);
            }
        }
    }
    return cand;
}

bool explode() {
    bool visited[MAX_SIZE] = {false,};
    bool exploded = false;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (board[i] != '.') {
            vector<int> cand = bfs(i, visited);
            if (cand.size() >= 4) {
                for (auto c : cand) {
                    board[c] = '.';
                }
                exploded = true;
            }
        }
    }

    for (int i = MAX_SIZE; i >= 0; i--) {
        if (board[i] != '.' && i / 6 != 11) {
            char color = board[i];
            board[i] = '.';
            int k = i + 6;
            while (board[k] == '.') {
                k += 6;
            }
            board[k - 6] = color;
        }
    }

    return exploded;
}

int chain() {
    int cnt = 0;
    while (explode()) {
        cnt++;
    }
    return cnt;
}