#include <iostream>
using namespace std;

int main() {
    int H, M;
    cin >> H >> M;

    if (M >= 45) {
        cout << H << ' ' << M-45 << endl;
    }

    else {
        cout << ((H == 0) ? 23 : H - 1) << ' ' << 15 + M << endl;
    }
    return 0;
}
