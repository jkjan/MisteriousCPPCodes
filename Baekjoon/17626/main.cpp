#include <iostream>
#include <climits>
#define MAX_SIZE 50001
using namespace std;

int main() {
    int n;
    int dp[MAX_SIZE];
    fill(dp, dp+MAX_SIZE, 4);
    dp[0] = 0;
    dp[1] = 1;
    scanf(" %d", &n);

    for (int i = 2; i <= n; ++i) {
        int minSquare = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            int square = i - j * j;
            minSquare = min(minSquare, dp[square]);
        }
        dp[i] = minSquare + 1;
    }
    printf("%d", dp[n]);

    return 0;
}
