#include <iostream>

#define MAX_SIZE 100
typedef struct delta {
    int y, x;
} delta;

int N, L;
int map[MAX_SIZE][MAX_SIZE];

void input();
bool roller(int i, int j, delta d);

int main() {
    input();
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        cnt += roller(i, 0, {0, 1});
    for (int i = 0; i < N; ++i)
        cnt += roller(0, i, {1, 0});
    printf("%d", cnt);
    return 0;
}

void input() {
    scanf(" %d %d", &N, &L);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d", map[i] + j);
        }
    }
}

bool roller(int i, int j, delta d) {
    int height = map[i][j]; // 현재 높이
    int slopeCnt; // 현재 남은 경사로 길이
    bool slopping = false; // 현재 경사로를 놓는 구간인지 확인
    int canBeSlope = 0; // 이전까지 부분 중 경사로가 될 수 있는 곳의 수
    for (int k = 0; k < N; ++k) {
        if (slopping && map[i][j] != height) // 경사로를 놓는 부분인데 이전 높이와 다르다면, 경사로가 겹치게 되므로 실패
            return false;
        else {
            if (height == map[i][j]) { // 경사로 혹은 평지인 부분
                if (slopping) { // 경사로 부분일 경우
                    slopeCnt--; // 경사로 길이 하나 줄임
                    if (slopeCnt == 0) // 경사로가 다 끝났을 경우
                        slopping = false; // 이제 경사로 구간이 끝났음을 표시
                }
                else // 평지이므로, 경사로가 될 수 있음
                    canBeSlope++;
            }
            else if (height - 1 == map[i][j]) { // 내리막길 발견
                height--; // 경사로를 놓아서 높이가 줄어드는 효과
                canBeSlope = 0; // 이전에 봐왔던 곳들은 경사로가 될 수 없음
                if (L > 1) {  // 경사로 길이가 2 이상이면 추후에도 경사로를 놓을 수 있게 함
                    slopeCnt = L - 1;
                    slopping = true; // 이 다음부터는 경사로 구간임을 표시
                }
            }
            else if (map[i][j] - 1 == height) { // 오르막길 발견
                if (canBeSlope < L) // 뒤에 경사로를 놓을 공간이 부족함
                    return false;
                height++; // 경사로를 놓아서 높이가 늘어나는 효과
                canBeSlope = 1; // 이 부분 역시 경사로가 또 놓일 수 있음
            }
            else // 위의 어떤 경우에도 해당하지 않는다면 높이 차 때문에 경사로를 못 놓는 경우임
                return false;
        }
        i += d.y; j += d.x; // i, j 를 이동
    }
    return !slopping; // 놓을 경사로 길이가 남아있으면 안 됨
}