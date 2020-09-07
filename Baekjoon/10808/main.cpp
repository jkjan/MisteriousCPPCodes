#include <iostream>
#include <cstring>

int main() {
    int alphas[26] = {0, };
    char S[101];
    scanf(" %s", S);
    int len = strlen(S);
    for (int i = 0; i < len; ++i) {
        alphas[S[i]-'a']++;
    }
    for (auto alpha : alphas) {
        printf("%d ", alpha);
    }
    return 0;
}

