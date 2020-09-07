#include <iostream>
#define MAX_SIZE 100001
int main() {
    int N;
    int dp[MAX_SIZE][3];
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    scanf(" %d", &N);
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }
    printf("%d", (dp[N][0] + dp[N][1] + dp[N][2]) % 9901);
    return 0;
}
