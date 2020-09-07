#include <iostream>
#include <cmath>
#define MAX_SIZE 1000001

using namespace std;
typedef long long int ll;

int main() {
    ll min, max;
    bool erased[MAX_SIZE] = {false,};
    scanf(" %lld %lld", &min, &max);
    ll cnt = max - min + 1;
    ll limit = (ll) sqrt(max);
    for (ll i = 2; i <= limit; i++) {
        ll squared = i * i;
        ll start = min / squared;
        start = start * squared;
        for (ll j = start; j <= max; j += squared) {
            if (min <= j && j <= max) {
                int downToIndex = (int)(j - min);
                if (!erased[downToIndex]) {
                    cnt -= 1;
                    erased[downToIndex] = true;
                }
            }
        }
    }

    printf("%lld", cnt);

    return 0;
}