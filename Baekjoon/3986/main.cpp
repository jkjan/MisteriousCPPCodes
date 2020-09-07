#include <iostream>
#include <stack>
#include <string>
#include <stack>
using namespace std;

bool tc();

int main() {
    int N, cnt;
    cin >> N;
    cnt = 0;
    for (int i = 0; i < N; ++i) {
        cnt += tc();
    }
    printf("%d", cnt);
    return 0;
}

int top(stack<char>* wordStack) {
    if (wordStack->empty())
        return -1;
    else
        return wordStack->top();
}

bool tc() {
    stack<char> wordStack;
    string w;
    cin >> w;
    for (char c : w) {
        if (top(&wordStack) == c)
            wordStack.pop();
        else
            wordStack.push(c);
    }
    return wordStack.empty();
}
