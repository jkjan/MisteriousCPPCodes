#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[101][101];
string combination(int n, int m);

int main() {
    dp[0][0] = "1";
    dp[1][0] = "1";
    int n, m;
    scanf(" %d %d", &n, &m);
    cout << combination(n, m);
    return 0;
}

void operate(string a, int aIndex, string b, int bIndex, string* ret, int* carry, int(*operate)(int, int)) {
    int aN = aIndex >= 0 ? a[aIndex] - '0' : 0;
    int bN = bIndex >= 0 ? b[bIndex] - '0' : 0;
    int n = operate(aN, bN);
    ret->push_back(((n%10 + *carry)%10) + '0');
    *carry = (n + *carry)/10;
}

string operator+(const string& a, const string& b) {
    string ret;
    int carry = 0;
    int aIndex = (int)(a.length()) - 1;
    int bIndex = (int)(b.length()) - 1;
    while (aIndex >= 0 || bIndex >= 0) {
        operate(a, aIndex, b, bIndex, &ret, &carry, [](int a, int b){return a+b;});
        aIndex--; bIndex--;
    }
    if (carry)
        ret.push_back(carry + '0');
    if (ret[ret.length()-1] == '0')
        ret.pop_back();
    reverse(ret.begin(), ret.end());
    return ret;
}

string combination(int n, int m) {
    if (m > n/2)
        m = n - m;
    else if (n == m || (n <= 0 || m <= 0))
        return "1";
    else if (n < m)
        return "0";
    if (dp[n][m].empty()) {
        string a = combination(n-1, m-1);
        string b = combination(n-1, m);
        dp[n][m] = a + b;
    }
    return dp[n][m];
}