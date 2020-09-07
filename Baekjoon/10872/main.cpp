#include <iostream>

using namespace std;

int main() {
    int N;
    int result = 1;
    cin >> N;
    while (N > 1) {
        result *= N;
        N--;
    }
    cout << result;
    return 0;
}
