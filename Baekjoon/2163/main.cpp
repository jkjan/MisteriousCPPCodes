#include <iostream>
#include <utility>
using namespace std;

int dp[301][301];

int cutChocolate(int n, int m);

int main() {
    for (int i = 0; i < 301; i++)
        fill(dp[0], dp[300], 0);
    int n, m;
    cin >> n >> m;
    cout << cutChocolate(n, m);
    return 0;
}

int cutChocolate(int n, int m) {
    if (n < m)
        swap(n, m);
    if (m == 1)
        return n-1;
    else if (dp[n][m] == 0) {
        int half = n / 2;
        int otherHalf = n - half;
        dp[n][m] = cutChocolate(half, m) + cutChocolate(otherHalf, m) + 1;
    }
    return dp[n][m];
}