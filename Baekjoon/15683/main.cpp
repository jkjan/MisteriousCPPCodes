#include <iostream>
#include <vector>
#define MAX_SIZE 8
#define INF MAX_SIZE*MAX_SIZE
using namespace std;

int N, M;
typedef struct delta {
    int y, x;
} delta;
typedef struct cctv {
    int type;
    int y, x;
    int head;
} cctv;
typedef struct node {
    int office[MAX_SIZE][MAX_SIZE]{};
    vector<cctv> cctvs;
} node;

vector<delta> ds[6][4] = {
        {},
        // 1번
        {{{0, 1}},
         {{1, 0}},
         {{0, -1}},
         {{-1, 0}}},
         // 2번
        {{{0, 1}, {0, -1}},
         {{-1, 0}, {1, 0}},
         {{0, 1}, {0, -1}},
         {{-1, 0}, {1, 0}}},
         // 3번
        {{{-1, 0}, {0, 1}},
         {{0, 1}, {1, 0}},
         {{1, 0}, {0, -1}},
         {{0, -1}, {-1, 0}}},
         // 4번
        {{{-1, 0}, {0, 1}, {0, -1}},
         {{-1, 0}, {0, 1}, {1, 0}},
         {{0, 1}, {1, 0}, {0, -1}},
         {{-1, 0}, {1, 0}, {0, -1}}},
        // 5번
         {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}},
          {{-1, 0}, {0, 1}, {1, 0}, {0, -1}},
          {{-1, 0}, {0, 1}, {1, 0}, {0, -1}},
          {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}}
};

vector<string> cases;
void input(node* init);
void dfs(string a, int l);
int getMin(node init);
int cctvCnt;

int main() {
    node init;
    input(&init);
    cctvCnt = init.cctvs.size();
    dfs("", 0);
    cout << getMin(init);
    return 0;
}

void dfs(string a, int l) {
    if (l >= cctvCnt) {
        cases.push_back(a);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        dfs(a + to_string(i), l + 1);
    }
}

void input(node* init) {
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf(" %d", &(init->office[i][j]));
            if (init->office[i][j] != 0 && init->office[i][j] != 6)
                init->cctvs.push_back({init->office[i][j], i, j, 0});
        }
    }
}

delta operator+(delta a, delta b) {
    return {a.y + b.y, a.x + b.x};
}

bool isValid(delta d) {
    return (-1 < d.y && d.y < N && -1 < d.x && d.x < M);
}

void goStraight(int office[][MAX_SIZE], delta origin, delta d) {
    while (isValid(origin)) {
        if (office[origin.y][origin.x] == 6)
            return;
        office[origin.y][origin.x] = 9;
        origin = origin + d;
    }
}

void batch(node* n) {
    for (auto c : n->cctvs) {
        for (auto arrow : ds[c.type][c.head]) {
            goStraight(n->office, {c.y, c.x}, arrow);
            n->office[c.y][c.x] = c.type;
        }
    }
}

int getCnt(int office[][MAX_SIZE]) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (office[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

int getMin(node init) {
    int minCnt = INF;
    for (auto c : cases) {
        node n = init;
        for (int i = 0; i < c.length(); ++i) {
            n.cctvs[i].head = c[i] - '0';
        }
        batch(&n);
        minCnt = min(minCnt, getCnt(n.office));
    }
    return minCnt;
}