#include <iostream>
#define MAX_SIZE 1000000
typedef long long ll;
int N;
int A[MAX_SIZE];
int B, C;
void input();

int main() {
    input();
    ll cnt = N;
    for (int i = 0; i < N; ++i) {
        A[i] -= B;
        if (A[i] > 0) {
            cnt += (A[i]/C + (A[i]%C != 0));
        }
    }
    printf("%lld", cnt);
    return 0;
}

void input() {
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %d", A + i);
    }
    scanf(" %d %d", &B, &C);
}

