#include <iostream>
using namespace std;

int getSum(int*, int, int);

int main() {
    int N, M;
    int cards[100];
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    cout << getSum(cards, N, M);
    return 0;
}

int getSum(int* cards, int N, int M) {
    int sum = 0;
    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                sum = cards[i] + cards[j] + cards[k];
                //cout << sum << " : " << cards[i] << ' ' << cards[j] << ' ' << cards[k] << endl;
                if (sum <= M)
                    maxSum = max(sum, maxSum);
                sum = 0;
            }
        }
    }
    return maxSum;
}