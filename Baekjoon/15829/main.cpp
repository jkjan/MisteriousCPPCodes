#include <iostream>
#define MAX_SIZE 51
#define M 1234567891
#define R 31
#define TO_NUM(x) ((x)-'a'+1)
using namespace std;
typedef long long ll;

ll pow(int x, int i, int threshold);
ll makeHash(int L, const char* str);

int main() {
    int L;
    char* str = new char[MAX_SIZE];
    scanf(" %d", &L);
    scanf(" %s", str);
    printf("%lld", makeHash(L, str));
    delete[] str;
    return 0;
}

ll pow(int x, int i, int threshold) {
    if (i == 0)
        return 1;
    ll halfX = (ll) pow(x, i / 2, threshold);
    ll newX = (((halfX * halfX)) % threshold
            * (i % 2 ? x : 1)) % threshold;
    return newX;
}

ll makeHash(int L, const char* str) {
    ll hashed = 0;
    for (int i = 0; i < L; i++) {
        hashed = (hashed + (TO_NUM(str[i]) * pow(R, i, M))) % M;
    }
    return hashed;
}