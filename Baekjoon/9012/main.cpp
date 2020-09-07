#include <iostream>
#include <stack>
using namespace std;

void tc();

int main() {
    int t;
    scanf(" %d", &t);
    for (int i = 0; i < t; i++)
        tc();
    return 0;
}

bool isValid(char* PS) {
    stack<bool> checker;
    while (*PS != 0) {
        if (*PS == '(')
            checker.push(true);
        else {
            if (checker.empty())
                return false;
            else {
                if (!checker.top())
                    return false;
                checker.pop();
            }
        }
        PS++;
    }
    return checker.empty();
}

void tc() {
    char* PS = new char[51];
    scanf(" %s", PS);
    printf("%s\n", isValid(PS)?"YES":"NO");
    delete[](PS);
}