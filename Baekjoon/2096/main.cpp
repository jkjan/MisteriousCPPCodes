#include <iostream>
using namespace std;

typedef int(*compare)(int, int);
int max(int a, int b);
int min(int a, int b);
void getDp(int N, int dp[][2][3], compare* f);

int main() {
    int N;
    int dp[2][2][3] = {0, };
    compare f[2] = {max, min};
    scanf(" %d", &N);
    getDp(N, dp, f);

    for (int i = 0; i < 2; ++i)
        printf("%d ", f[i](f[i](dp[i][1][0], dp[i][1][1]), dp[i][1][2]));

    return 0;
}

void getDp(int N, int dp[][2][3], compare* f) {
    short newLine[3];

    for (int i = 1; i <= N; ++i) {
        scanf(" %hd %hd %hd", newLine, newLine + 1, newLine + 2);
        for (int j = 0; j < 2; j++) {
            dp[j][1][0] = newLine[0] + f[j](dp[j][0][0], dp[j][0][1]);
            dp[j][1][1] = newLine[1] + f[j](f[j](dp[j][0][0], dp[j][0][1]), dp[j][0][2]);
            dp[j][1][2] = newLine[2] + f[j](dp[j][0][1], dp[j][0][2]);
            for (int k = 0; k < 3; ++k)
                dp[j][0][k] = dp[j][1][k];
        }
    }
}

int max(int a, int b) {
    return std::max(a, b);
}

int min(int a, int b) {
    return std::min(a, b);
}