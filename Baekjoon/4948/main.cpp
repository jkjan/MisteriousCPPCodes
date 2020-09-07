#include <iostream>
#include <memory.h>
#define SIZE 246913

using namespace std;

void getAllPrimeNumbers(bool*);
int proveBertrand(const bool*, int);

int main() {
    bool num[SIZE] = {false, };
    int n;
    getAllPrimeNumbers(num);
    while (true) {
        cin >> n;
        if(n==0)
            return 0;
        cout << proveBertrand(num, n) << endl;
    }
}

void getAllPrimeNumbers(bool* num) {
    for (int i = 2; i < SIZE; i++) {
        for (int j = 2; i * j < SIZE; j++) {
            num[i*j] = true;
        }
    }
}

int proveBertrand(const bool* num, int N) {
    int cnt = 0;
    for (int i = N + 1; i <= N*2; i++) {
        if (!num[i]) {
            cnt++;
        }
    }
    return cnt;
}


