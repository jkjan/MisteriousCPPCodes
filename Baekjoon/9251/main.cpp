#include <iostream>
#include <cstring>
#define MAX_SIZE 1002

int getLCS(char* a, char* b);

int main() {
    char a[MAX_SIZE], b[MAX_SIZE];
    scanf(" %s %s", a+1, b+1);
    printf("%d", getLCS(a, b));
    return 0;
}

int getLCS(char* a, char* b) {
    int aLen = strlen(a+1);
    int bLen = strlen(b+1);
    int dp[MAX_SIZE][MAX_SIZE] = {0, };
    for (int i = 1; i <= bLen; ++i) {
        for (int j = 1; j <= aLen; ++j) {
            if (a[j] == b[i]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[bLen][aLen];
}