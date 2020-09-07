#include <iostream>
#define MAX_SIZE 1000000 + 1
using namespace std;

void getPrime(int* num);
void getPair(int* num, int n);

int main() {
    int num[MAX_SIZE] = {0, };
    int n = 1;
    num[1] = 1;
    getPrime(num);
    while (true) {
        scanf(" %d", &n);
        if (n == 0)
            break;
        getPair(num, n);
    }
    return 0;
}

void getPrime(int* num) {
    for (int i = 2; i <= MAX_SIZE; i++) {
        if (num[i] == 0) {
            for (int j = 2*i; j <= MAX_SIZE; j += i) {
                num[j] = 1;
            }
        }
    }
}

void getPair(int* num, int n) {
    for (int i = n; i >= 3; i--) {
        if (num[i] == 0 && num[n-i] == 0) {
            printf("%d = %d + %d\n", n, n-i, i);
            return;
        }
    }
    printf("Goldbach's conjecture is wrong.\n");
}