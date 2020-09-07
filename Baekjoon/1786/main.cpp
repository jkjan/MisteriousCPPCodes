#include <iostream>
#include <vector>
#include <cstring>
#define MAX_SIZE 1000002
using namespace std;

vector<int> kmp(char* str, int sLen, char* p, int pLen);

int main() {
    char str[MAX_SIZE], p[MAX_SIZE];
    fgets(str, MAX_SIZE, stdin);
    fgets(p, MAX_SIZE, stdin);
    int sLen = strlen(str);
    int pLen = strlen(p);
    str[sLen-1] = 0;
    p[pLen-1] = 0;
    auto found = kmp(str, --sLen, p, --pLen);
    printf("%zu\n", found.size());
    for(auto f : found) {
        printf("%d ", f);
    }
    return 0;
}

vector<int> getPi(char* p, int pLen) {
    vector<int> pi(pLen, 0);
    int j = 0;
    for (int i = 1; i < pLen; ++i) {
        while (j > 0 && p[i] != p[j])
            j = pi[j-1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(char* str, int sLen, char* p, int pLen) {
    vector<int> pi = getPi(p, pLen);
    vector<int> pos;
    int j = 0;
    for (int i = 0; i < sLen; i++) {
        while (j > 0 && str[i] != p[j])
            j = pi[j-1];
        if (str[i] == p[j]) {
            if (j == pLen - 1) {
                pos.push_back(i-pLen+2);
                j = pi[j];
            }
            else
                j++;
        }
    }
    return pos;
}
