#include <iostream>
#include <vector>

#define MAX_SIZE 50*50
#define ROCK 'X'
#define BEAVER 'D'
#define HEDGEHOG 'S'
#define WATER '*'

using namespace std;

int R, C;
vector<int> mapGraph[MAX_SIZE+1];
vector<int> water;
vector<int> hedgehog;
char map[MAX_SIZE+1];
bool visited[MAX_SIZE+1] = {false, };

void input();
bool spread(char who, vector<int>* object);

int main() {
    int time = 0;

    input();

    while (!hedgehog.empty()) {
        spread(WATER, &water);
        bool isSafe = spread(HEDGEHOG, &hedgehog);
        time++;

        if (isSafe) {
            cout << time;
            return 0;
        }
    }

    cout << "KAKTUS";

    return 0;
}

bool spread(char who, vector<int>* object) {
    vector<int> newlySpread;
    for (int & field : *object) {
        for (int & nowVisit : mapGraph[field]) {
            if (who == WATER) {
                if (map[nowVisit] != BEAVER && map[nowVisit] != WATER) {
                    map[nowVisit] = WATER;
                    newlySpread.push_back(nowVisit);
                    visited[nowVisit] = true;
                }
            }

            if (!visited[nowVisit] && who == HEDGEHOG) {
                visited[nowVisit] = true;
                if (map[nowVisit] == BEAVER)
                    return true;
                if (map[nowVisit] != WATER)
                    newlySpread.push_back(nowVisit);
            }
        }
    }

    object->resize(newlySpread.size());
    copy(newlySpread.begin(), newlySpread.end(), object->begin());
    return false;
}

void connect(int a, int b) {
    mapGraph[a].push_back(b);
    mapGraph[b].push_back(a);
}

void input() {
    cin >> R >> C;
    getchar();
    char info;
    int nodeNum = 1;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf("%c", &info);
            map[nodeNum] = info;
            if (info != ROCK) {
                if (i > 1) {
                    if (map[nodeNum - C] != ROCK) {
                        connect(nodeNum, nodeNum-C);
                    }
                }
                if (j > 1) {
                    if (map[nodeNum - 1] != ROCK) {
                        connect(nodeNum, nodeNum-1);
                    }
                }

                if (info == WATER) {
                    visited[nodeNum] = true;
                    water.push_back(nodeNum);
                }
                else if (info == HEDGEHOG) {
                    visited[nodeNum] = true;
                    hedgehog.push_back(nodeNum);
                }
            }
            nodeNum++;
        }
        getchar();
    }
}