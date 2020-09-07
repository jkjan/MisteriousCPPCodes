#include <iostream>
#define MAX_VOL 1001
#define MAX_SONG 101

using namespace std;

int main() {
    int N, S, M;
    int dp[MAX_SONG][MAX_VOL];
    int V[MAX_SONG];
    cin >> N >> S >> M;

    fill(&dp[0][0], &dp[MAX_SONG-1][MAX_VOL], -1);

    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }
    dp[0][S] = S;
    V[0] = S;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i-1][j] == -1)
                continue;
            int added = dp[i-1][j] + V[i];
            int subtracted = dp[i-1][j] - V[i];
            if (added <= M) {
                dp[i][added] = added;
            }
            if (subtracted >= 0) {
                dp[i][subtracted] = subtracted;
            }
        }
    }

    int maxVol = -1;
    for (int i = 0; i <= M; i++) {
        maxVol = max(maxVol, dp[N][i]);
    }

    cout << maxVol;
    return 0;
}