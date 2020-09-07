#include <iostream>
#include <cstring>
#include <stack>

bool isPalindrome();

int main() {
    printf("%d", isPalindrome());
}

bool isPalindrome() {
    char S[101];
    std::stack<char> charStack;
    scanf(" %s", S);
    int len = strlen(S);
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