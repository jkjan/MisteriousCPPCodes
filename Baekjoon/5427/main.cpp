#include <iostream>
#include <vector>

using namespace std;

#define EMPTY '.'
#define WALL '#'
#define SANGEUN '@'
#define FIRE '*'
#define MAX_SIZE 1002*1002
#define EXIT 'X'

int escapeSangeun();
void input(int *w, int *h, vector<int> *sangeun, char *map, vector<int> *mapGraph, vector<int> *fire);
bool spread(bool* visited, int who, char* map, vector<int>* mapGraph, vector<int>* object);

int main() {
    int t;      // 테스트 케이스
    cin >> t;
    for (int i = 0; i < t; i++) {
        int answer;

        if ((answer = escapeSangeun()) == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << answer << endl;
    }
    return 0;
}

int escapeSangeun() {
    int w, h;    // 너비, 높이
    char map[MAX_SIZE + 1];
    bool visited[MAX_SIZE + 1] = {false, };
    vector<int> mapGraph[MAX_SIZE + 1];    // 전체 맵 그래프
    vector<int> fire;       // 불
    vector<int> sangeun;    // 상근
    int time = 0;
    input(&w, &h, &sangeun, map, mapGraph, &fire);

    while (!sangeun.empty()) {
        spread(visited, FIRE, map, mapGraph, &fire);
        time++;

        bool isEscaped = spread(visited, SANGEUN, map, mapGraph, &sangeun);

        if (isEscaped)
            return time;
    }

    return -1;
}

bool spread(bool* visited, int who, char* map, vector<int>* mapGraph, vector<int>* object) {
    vector<int> newlySpread;

    for (auto itor = object->begin(); itor != object->end(); itor++) {
        visited[*itor] = true;
        for (auto gItor = mapGraph[*itor].begin(); gItor != mapGraph[*itor].end(); gItor++) {
            if (!visited[*gItor]) {
                visited[*gItor] = true;

                if (who == SANGEUN) {
                    if (map[*gItor] == EXIT) {
                        return true;
                    }
                    if (map[*gItor] != FIRE) {
                        newlySpread.push_back(*gItor);
                    }
                }

                else {
                    map[*gItor] = FIRE;
                    newlySpread.push_back(*gItor);
                }
            }
        }
    }
    object->resize(newlySpread.size());
    copy(newlySpread.begin(), newlySpread.end(), object->begin());

    return false;
}

void input(int *w, int *h, vector<int> *sangeun, char *map, vector<int> *mapGraph, vector<int> *fire) {
    char info;
    cin >> *w >> *h;
    getchar();
    int nodeNum = *w + 4;
    int level = *w + 2;

    for (int i = 1; i <= *h; i++) {
        for (int j = 1; j <= *w; j++) {
            scanf("%c", &info);
            map[nodeNum] = info;

            if (info != WALL) {
                if (map[nodeNum - level] != WALL) {
                    mapGraph[nodeNum].push_back(nodeNum - level);
                    if (i > 1) {    // 노드가 맵 내부면 반대쪽 노드에서도 추가
                        mapGraph[nodeNum - level].push_back(nodeNum);
                    }
                }

                if (map[nodeNum - 1] != WALL) {
                    mapGraph[nodeNum].push_back(nodeNum - 1);
                    if (j > 1) {
                        mapGraph[nodeNum - 1].push_back(nodeNum);
                    }
                }

                if (i == 1) {   // 외부면 추가 않고 출구 표시
                    map[nodeNum - level] = EXIT;
                }

                if (j == 1) {
                    map[nodeNum - 1] = EXIT;
                }

                if (i == *h) {
                    mapGraph[nodeNum].push_back(nodeNum + level);
                    map[nodeNum + level] = EXIT;
                }
                if (j == *w) {
                    mapGraph[nodeNum].push_back(nodeNum + 1);
                    map[nodeNum + 1] = EXIT;
                }

                if (info == SANGEUN)
                    sangeun->push_back(nodeNum);
                else if (info == FIRE)
                    fire->push_back(nodeNum);
            }
            nodeNum++;
            if (j == *w)
                nodeNum+=2;
        }
        getchar();
    }
}