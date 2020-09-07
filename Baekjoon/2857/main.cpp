#include <iostream>
#include <vector>
#include <string>
using namespace std;

int kmp(string str, string p);

int main() {
    string agent;
    vector<short> indices;
    for (int i = 1; i <= 5; ++i) {
        cin >> agent;
        if (kmp(agent, "FBI"))
            indices.push_back(i);
    }
    if (indices.empty())
        cout << "HE GOT AWAY!";
    else {
        for (auto i : indices)
            cout << i << " ";
    }
    return 0;
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
    for (int i = 0; i < sLen; i++) {
        while (j > 0 && str[i] != p[j])
            j = pi[j-1];
        if (str[i] == p[j]) {
            if (j == pLen - 1)
                return true;
            else
                j++;
        }
    }
    return false;
}