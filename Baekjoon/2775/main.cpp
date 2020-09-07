#include <iostream>
#define MAX_SIZE 14
using namespace std;

int arr[MAX_SIZE+1][MAX_SIZE+1];
void init();
void getArr();
void tc();

int main() {
    int T;
    init();
    getArr();
    scanf(" %d", &T);
    for (int i = 0; i < T; i++) {
        tc();
    }

    return 0;
}

void init() {
    fill(&(arr[0][0]), &(arr[MAX_SIZE-1][MAX_SIZE]), 0);
    for (int i = 1; i <= MAX_SIZE; ++i) {
        arr[0][i] = i;
    }
}

void getArr() {
    for (int i = 1; i <= MAX_SIZE; i++) {
        for (int j = 1; j <= MAX_SIZE; ++j) {
            for (int k = 1; k <= j; ++k) {
                arr[i][j] += arr[i-1][k];
            }
        }
    }
}

void tc() {
    int k, n;
    scanf(" %d", &k);
    scanf(" %d", &n);
    printf("%d\n", arr[k][n]);
}