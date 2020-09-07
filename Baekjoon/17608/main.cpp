#include <iostream>

int main() {
    int N, sticks[100000], canSee, cnt;
    cnt = 0;
    canSee = 0;
    scanf(" %d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %d", sticks + i);
    }
    for (int i = N-1; i >= 0; i--) {
        if (sticks[i] > canSee) {
            canSee = sticks[i];
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}

