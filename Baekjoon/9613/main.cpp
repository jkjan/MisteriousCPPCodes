#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ullint;

void input();
int gcd(int a, int b);

int main() {
    int t;
    scanf(" %d", &t);
    for (int i = 0; i < t; i++) {
        input();
    }
    return 0;
}

ullint getEveryGCD(int n, int* nums) {
    bool* marker = new bool[n];
    int i;
    for (i = 0; i < n - 2; i++) {
        marker[i] = false;
    }
    for (; i < n; i++) {
        marker[i] = true;
    }

    long long int sum = 0;

    do {
        int ab[2];
        int* p = ab;

        for (int j = 0; j < n; j++) {
            if (marker[j]) {
                *p++ = nums[j];
            }
        }
        sum += gcd(ab[0], ab[1]);
    } while (next_permutation(marker, marker+n));

    delete [] marker;
    return sum;
}

void input() {
    int N;
    scanf(" %d", &N);
    int* nums = new int[N];
    for (int i = 0; i < N; i++) {
        scanf(" %d", nums + i);
    }
    printf("%lld\n", getEveryGCD(N, nums));
    delete [] nums;
}

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

