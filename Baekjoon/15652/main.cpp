#include <iostream>
#include <queue>
using namespace std;
int N, M;

void getSequence(int level, deque<int> history);

int main() {
    deque<int> history;
    scanf(" %d %d", &N, &M);
    getSequence(0, history);
    return 0;
}

void getSequence(int level, deque<int> history) {
    if (level == M) {
        while (!history.empty()) {
            printf("%d ", history.front());
            history.pop_front();
        }
        printf("\n");
        return;
    }
    int back = 1;
    if (!history.empty())
        back = history.back();
    for (int i = back; i <= N; i++) {
        history.push_back(i);
        getSequence(level+1, history);
        history.pop_back();
    }
}
