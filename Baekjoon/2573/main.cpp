#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 300 * 300

using namespace std;

typedef struct iceberg {
    int pos, height;
} iceberg;

int N, M;
int field[MAX_SIZE];
vector<iceberg> northPole;
vector<int> graph[MAX_SIZE];

void input();
int getYears();

int main() {
    input();
//    for (auto n : northPole) {
//        printf("%d -> %d\n", n.pos, n.height);
//    }
    printf("%d", getYears());
    return 0;
}

int indexToNum(int i, int j) {
    return i*M + j;
}

void connect(int i, int j, bool isI) {
    int criterion = isI ? i : j;
    if (criterion > 0) {
        int thisNode = indexToNum(i, j);
        int thatNode = indexToNum(i-isI, j-!isI);
        graph[thisNode].push_back(thatNode);
        graph[thatNode].push_back(thisNode);
    }
    if (isI){
        connect(i, j, false);
        return;
    }
}

void input() {
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int thisNode = indexToNum(i, j);
            scanf(" %d", field + thisNode);
            connect(i, j, true);
            if (field[thisNode] != 0) {
                northPole.push_back({thisNode, field[thisNode]});
            }
        }
    }
}

int count(int n) {
    int c = 0;
    c += field[n-1] == 0;
    c += field[n+1] == 0;
    c += field[n-M] == 0;
    c += field[n+M] == 0;
    return c;
}

bool melt() {
    vector<int> changed;
    int none = 0;
    for (auto & i : northPole) {
        if (i.height == 0)
            none++;
        int melted = count(i.pos);
        i.height = (i.height <= melted ? 0 : i.height - melted);
        changed.push_back(i.height);
    }
    for (int i = 0; i < changed.size(); i++) {
        field[northPole[i].pos] = changed[i];
    }
    return none == northPole.size();
}

void bfs(int start, bool *visited) {
    queue<int> willVisit;
    visited[start] = true;
    willVisit.push(start);

    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto g : graph[nowVisit]) {
            if (!visited[g] && field[g] != 0) {
                willVisit.push(g);
                visited[g] = true;
            }
        }
    }
}

bool isDivided() {
    bool visited[MAX_SIZE] = {false, };
    int divided = 0;
    for (auto n : northPole) {
        if (n.height == 0) continue;
        if (!visited[n.pos]) {
            bfs(n.pos, visited);
            divided++;
        }
    }
    return divided >= 2;
}

int getYears() {
    int years = 0;
    bool allMelted = northPole.empty();
    while (!(isDivided() || allMelted)) {
        allMelted = melt();
        years++;
    }
    return allMelted ? 0 : years;
}