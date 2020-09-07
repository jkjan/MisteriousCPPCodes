#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <list>
#include <set>

using namespace std;

typedef struct bracket {
    int open, close;
} bracket;


void getBrackets(string* s, vector<bracket>* brackets);
bool isIn(int i, list<bracket>* brackets);
void deleteBracket(set<string>* comb, string*s ,int n, vector<bracket>* brackets);

int main() {
    string s;
    set<string> comb;
    vector<bracket> brackets;
    cin >> s;
    getBrackets(&s, &brackets);
    for (int i = 1; i <= brackets.size(); ++i)
        deleteBracket(&comb, &s, i, &brackets);
    for (const auto& c : comb)
        cout << c << endl;
    return 0;
}

void getBrackets(string* s, vector<bracket>* brackets) {
    stack<int> bracketStack;
    for (int i = 0; i < s->length(); i++) {
        if (s->at(i) == '(') {
            bracketStack.push(i);
        }
        else if (s->at(i) == ')') {
            brackets->push_back({bracketStack.top(), i});
            bracketStack.pop();
        }
    }
}

bool isIn(int i, list<bracket>* brackets) {
    for (auto iter = brackets->begin(); iter != brackets->end(); iter++) {
        if (iter->open == i || iter->close == i) {
            if (iter->close == i)
                brackets->erase(iter++);
            return true;
        }
    }
    return false;
}

string withoutBracket(string* s, list<bracket>* brackets) {
    string without;
    for (int i = 0; i < s->length(); i++) {
        if (!isIn(i, brackets)) {
            without += s->at(i);
        }
    }
    return without;
}

void deleteBracket(set<string>* comb, string* s, int n, vector<bracket>* brackets) {
    int len = brackets->size();
    vector<bool> mark(len-n, false);
    for (int i = 0; i < n; i++)
        mark.push_back(true);
    do {
        list<bracket> willDelete;
        for (int i = 0; i < len; ++i) {
            if (mark[i])
                willDelete.push_back(brackets->at(i));
        }
        string without = withoutBracket(s, &willDelete);
        comb->insert(without);
    } while (next_permutation(mark.begin(), mark.end()));
}