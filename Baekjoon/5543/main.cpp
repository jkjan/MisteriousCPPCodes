#include <iostream>
#define MIN 4000
using namespace std;

int main() {
    int costs[5];
    for (int & cost : costs) {
        cin >> cost;
    }
    int minCost = MIN;

    for (int i = 0; i < 3; i++) {
        minCost = min(minCost, (costs[i] + costs[3]));
        minCost = min(minCost, (costs[i] + costs[4]));
    }
    cout << minCost - 50;
    return 0;
}
