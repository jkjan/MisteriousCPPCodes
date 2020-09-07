#include <iostream>
#define MAX_SIZE 10001

int arr[MAX_SIZE] = {0,};

void input();
void countSort();

int main() {
    input();
    countSort();
    return 0;
}

void input() {
    int N;
    scanf(" %d", &N);
    for (int i = 0; i < N; i++) {
        int n;
        scanf(" %d", &n);
        arr[n]++;
    }
}

void countSort() {
    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 0; j < arr[i]; j++) {
            printf("%d\n", i);
        }
    }
}