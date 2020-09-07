#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isPalindrome(int N) {
    string S = to_string(N);
    std::stack<char> charStack;
    int len = S.length();
    int mid = len/2;
    bool even = !(len%2);
    int i;

    for (i = 0; i <= mid - even; i++) {
        charStack.push(S[i]);
    }

    if (!even)
        charStack.pop();

    for (; i < len; i++) {
        if (charStack.top() != S[i])
            return false;
        charStack.pop();
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    while (!isPalindrome(++N));
    cout << N;
    return 0;
}