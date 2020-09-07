#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve();

int main() {
    int t;
    scanf(" %d", &t);
    for (int i = 0; i < t; i++) {
        printf("%d\n", solve());
    }
    return 0;
}

int findSubset(int n, int x, vector<int> array);

int solve() {
    int n, x;
    int answer = -1;
    scanf(" %d %d", &n, &x);
    vector<int> array(n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &(array[i]));

    while (answer == -1) {
        answer = findSubset(n, x, array);
        n--;
        if (n == 0)
            break;
    }

    return answer;
}

int findSubset(int n, int x, vector<int> array) {
    int k = array.size();
    auto* mask = new bool[k];
    int i;

    for (i = 0; i < k-n; i++) {
        mask[i] = false;
    }
    for (; i < k; i++) {
        mask[i] = true;
    }

    do {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            if (mask[j])
                sum += array[j];
        }

        if (sum % x != 0)
            return n;

    } while (next_permutation(mask, mask+k));

    delete [] (mask);

    return -1;
}
