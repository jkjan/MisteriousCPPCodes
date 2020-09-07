#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string s);
string balance(string s);

string solution(string s) {
    if (isBalanced(s))
        return s;
    else
        return balance(s);
}

int divide(string s) {
    int open, close, i;
    open = close = i = 0;
    while (open != close || (open == 0 && close == 0)) {
        if (s[i] == '(')
            open++;
        else
            close++;
        i++;
    }
    return i;
}

bool isBalanced(string s) {
    stack<char> bracket;
    for (auto c : s) {
        if (c == ')') {
            if (bracket.empty())
                return false;
            if (bracket.top() == '(')
                bracket.pop();
        }
        else
            bracket.push('(');
    }
    return bracket.empty();
}

string balance(string s) {
    if (s.length() == 0)
        return s;
    int cut = divide(s);
    string u = s.substr(0, cut);
    string v = s.substr(cut);
    if (isBalanced(u)) {
        return u + balance(v);
    }
    else {
        string temp = "(";
        temp += balance(v);
        temp += ")";
        u = u.substr(1, u.length()-2);
        for (auto c : u)
            temp.push_back(c == '(' ? ')' : '(');
        return temp;
    }
}
