#include <iostream>
using namespace std;

int dp[41] = {0, };
int zeros = 0;
int ones = 0;

int fibonacci(int n) {
    if (n == 0) {
        zeros++;
        return 0;
    }
    else if (n == 1) {
        ones++;
        return 1;
    }
    else if (dp[n] == 0)
        dp[n] = fibonacci(n-1) + fibonacci(n-2);
    return dp[n];
}

int main() {
    int T, temp;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> temp;
        fibonacci(temp);
        cout << zeros << " " << ones << endl;
        zeros = ones = 0;
        fill(dp, dp+41, 0);
    }
    return 0;
}