#include <iostream>
#include <vector>
using namespace std;
typedef struct pos {
    int y, x;
} pos;

void breed(vector<pos> dragonCurve);

int main() {
    return 0;
}

void breed(vector<pos> dragonCurve) {
    pos tip = dragonCurve.back();
    for (int i = 0; i < dragonCurve.size() - 1; ++i) {

    }
}
