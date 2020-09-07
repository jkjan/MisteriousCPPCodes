#include <iostream>
#define MAX_SIZE 500
#define REMOVE 2
#define PUT 1
#define INF 500 * 500 * 257 * REMOVE

int N, M;
int minHeight, maxHeight;
int field[MAX_SIZE][MAX_SIZE];

int input();
std::pair<int, int> getMaxTime(int B);

int main() {
    int B = input();
    std::pair<int, int> output = getMaxTime(B);
    printf("%d %d", output.first, output.second);
    return 0;
}

int input() {
    int B;
    maxHeight = -1;
    minHeight = 257;
    scanf(" %d %d %d", &N, &M, &B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %d", &(field[i][j]));
            minHeight = std::min(minHeight, field[i][j]);
            maxHeight = std::max(maxHeight, field[i][j]);
        }
    }
    return B;
}

int getTime(int height, int B) {
    int higher = 0, lower = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] > height) {
                higher += (field[i][j] - height);
            }
            else if (field[i][j] < height) {
                lower += (height-field[i][j]);
            }
        }
    }
    
    if (higher == 0 && lower == 0)
        return 0;
    if (lower > higher + B)
        return INF;
    return higher * 2 + lower;
}

std::pair<int, int> getMaxTime(int B) {
    int minTime = INF;
    int height;
    for (int t = maxHeight; t >= minHeight; t--) {
        int possibleTime = getTime(t, B);
        if (possibleTime < minTime) {
            minTime = possibleTime;
            height = t;
        }
    }
    return {minTime, height};
}