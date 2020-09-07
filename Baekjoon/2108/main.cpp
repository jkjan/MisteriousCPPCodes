#include <iostream>
#include <map>
using namespace std;
struct compare {
    bool operator()(const int a, const int b) {
        return a > b;
    }
};

int main() {
    map<int, int, compare> test;
    test.insert({1, 2});
    test.insert({2, 3});

    for (auto m : test) {
        printf("%d %d\n", m.first, m.second);
    }

    return 0;
}
