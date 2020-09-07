#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector< vector<ll> > matrix;
int N;

matrix input(ll* M);
template<typename ty>
ty myPow(ty m, ll pow);
void printMatrix(matrix m);

int main() {
    ll M;
    matrix m = input(&M);
    m = myPow<matrix>(m, M);
    printMatrix(m);
    return 0;
}

matrix operator*(const matrix & a, const matrix & b) {
    matrix c(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}

template<typename ty>
ty myPow(ty m, ll pow) {
    if (pow == 1)
        return m;
    ty half = myPow(m, pow/2);
    ty square = half * half;
    if (pow%2)
        square = square * m;
    return square;
}

matrix input(ll* M) {
    scanf(" %d %lld", &N, M);
    matrix m(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %lld", &(m[i][j]));
        }
    }
    return m;
}

void printMatrix(matrix m) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%lld ", m[i][j]);
        }
        printf("\n");
    }
}
