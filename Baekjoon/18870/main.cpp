#include <iostream>
#include <map>
#define MAX_SIZE 1000000
using namespace std;

void input(int* N, int* coords, map<int, int>* coordMap);
void press(map<int, int>* coordMap);
void output(const int* N, int* coords, map<int, int>* coordMap);

int main() {
    int N;
    map<int, int> coordMap;
    int coords[MAX_SIZE];
    input(&N, coords, &coordMap);
    press(&coordMap);
    output(&N, coords, &coordMap);
    return 0;
}

void input(int* N, int* coords, map<int, int>* coordMap) {
    scanf(" %d", N);
    for (int i = 0; i < *N; ++i) {
        scanf(" %d", coords+i);
        coordMap->insert({coords[i], 0});
    }
}

void press(map<int, int>* coordMap) {
    uint idx = 0;
    for (auto & c : *coordMap)
        c.second = idx++;
}

void output(const int* N, int* coords, map<int, int>* coordMap) {
    for (int i = 0; i < *N; ++i)
        printf("%d ", coordMap->at(coords[i]));
}