#include <iostream>
#include <string>
int main() {
    int cnt = 0;
    int bits = 1065233;
    std::string a;
    std::cin >> a;
    for (auto c : a)
        if (bits & 1 << (c - 'a'))
            cnt++;
    std::cout << cnt;
    return 0;
}