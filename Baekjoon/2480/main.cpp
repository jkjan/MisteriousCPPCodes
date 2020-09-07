#include <iostream>
int solve();
int main() {
    printf("%d", solve());
    return 0;
}

int solve() {
    int in;
    int dice[7] = {0, };
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        scanf(" %d", &in);
        dice[in]++;
    }
    for (int i = 1; i <= 6; ++i) {
        if (dice[i] == 3)
            return 10000 + i * 1000;
        else if (dice[i] == 2)
            return 1000 + i * 100;
        else if (dice[i] > 0)
            cnt++;
        if (cnt == 3)
            return i * 100;
    }
    return 0;
}