#include <algorithm>
#include <cstdio>
#define MAX_SIZE 100000

using namespace std;

bool compare (int a, int b){
    return a > b;
}

void input(int* N, int* seq);
void set(int* seq, int A, int B);

int main() {
    int N;
    int seq[MAX_SIZE];
    int K;
    input(&N, seq);

    scanf(" %d", &K);

    for (int i = 0; i < K; i++) {
        int A, B;
        scanf(" %d %d", &A, &B);
        set(seq, A, B);
    }

    for (int j = 0; j < N; j++) {
        printf("%d ", seq[j]);
    }

    return 0;
}

void input(int* N, int* seq) {
    scanf(" %d", N);
    for (int i = 0; i < *N; i++) {
        scanf(" %d", seq+i);
    }
}

void set(int* seq, int A, int B) {
    sort(seq, seq+A);
    sort(seq, seq+B, compare);
}
