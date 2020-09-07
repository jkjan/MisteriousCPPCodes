#include <iostream>
#include <algorithm>

bool compare(char a, char b) {
    return a > b;
}

int main() {
    char arr[11];
    int i = 0;
    while (fscanf(stdin, "%c", arr + (i++)) != EOF);
    arr[--i] = 0;
    std::sort(arr, arr + i, compare);
    printf("%s", arr);
    return 0;
}
