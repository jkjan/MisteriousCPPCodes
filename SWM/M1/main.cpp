#include <iostream>
#define MAX_SIZE 100000
using namespace std;
int main() {
    int N, K;
    int arr[MAX_SIZE];
    int min = MAX_SIZE, minIndex = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    int fromStart = (minIndex + 1)/(--K);
    int fromEnd = (N - minIndex + 1)/K;

    printf("%d", fromStart + fromEnd);

    return 0;
}
