#include <iostream>
#include <string>
using namespace std;
int main() {
    string words[5];
    for(auto & word : words) {
        cin >> word;
    }
    int cnt;
    for (int i = 0; i < 15; i++) {
        cnt = 0;
        for (auto & word : words) {
            if (word.size() > i) {
                cout << word[i];
                cnt++;
            }
        }
        if (cnt == 0)
            break;
    }

    return 0;
}
