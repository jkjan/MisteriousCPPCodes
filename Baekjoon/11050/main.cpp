#include <iostream>
#define MAX_SIZE 10

int dp[MAX_SIZE + 1] = {0, };
int factorial(int n);

int main() {
    int N, K;
    scanf(" %d %d", &N, &K);
    printf("%d", (factorial(N)/factorial(K)/factorial(N-K)));
    return 0;
}

int factorial(int n) {
    if (n <= 1) {
        dp[n] = 1;
    }
    else if (dp[n] == 0) {
        dp[n] = n * factorial(n-1);
    }
    return dp[n];
}
