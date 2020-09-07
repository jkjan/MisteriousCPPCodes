#include <iostream>
#include <algorithm>
#define MAX_SIZE 200001
using namespace std;
void tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d\n", i);
        tc();
    }
    return 0;
}

void tc() {
    int N, K, A[MAX_SIZE], B[MAX_SIZE];
    scanf(" %d %d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", A + i);
    }
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", B + i);
    }
    sort(A+1, A+N+1);
    sort(B+1, B+N+1);
    int Ai = K/N;
    int Bi = K%N;
    if (Bi == 0)
        Bi = N;
    if (Ai == 0)
        Ai = 1;
    printf("%d\n", A[Ai] + B[Bi]);
}