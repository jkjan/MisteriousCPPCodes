#include <iostream>
#define MAX_SIZE 1000000

typedef long long int ll;

int N, M;
int trees[MAX_SIZE];

void input();
int init();
int getMaxHeight(int high, int low);

int main() {
    input();
    int maxTree = init();
    printf("%d", getMaxHeight(maxTree, 0));
    return 0;
}

void input() {
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf(" %d", trees + i);
    }
}

int init() {
    int maxTree = 0;
    for (int i = 0; i < N; i++) {
        maxTree = (maxTree > trees[i] ? maxTree : trees[i]);
    }

    return maxTree;
}

ll cut(int height) {
    ll treeSum = 0;
    for (int i = 0; i < N; i++) {
        int cutTree = trees[i] - height;
        if (cutTree > 0)
            treeSum += cutTree;
    }
    return treeSum;
}

int lastCheckPoint;
int getMaxHeight(int high, int low) {
    if (high < low)
        return lastCheckPoint;
    int middle = (high + low)/2;
    ll treeSum = cut(middle);

    if (treeSum >= M) {
        lastCheckPoint = middle;
        return getMaxHeight(high, middle + 1);
    }
    else
        return getMaxHeight(middle - 1, low);
}