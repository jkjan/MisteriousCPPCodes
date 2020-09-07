#include <iostream>
#define INF 10001

int main() {
    int N, K, prod, dp[101][10001], coins[101];
    std::fill(&(dp[0][0]), &(dp[100][10001]), INF);
    scanf(" %d %d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", coins + i);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (j == coins[i]) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            for (int k = 1; (prod = k * coins[i]) < j; ++k) {
                dp[i][j] = std::min(dp[i][j], dp[i][j-prod] + dp[i][prod]);
            }
        }
    }

    printf("%d", dp[N][K] >= INF ? -1 : dp[N][K]);
    return 0;
}
