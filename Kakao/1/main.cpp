#include <iostream>
#include <cmath>
using namespace std;

int getExtracted(string s, int n);

int solution(string s) {
    int cnt = 1001;
    if (s.length() == 1)
        return 1;
    for (int i = 1; i <= s.length()/2; i++) {
        int extracted = getExtracted(s, i);
        cnt = min(cnt, extracted);
    }
    return cnt;
}

int getExtracted(string s, int n) {
    int t, a, i, cnt, len;
    t = a = len = 0;
    cnt = 1;
    while (a + n < s.length()) {
        a += n;
        for (i = 0; i < n && a + i < s.length(); i++) {
            if (s[t + i] != s[a + i])
                break;
        }
        if (i != n) {
            t = a;
            if (cnt > 1)
                len += (int)log10(cnt) + 1;
            len += n;
            cnt = 1;
        }
        else
            cnt++;
    }
    if (cnt > 1) {
        len += (int)log10(cnt) + 1;
        len += n;
    }
    else {
        len += (s.length() - a);
    }
    return len;
}