#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void tc();
long scanf();

int main() {
    uint T = scanf();
    for (int i = 0; i < T; ++i) {
        tc();
    }
    return 0;
}

long scanf() {
    char* ptr;
    char str[256];
    scanf(" %s", str);
    return strtol(str, &ptr, 10);
}

void getNums(vector<uint>* num, map<string, uint>* wardrobe) {
    num->reserve(wardrobe->size());
    for (const auto& w : *wardrobe) {
        num->push_back(w.second);
    }
}

void input(vector<uint>* num) {
    uint n = (uint)scanf();
    map<string, uint> wardrobe;
    for (uint i = 0; i < n; ++i) {
        string wear, type;
        cin >> wear >> type;
        if (wardrobe.count(type) == 0)
            wardrobe.insert({type, 1});
        else
            wardrobe[type]++;
    }
    getNums(num, &wardrobe);
}

void tc() {
    vector<uint> num;
    input(&num);
    uint cases = 1;
    for(auto n : num) {
        cases *= (n+1);
    }
    printf("%d\n", cases - 1);
}