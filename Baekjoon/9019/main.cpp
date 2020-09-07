#include <iostream>
#include <string>
#include <queue>
using namespace std;

void tc();
long input();

int main() {
    int T = (int)input();
    for (int i = 0; i < T; ++i)
        tc();
    return 0;
}

int D(int n) {
    return 2*n % 10000;
}

int S(int n) {
    return (n + 9999) % 10000;
}

int L(int n) {
    return (n * 10 + (n / 1000)) % 10000;
}

int R(int n) {
    return n / 10 + (n % 10) * 1000;
}

typedef struct node {
    int n;
    string cmdArr;
} node;

typedef struct op {
    int(*func)(int);
    char cmd;
} op;

string bfs(int A, int B) {
    bool visited[10000] = {false, };
    queue<node> willVisit;
    willVisit.push({A, ""});
    op ops[4] = {{D, 'D'}, {S, 'S'}, {L, 'L'}, {R, 'R'}};
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();
        for (auto o : ops) {
            if (nowVisit.n == 0 && o.cmd != 'S')
                continue;
            string newCmdArr = nowVisit.cmdArr + o.cmd;
            int newN = o.func(nowVisit.n);
            if (newN == B)
                return newCmdArr;
            if (!visited[newN]) {
                visited[newN] = true;
                willVisit.push({newN, newCmdArr});
            }
        }
    }
    return "";
}

long input() {
    char* ptr;
    char str[256];
    scanf(" %s", str);
    return strtol(str, &ptr, 10);
}

void tc() {
    int A = (int)input();
    int B = (int)input();
    cout << bfs(A, B) << endl;
}
