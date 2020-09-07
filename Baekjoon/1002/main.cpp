#include <iostream>
#include <cmath>

int tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        printf("%d\n", tc());
    }
    return 0;
}

int tc() {
    int x1, y1, r1, x2, y2, r2;
    scanf(" %d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

    if (x1 == x2 && y1 == y2) {
        if (r1 == r2)
            return -1;
    }

    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    if (abs(r1- r2) < dist && dist < r1 + r2)
        return 2;
    else if (abs(r1 - r2) == dist || r1 + r2 == dist)
        return 1;
    else
        return 0;
}