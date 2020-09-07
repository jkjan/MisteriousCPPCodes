#include <iostream>
using namespace std;

bool tile();

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << (tile() ? "YES" : "NO") << endl;
    }
    return 0;
}

bool tile() {
    int N, M;
    cin >> N >> M;
    int A, B, C;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j % 3 == 1) {
                cin >> A;
            }

            else if (j % 3 == 2) {
                cin >> B;
            }

            else {
                cin >> C;
                if (A == 0 && B == 1 && C == 0) {
                    return false;
                }
            }

            if ((j == 3 && A == 1 && B == 0) ||
                (j == M && B == 0 && C == 1)) {
                return false;
            }
        }
    }

    return true;
}