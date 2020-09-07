#include <iostream>
#include <set>
using namespace std;

typedef struct word {
    string w;
}word;

void input(int* N, set<word>* words);
void output(set<word>* words);

int main() {
    int N;
    set<word> words;
    input(&N, &words);
    output(&words);
    return 0;
}

bool operator<(const word& a, const word& b) {
    if (a.w.length() == b.w.length()) {
        return a.w < b.w;
    }

    return (a.w.length() < b.w.length());
}

void input(int* N, set<word>* words) {
    cin >> *N;
    for (int i = 0; i < *N; i++) {
        string a;
        cin >> a;
        words->insert({a});
    }
}

void output(set<word>* words) {
    for (auto & s : *words) {
        cout << s.w << endl;
    }
}