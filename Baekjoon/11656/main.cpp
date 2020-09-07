#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    set<string> suffixes;
    string S;
    cin >> S;
    for (int i = 0; i < S.length(); ++i) {
        suffixes.insert(S.substr(i));
    }
    for (auto s : suffixes) {
        cout << s << endl;
    }
    return 0;
}
