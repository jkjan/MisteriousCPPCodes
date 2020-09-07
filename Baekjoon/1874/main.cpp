#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void init(int n, stack<int>* last);
int top(stack<int>* s);
void NO();

int main() {
    int n;
    stack<int> s;
    stack<int> last;
    vector<char> arr;

    s.push(0);
    scanf(" %d", &n);
    init(n, &last);

    for (int i = 0; i < n; i++) {
        int num;
        scanf(" %d", &num);

        if (top(&s) < num) {
            int popped = top(&last);
            while (popped <= num && top(&s) < num) {
                popped = last.top();
                last.pop();
                s.push(popped);
                arr.push_back('+');
            }
            if (top(&s) != num)
                NO();
        }

        if (top(&s) >= num) {
            while (top(&s) >= num) {
                s.pop();
                arr.push_back('-');
            }
        }
    }

    for (auto a : arr)
        printf("%c\n", a);

    return 0;
}

void NO() {
    printf("NO");
    exit(0);
}

int top(stack<int>* s) {
    if (s->empty())
        NO();
    else
        return s->top();
}

void init(int n, stack<int>* last) {
    for (int i = n; i >= 1; i--) {
        last->push(i);
    }
}
