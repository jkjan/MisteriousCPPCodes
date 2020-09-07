#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void input(int* N, string* S);
void getPn(const int* N, string* Pn);
int kmp(string str, string p);

int main() {
    int N;
    string S, Pn;
    input(&N, &S);
    getPn(&N, &Pn);
    printf("%d", kmp(S, Pn));
    return 0;
}

void input(int* N, string* S) {
    int M;
    scanf(" %d", N);
    scanf(" %d", &M);
    cin >> *S;
}

void getPn(const int* N, string* Pn) {
    for (int i = 0; i < *N; ++i) {
        *Pn += "IO";
    }
    *Pn += "I";
}

vector<int> getPi(string p) {
    int len = p.length();
    int j = 0;
    vector<int> pi(len, 0);
    for (int i = 1; i < len; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j-1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

int kmp(string str, string p) {
    vector<int> pi = getPi(p);
    int sLen = str.length();
    int pLen = p.length();
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < sLen; i++) {
        while (j > 0 && str[i] != p[j])
            j = pi[j-1];
        if (str[i] == p[j]) {
            if (j == pLen - 1) {
                cnt++;
                j = pi[j];
            }
            else
                j++;
        }
    }
    return cnt;
}