#include <iostream>

using namespace std;

int main() {
    int N, K, i, j;
    int cnt = 0;
    bool num[1001] = {false,};
    cin >> N >> K;
    for(i = 2; i <= N; i++) {
        for (j = 1; i*j <= N; j++) {
            if (!num[i*j]) {
                num[i*j] = true;
                cnt++;
                if (cnt == K) {
                    cout << i*j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
