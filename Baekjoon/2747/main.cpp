#include <iostream>

int dp[46] = {0, };

int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n <= 2)
        return 1;
    else if (dp[n] == 0)
        dp[n] = fibo(n-1) + fibo(n-2);
    return dp[n];
}

int main() {
    int n;
    scanf(" %d", &n);
    printf("%d", fibo(n));
    return 0;
}
