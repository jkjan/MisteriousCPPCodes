#include <iostream>
using namespace std;

string doc, word;
int isSame(int i);

int main() {
    int i, j, cnt;
    i = cnt = 0;
    getline(cin, doc);
    getline(cin, word);
    while (i < doc.length()) {
        if ((j = isSame(i)) == -1)
            i++;
        else {
            i = j;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

int isSame(int i) {
    for (auto c : word) {
        if (c != doc[i++])
            return -1;
    }
    return i;
}