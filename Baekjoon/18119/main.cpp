#include <cstring>
#include <bitset>

using namespace std;

void init();
void input(int* M);
int query(int q, char x);

int N;
int cur;
int need[10000];

int main() {
    int M, q;
    char x;
    init();
    input(&M);

    for (int k = 0; k < M; ++k) {
        scanf(" %d %c", &q, &x);
        printf("%d\n", query(q, x));
    }

    return 0;
}

bool doesHeKnow(int word) {
    return (cur & word) == word;
}

void remember(int* status, char c) {
    *status = *status | (1 << (25 - c + 'a'));
}

void forget(int* status, char c) {
    *status = *status - (1 << (25 - c + 'a'));
}

int neededAlphabets(char* word, int len) {
    int x = 0;
    for (int i = 0; i < len; i++) {
        remember(&x, word[i]);
    }
    return x;
}

int countWords() {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        cnt += doesHeKnow(need[i]);
    }
    return cnt;
}

int query(int q, char x) {
    if (q == 1)
        forget(&cur, x);
    else
        remember(&cur, x);
    return countWords();
}

void init() {
    for (int i = 0; i < 26; ++i) {
        remember(&cur, i+'a');
    }
}

void input(int* M) {
    int len;
    char word[1001];
    scanf(" %d %d", &N, M);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", word);
        len = strlen(word);
        need[i] = neededAlphabets(word, len);
    }
}