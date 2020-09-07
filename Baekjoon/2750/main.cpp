#include <iostream>
#include <algorithm>

int main() {
    int N;
    int arr[1000];
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %d", arr + i);
    }
    std::sort(arr, arr+N);
    for (int j = 0; j < N; ++j) {
        printf("%d\n", arr[j]);
    }

    return 0;
}
