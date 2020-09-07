#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt = 0;
bool* vertical;
bool* upperDiagonal;
bool* lowerDiagonal;

void n_queen(int i);

int main() {
    scanf(" %d", &N);
    vertical = new bool[N];
    upperDiagonal = new bool[2*N - 1];
    lowerDiagonal = new bool[2*N - 1];
    n_queen(0);
    printf("%d", cnt);
    delete [] vertical;
    delete [] upperDiagonal;
    delete [] lowerDiagonal;
    return 0;
}

void n_queen(int i) {
    if (i == N) {
        cnt++;
        return;
    }
    for (int j = 0; j < N; j++) {
        int upper = i + j;
        int lower = i - j + N - 1;
        if (!vertical[j] && !upperDiagonal[upper] && !lowerDiagonal[lower]) {
            vertical[j] = upperDiagonal[upper] = lowerDiagonal[lower] = true;
            n_queen(i+1);
            vertical[j] = upperDiagonal[upper] = lowerDiagonal[lower] = false;
        }
    }
}