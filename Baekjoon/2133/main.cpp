#include <iostream>

int main() {
    int N;
    int dp[31] = {1, 0, 3,};
    scanf(" %d", &N);

    if (N % 2 == 0) {
        for (int i = 4; i <= N; i += 2) {
            dp[i] = dp[i - 2] * 3;
            for (int j = 4; j <= i; j += 2) {
                dp[i] += dp[i - j] * 2;
            }
        }
    }
    printf("%d", dp[N]);
    return 0;
}
