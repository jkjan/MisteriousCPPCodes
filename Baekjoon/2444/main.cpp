#include <iostream>

void printRepeatedly(char c, int n);

int main() {
    int N, i;
    bool ascending = true;
    scanf(" %d", &N);
    i = N-1;
    do {
        printRepeatedly('*', N - i);
        printRepeatedly(' ', i);
        printf("\n");
        i += ascending ? -1 : 1;
        if (i == 0)
            ascending = false;
    } while (i != N && i >= 0);
    return 0;
}

void printRepeatedly(char c, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
}