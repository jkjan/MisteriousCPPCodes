#include <iostream>
int main() {
    int N;
    int dp[1000001] = {1, };
    scanf(" %d", &N);
    for (int i = 1; i <= N; ++i)
        dp[i] = (dp[i-1] + (i%2 ? 0 : dp[i/2])) % 1000000000;
    printf("%d", dp[N]);
    return 0;
}