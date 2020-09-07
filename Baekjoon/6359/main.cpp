#include <iostream>
#include <cmath>

int tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i)
        printf("%d\n", tc());
    return 0;
}

int tc() {
    int n;
    int cnt = 0;
    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i) {
        int sq = (int)sqrt(i);
        if (sq * sq == i)
            cnt++;
    }
    return cnt;
}