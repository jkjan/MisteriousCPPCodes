#include <iostream>
#define N 1001
#define R 0
#define G 1
#define B 2
#define MAX 1000 * 1000 + 1
using namespace std;

int main() {
    int dp[N][3];
    int home[3];
    int n;
    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf(" %d %d %d", home+R, home+G, home+B);
        for (int j = 0; j <= 2; ++j) {
            if (i == 1)
                dp[1][j] = home[j];
            else {
                int minCost = MAX;
                for (int k = 0; k <= 2; ++k)
                    if (j != k)
                        minCost = min(minCost, dp[i-1][k]);
                dp[i][j] = home[j] + minCost;
            }
        }
    }
    int minCost = MAX;
    for (int i = 0; i <= 2; ++i)
        minCost = min(minCost, dp[n][i]);
    cout << minCost;
    return 0;
}