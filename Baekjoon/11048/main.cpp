#include <iostream>
int main() {
    int dp[1001][1001] = {0, };
    int N, M, candy;
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf(" %d", &candy);
            dp[i][j] = std::max(dp[i-1][j], std::max(dp[i][j-1], dp[i-1][j-1])) + candy;
        }
    }
    printf("%d", dp[N][M]);
    return 0;
}