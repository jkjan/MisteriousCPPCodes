#include <iostream>
using namespace std;
int main() {
    int N, K;
    int arr[3000];
    cin >> N >> K;
    int maxSize = N-K+1;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int minD = arr[N-1] - arr[0];
    for (int i = 0; i <= N-maxSize; i++) {
        minD = min(arr[i+maxSize-1] - arr[i], minD);
    }
    cout << minD;
    return 0;
}
