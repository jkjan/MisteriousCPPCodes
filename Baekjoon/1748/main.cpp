#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    if (N <= 9) {
        cout << N;
        return 0;
    }

    int digit = log10(N);
    int newDigit = 0;
    int counter = 9;
    int i;
    for(i = 1; i <= digit; i++) {
        newDigit += i*counter;
        counter *= 10;
    }

    newDigit += i * (N - (int)pow(10, digit) + 1);
    cout << newDigit;
    return 0;
}
