#include <iostream>
#include <vector>

#define SIZE 100
#define NODE_SIZE SIZE * SIZE * SIZE
#define NONE -1
#define NOT_RIPEN 0
#define RIPEN 1

using namespace std;

int M, N, H;  // 가로, 세로, 높이
bool visited[NODE_SIZE + 1] = {false, };

void input(vector<int>* tomatoBox, vector<int>* ripenTomatoes, int* tomatoes, int* notRipenTomato);
void ripe(vector<int>* tomatoBox, vector<int>* ripenTomatoes, int* tomatoes, int* notRipenTomato);

int main() {
    vector<int> tomatoBox[NODE_SIZE + 1]; // 전체 토마토 상자
    vector<int> ripenTomatoes;  // 익은 토마토들의 번호
    int tomatoes[NODE_SIZE + 1];  // 토마토의 상태
    int notRipenTomato = 0;
    int days = 0;

    input(tomatoBox, &ripenTomatoes, tomatoes, &notRipenTomato);

    if (notRipenTomato == 0) {
        cout << 0;
        return 0;
    }

    while (!ripenTomatoes.empty()) {
//        cout << "Day " << days << endl;
//        for (int i = 1; i <= M * N * H; i++) {
//            cout << tomatoes[i] << " ";
//            if (i % M == 0) {
//                cout << endl;
//            }
//        }
//        cout << endl;

        ripe(tomatoBox, &ripenTomatoes, tomatoes, &notRipenTomato);
        days++;

        if (notRipenTomato == 0) {
            cout << days;
            return 0;
        }
    }

    cout << -1;

    return 0;
}

int indexToNode(int i, int j, int k) {
    return (i-1) * N * M + (j-1) * M + k;
}

void input(vector<int>* tomatoBox, vector<int>* ripenTomatoes, int* tomatoes, int* notRipenTomato) {
    cin >> M >> N >> H;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                int node = indexToNode(i, j, k);
                cin >> tomatoes[node];

                if (tomatoes[node] == RIPEN) {
                    ripenTomatoes->push_back(node);
                }

                if (tomatoes[node] == NOT_RIPEN) {
                    (*notRipenTomato)++;
                }

                if (tomatoes[node] == NONE) {
                    continue;
                }

                if (1 < i) {
                    int adjacent = indexToNode(i - 1, j, k);
                    if (tomatoes[adjacent] != NONE) {
                        tomatoBox[node].push_back(adjacent);
                        tomatoBox[adjacent].push_back(node);
                    }
                }

                if (1 < j) {
                    int adjacent = indexToNode(i, j - 1, k);
                    if (tomatoes[adjacent] != NONE) {
                        tomatoBox[node].push_back(adjacent);
                        tomatoBox[adjacent].push_back(node);
                    }
                }

                if (1 < k) {
                    int adjacent = indexToNode(i, j, k - 1);
                    if (tomatoes[adjacent] != NONE) {
                        tomatoBox[node].push_back(adjacent);
                        tomatoBox[adjacent].push_back(node);
                    }
                }
            }
        }
    }
}

void ripe(vector<int>* tomatoBox, vector<int>* ripenTomatoes, int* tomatoes, int* notRipenTomato) {
    vector<int> newlyRipedTomatoes;

    for (int & tomato : *ripenTomatoes) {
        for (int & adjacent : tomatoBox[tomato]) {
            if (!visited[adjacent] && tomatoes[adjacent] == NOT_RIPEN) {
                visited[adjacent] = true;
                tomatoes[adjacent] = RIPEN;
                (*notRipenTomato)--;
                newlyRipedTomatoes.push_back(adjacent);
            }
        }
    }
    ripenTomatoes->resize(newlyRipedTomatoes.size());
    copy(newlyRipedTomatoes.begin(), newlyRipedTomatoes.end(), ripenTomatoes->begin());
}