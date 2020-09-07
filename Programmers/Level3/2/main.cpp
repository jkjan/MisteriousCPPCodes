#include <iostream>
#include <string>
#include <vector>
#define MAX_SIZE 501

using namespace std;

int solution(vector<vector<int>> triangle) {
    int dp[MAX_SIZE][MAX_SIZE] = {0, };
    int N = triangle.size();
    dp[1][1] = triangle[0][0];
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= triangle[i-1].size() ; ++j) {
            if (j == 1)
                dp[i][j] = triangle[i-1][j-1] + dp[i-1][j];
            else if (j == triangle[i-1].size())
                dp[i][j] = triangle[i-1][j-1] + dp[i-1][j-1];
            else
                dp[i][j] = triangle[i-1][j-1] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    int m = dp[N][1];
    for (int i = 1; i <= N; i++) {
        m = max(m, dp[N][i]);
    }
    return m;
}

int main() {
    vector<vector<int>> triangle ={{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    solution(triangle);
    return 0;
}
