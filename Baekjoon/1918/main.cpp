#include <iostream>
#include <cstring>
#include <stack>
#define UP true
#define LOW false
#define EMPTY 'E'
using namespace std;

typedef bool(*priority)(char);

char mid[101];
int len;
int getPostfix(int i);

int main() {
    scanf(" %s", mid);
    len = strlen(mid);
    getPostfix(0);
    return 0;
}

char top(stack<char>* operators) {
    if (operators->empty())
        return EMPTY;
    else
        return operators->top();
}

void end(stack<char>* operators, bool(*condition)(char)) {
    char recent = top(operators);
    while (recent != EMPTY && condition(recent)) {
        printf("%c", recent);
        operators->pop();
        recent = top(operators);
    }
}

priority func(bool isUpper){
    return isUpper ?
        [](char c){return c == '*' || c == '/';} :
        [](char c){return c == '+' || c == '-';};
}

bool close(stack<char>* operators, priority p) {
    char recent = top(operators);
    if (p(recent)) {
        printf("%c", recent);
        operators->pop();
        return true;
    }
    return false;
}

int getPostfix(int i) {
    stack<char> operators;

    for (; i < len; i++) {
        if (mid[i] == ')')
            break;
        else if (mid[i] == '(') {
            i = getPostfix(i + 1);
            close(&operators, func(UP));
        }
        else if (isalpha(mid[i])) {
            printf("%c", mid[i]);
            close(&operators, func(UP));
        }
        else {
            if (mid[i] == '+' || mid[i] == '-')
                if (!close(&operators, func(LOW)))
                    end(&operators, func(UP));
            operators.push(mid[i]);
        }
    }

    end(&operators, [](char c){return true;});
    return i;
}