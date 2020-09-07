#include <iostream>
#include <algorithm>

bool compare(char a, char b) {
    return a > b;
}

int main() {
    int i = 0;
    char thirty[100001];
    bool appear[10] = {false, };
    int cnt = 0;
    int num;
    while (fscanf(stdin, " %c", thirty + i) != EOF) {
        num = thirty[i] - '0';
        appear[num] = true;
        cnt += num;
        i++;
    }
    thirty[i] = 0;
    if (!appear[0] || cnt % 3 != 0) {
        printf("-1");
        return 0;
    }
    std::sort(thirty, thirty + i, compare);
    printf("%s", thirty);
    return 0;
}
