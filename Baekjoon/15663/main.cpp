#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#define MAX_SIZE 8
using namespace std;

int N, M;
int arr[MAX_SIZE];
bool check[MAX_SIZE];
set<string> dup;
vector<int> history;
void getSequence(int level);

int main() {
    scanf(" %d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf(" %d", arr + i);
    }

    std::sort(arr, arr+N);
    getSequence(0);

    for (auto d : dup) {
        cout << d << endl;
    }

    return 0;
}

void getSequence(int level) {
    if (level == M) {
        for (auto h : history) {
            printf("%d ", arr[h]);
        }
        printf("\n");
        return;
    }

    int before = -1;
    int back = 0;
    if (!history.empty())
        back = history.back();
    for (int i = back; i < N; i++) {
        if (before != arr[i]) {
            before = arr[i];
            history.push_back(i);
            getSequence(level+1);
            history.pop_back();
        }
    }
}