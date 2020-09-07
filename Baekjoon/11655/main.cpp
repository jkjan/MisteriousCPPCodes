#include <iostream>
int main() {
    char s[101];
    int len = -1;
    scanf("%[^\n]", s);
    while (s[++len] != 0);
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            if (islower(s[i]))
                s[i] = ((s[i] - 'a') + 13) % 26 + 'a';
            else
                s[i] = ((s[i] - 'A') + 13) % 26 + 'A';
        }
    }
    printf("%s", s);
    return 0;
}