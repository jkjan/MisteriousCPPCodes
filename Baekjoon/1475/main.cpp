#include <iostream>

int main() {
    char c;
    int num[10] = {0, };
    char former = 0;
    int max = 0;
    while ((c = (char)getchar()) != '\n') {
        if (c == former) {
            if (c == '6')
                c = '9';
            else
                c = '6';
            former = 0;
        }

        else if (c == '6' || c == '9')
            former = c;

        num[c - '0']++;
    }

    for (int n : num) {
        max = std::max(max, n);
    }
    printf("%d", max);
    return 0;
}
