#include <iostream>

int strlen(const char* S) {
    int i = -1;
    while (S[++i] != NULL);
    return i;
}

int main() {
    char S[101];
    scanf(" %s", S);
    printf("%d", strlen(S));
    return 0;
}
