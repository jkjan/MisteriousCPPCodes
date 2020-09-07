#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        char s[31];
        scanf(" %[^\n]", s);
        s[0] = toupper(s[0]);
        printf("%s\n", s);
    }
    return 0;
}
