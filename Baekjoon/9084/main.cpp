#include <iostream>
#define MAX_COIN 101
#define MAX_VALUE 10001

using namespace std;

void input(int* n, int* k, int* coin);
void tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        tc();
    }
}

void tc() {
    int dp[2][MAX_VALUE];
    int n, k;
    int coin[MAX_COIN];
    bool up = false;
    input(&n, &k, coin);
    fill(&dp[0][0], &dp[1][MAX_VALUE], 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[up][j] = 0;
            if (j % coin[i] == 0) {
                dp[up][j]++;
            }
            for(int l = j; l >= 1; l-= coin[i]) {
                dp[up][j] += dp[!up][l];
            }
        }
        up = !up;
    }

    printf("%d\n", dp[!(n%2)][k]);
}

void input(int* n, int* k, int* coin) {
    scanf(" %d", n);
    for(int i = 1; i <= *n; i++) {
        scanf(" %d", coin + i);
    }
    scanf(" %d", k);
}
