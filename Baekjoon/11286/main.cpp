#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(int a, int b) {
        int aa = abs(a);
        int ba = abs(b);
        if (aa == ba)
            return a > b;
        return aa > ba;
    }
};

long input();

int main() {
    priority_queue<int, vector<int>, compare> pq;
    int N = (int)input();
    for (int i = 0; i < N; ++i) {
        int x = (int)input();
        if (x == 0) {
            if (!pq.empty()) {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else
                printf("0\n");
        }
        else
            pq.push(x);
    }
    return 0;
}

long input() {
    char *ptr;
    char str[256];
    scanf(" %s", str);
    return strtol(str, &ptr, 10);
}