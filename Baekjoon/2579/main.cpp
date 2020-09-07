#include <iostream>
using namespace std;

int stairs[301];
int dp[301] = {0,};

int game(int n) {
    if (n <= 3)
        return dp[n];
    else if (dp[n] == 0) {
        dp[n] = max(game(n-2) + stairs[n], game(n-3) + stairs[n-1] + stairs[n]);
    }
    return dp[n];
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> stairs[i];
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = (stairs[1] > stairs[2] ? stairs[1] : stairs[2]) + stairs[3];

    for (int i = 4; i <= N; i++) {
        dp[i] = max(dp[i-2] + stairs[i], stairs[i-1] + stairs[i] + dp[i-3]);
    }
    cout << dp[N];

    return 0;
}
