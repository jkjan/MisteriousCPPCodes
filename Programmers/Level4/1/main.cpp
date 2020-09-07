#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define MAX_SIZE 16777216

using namespace std;

typedef struct node {
    stack<bool> bracket;
    int size;
} node;

int bfs(int n) {
    queue<node> willVisit;
    willVisit.push({stack<bool>(), 0});
    int cnt = 0;
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();

        if (nowVisit.size == n*2) {
            if (nowVisit.bracket.empty())
                cnt++;
            continue;
        }

        if (nowVisit.bracket.empty()) {
            nowVisit.bracket.push(true);
            nowVisit.size++;
            willVisit.push(nowVisit);
        }
        else {
            node adj = nowVisit;
            adj.bracket.pop();
            adj.size++;
            willVisit.push(adj);

            nowVisit.bracket.push(true);
            nowVisit.size++;
            willVisit.push(nowVisit);
        }
    }
    return cnt;
}

int solution(int n) {
    int answer = bfs(n);
    return answer;
}

int main() {
    for (int i = 1; i <= 14; ++i) {
        cout << solution(i) << endl;
    }
    return 0;
}
