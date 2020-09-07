#include <iostream>
#include <string>
int main() {
    int ans = 0;
    std::string A[2];
    std::cin >> A[0] >> A[1];
    int cnt[2][26] = {0,};
    for (int i = 0; i < 2; i++) {
        for (auto a : A[i])
            cnt[i][a - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        ans += abs(cnt[0][i] - cnt[1][i]);
    }
    std::cout << ans;
    return 0;
}
