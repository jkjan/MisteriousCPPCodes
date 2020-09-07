#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    if (N%2 == 1) {
        cout << 7;
    }
    else {
        cout << 1;
    }
    for (int i = 0; i < N/2 - 1; i++) {
        cout << 1;
    }
    return 0;
}
