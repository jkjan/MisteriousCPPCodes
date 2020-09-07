#include <iostream>
#include <vector>
#define MAX_SIZE 3000

using namespace std;

typedef long long ll;

typedef struct pos {
    ll x, y;
} pos;

typedef struct line {
    pos pos1, pos2;
} line;

int ccw(pos pos1, pos pos2, pos pos3);
bool isIntersect(line line1, line line2);
int unionParent(int a, int b);
int getParent(int x);

int parent[MAX_SIZE];
int groupSizes[MAX_SIZE];

int main() {
    int N;
    int maxGroupCnt = 1;
    int groupCnt = 0;
    line lines[MAX_SIZE];
    scanf(" %d", &N);

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        groupSizes[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        lines[i] = {{x1, y1}, {x2, y2}};

        for (int j = 0; j < i; j++) {
            if (getParent(i) == getParent(j))
                continue;

            if (isIntersect(lines[i], lines[j])) {
                maxGroupCnt = max(maxGroupCnt, unionParent(i, j));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (parent[i] == i)
            groupCnt++;
    }

    printf("%d\n%d", groupCnt, maxGroupCnt);

    for (int i = 0; i < N; i++) {
        printf("%d ", parent[i]);
    }

    return 0;
}

int ccw(pos pos1, pos pos2, pos pos3) {
    ll criterion = (pos1.x * pos2.y + pos2.x * pos3.y + pos3.x * pos1.y)
                    - (pos1.y * pos2.x + pos2.y * pos3.x + pos3.y * pos1.x);

    if (criterion > 0)
        return 1;
    else if (criterion == 0)
        return 0;
    else
        return -1;
}

bool isIntersect(line line1, line line2) {
    pos a = line1.pos1;
    pos b = line1.pos2;
    pos c = line2.pos1;
    pos d = line2.pos2;

    int ct1 = ccw(a, b, c) * ccw(a, b, d);
    int ct2 = ccw(c, d, a) * ccw(c, d, b);

    if (ct1 == 0 && ct2 == 0) {
        if (a.x > b.x) {
            swap(a, b);
        }
        if (c.x > d.x) {
            swap(c, d);
        }
        return c.x <= b.x && a.x <= d.x;
    }

    return ct1 <= 0 && ct2 <=0;
}

int getParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

int unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (groupSizes[a] > groupSizes[b])
        swap(a, b);
    parent[a] = b;
    groupSizes[b] += groupSizes[a];
    return groupSizes[b];
}