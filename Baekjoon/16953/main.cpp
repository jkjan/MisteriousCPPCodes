#include <iostream>

int cnt = 0;
int start;

bool howMany(int num);

int main() {
    int goal;
    scanf(" %d %d", &start, &goal);
    bool succeed = howMany(goal);
    printf("%d", succeed ? cnt : -1);
    return 0;
}

bool howMany(int num) {
    cnt++;
    if (num == start)
        return true;
    if (num == 0) {
        return false;
    }
    if (num % 2 && (num % 10 == 1))
        return howMany(num/10);
    else if (num % 2 == 0)
        return howMany(num/2);
    else
        return false;
}