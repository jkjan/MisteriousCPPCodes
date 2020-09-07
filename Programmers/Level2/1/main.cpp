#include <iostream>
#include <iostream>
using namespace std;

int solution(int n) {
    int cnt = 0;
    while (n != 0) {
        if (n >= 2 && n % 2 == 0)
            n /= 2;
        else {
            n--;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int N = 6;
    cout << solution(N);
    return 0;
}
