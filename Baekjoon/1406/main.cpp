#include <iostream>
#include <list>
using namespace std;

list<char> str;
list<char>::iterator iter;

void init();
void operate();

int main() {
    init();
    iter = str.end();
    int M;
    scanf(" %d", &M);
    for (int i = 0; i < M; ++i) {
        operate();
    }
    for (auto c : str)
        printf("%c", c);

    return 0;
}

void init() {
    string s;
    cin >> s;
    for (auto c : s)
        str.push_back(c);
}

void L() {
    if (iter != str.begin())
        iter--;
}

void D() {
    if (iter != str.end())
        iter++;
}

void B() {
    auto backup = iter;
    if (iter != str.begin())
        str.erase(--iter);
    iter = backup;
}

void P(char x) {
    str.insert(iter, x);
}

void operate() {
    char cmd;
    scanf(" %c", &cmd);
    if (cmd == 'L')
        L();
    else if (cmd == 'D')
        D();
    else if (cmd == 'B')
        B();
    else {
        scanf(" %c", &cmd);
        P(cmd);
    }
}