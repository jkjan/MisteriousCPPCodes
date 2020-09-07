#include <iostream>
using namespace std;

int N, K;
int W[101], V[101];

int knapsack(int, int);

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    cout << knapsack(0, 1);

    return 0;
}

int knapsack(int nowW, int n) {
    if (n > N)
        return 0;
    int sumW = nowW;
    int sumV = 0;
    int i;
    for (i = n; i <= N; i++) {
        if (W[i] <= K-sumW) {
            sumW += W[i];
            sumV += V[i];
        }
        else break;
    }

    if (i == N+1)
        return sumV;

    int next = 0;
    if (nowW + W[n] <= K)
        next =  knapsack(nowW + W[n], n+1) + V[n];
    return max(next, knapsack(nowW, n+1));
}