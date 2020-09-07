#include <iostream>
#include <vector>

#define SIZE 1000
#define NODE_SIZE SIZE * SIZE
#define NONE -1
#define NOT_RIPEN 0
#define RIPEN 1

using namespace std;

int M, N;  // 가로, 세로
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

int indexToNode(int i, int j) {
    return (i-1) * M + j;
}

void input(vector<int>* tomatoBox, vector<int>* ripenTomatoes, int* tomatoes, int* notRipenTomato) {
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int node = indexToNode(i, j);
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

            if (2 <= i) {
                int adjacent = indexToNode(i - 1, j);
                tomatoBox[node].push_back(adjacent);
                tomatoBox[adjacent].push_back(node);
            }

            if (j < M) {
                int adjacent = indexToNode(i, j + 1);
                tomatoBox[node].push_back(adjacent);
                tomatoBox[adjacent].push_back(node);
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