#include <iostream>

int alpha[26] = {0, };
void input();
int main() {
    int N;
    bool fail = true;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        input();
    }
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] >= 5) {
            fail = false;
            printf("%c", i + 'a');
        }
    }
    if (fail)
        printf("PREDAJA");
    return 0;
}

void input() {
   char name[31];
   scanf(" %s", name);
   alpha[name[0] - 'a']++;
}
