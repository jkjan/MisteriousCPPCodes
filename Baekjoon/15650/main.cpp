#include <iostream>
#include <algorithm>

void getSequence(int* arr, int N, int M);

int main() {
    int N, M;
    scanf(" %d %d", &N, &M);
    int* arr = new int[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = i+1;
    }
    getSequence(arr, N, M);
    return 0;
}

void getSequence(int* arr, int N, int M) {
    bool* mask = new bool[N];
    std::fill(mask, mask+M, false);
    std::fill(mask+M, mask+N, true);
    do {
        for (int i = 0; i < N; i++) {
            if (!mask[i])
                printf("%d ", arr[i]);
        }
        printf("\n");
    } while (std::next_permutation(mask, mask+N));
}