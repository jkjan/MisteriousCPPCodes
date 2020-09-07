#include <cstdio>
#include <algorithm>
#define MAX_SIZE 100000

using namespace std;

void input(int* N, int* ropes);
int greedy(int N, int* ropes);

int main() {
    int N;
    int ropes[MAX_SIZE];
    input(&N, ropes);
    printf("%d", greedy(N, ropes));
    return 0;
}

void input(int* N, int* ropes){
    scanf(" %d", N);
    for(int i = 0; i < *N; i++) {
        scanf(" %d", ropes+i);
    }
    sort(ropes, ropes + *N);
}

int greedy(int N, int* ropes) {
    int maxWeight = 0;
    for(int i = 0; i < N; i++) {
        maxWeight = max(maxWeight, ropes[i] * (N - i));
    }
    return maxWeight;
}