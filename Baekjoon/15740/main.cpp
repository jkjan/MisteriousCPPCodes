#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int toNum(char a) {
    return a - '0';
}

char toChar(uint n) {
    return (char)(n + '0');
}

string operator-(string a, string b);

void operate(string a, int aIndex, string b, int bIndex, string* ret, int* carry, int(*operate)(int, int)) {
    int aN = aIndex >= 0 ? toNum(a[aIndex]) : 0;
    int bN = bIndex >= 0 ? toNum(b[bIndex]) : 0;
    int n = operate(aN, bN);
    ret->push_back(toChar((n%10 + *carry)%10));
    *carry = (n + *carry)/10;
}

string operator+(string a, string b) {
    if (a == "0" && b == "0")
        return "0";
    bool minus = false;
    if (a[0] == '-') {
        if (b[0] != '-')
            return b-a.substr(1);
        else if (b[0] == '-') {
            a = a.substr(1);
            b = b.substr(1);
            minus = true;
        }
    }
    else if (b[0] == '-') {
        return a-b.substr(1);
    }

    string ret;
    int carry = 0;
    int aIndex = (int)(a.length()) - 1;
    int bIndex = (int)(b.length()) - 1;
    while (aIndex >= 0 || bIndex >= 0) {
        operate(a, aIndex, b, bIndex, &ret, &carry, [](int a, int b){return a+b;});
        aIndex--; bIndex--;
    }
    if (carry)
        ret.push_back(toChar(carry));
    if (ret[ret.length()-1] == '0')
        ret.pop_back();
    if (minus)
        ret.push_back('-');
    reverse(ret.begin(), ret.end());
    return ret;
}

string getComplement(int digit, string a) {
    string complement;
    string one = "1";
    int aIndex = (int)a.length()-1 ;
    int diff = digit - aIndex;
    for (int i = 0; i < diff; i++) {
        complement.push_back('9');
    }
    for (int i = 0; i <= aIndex; i++) {
        complement.push_back(toChar(9 - toNum(a[i])));
    }
    complement = complement + one;
    return complement;
}

bool operator<(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else {
        int i = 0;
        while (i < a.length()) {
            if (a[i] != b[i])
                return a[i] < b[i];
            i++;
        }
    }
    return false;
}

string operator-(string a, string b) {
    bool minus = false;
    if (a < b) {
        minus = true;
        swap(a, b);
    }
    int aIndex = (int)a.length()-1;
    int bIndex = (int)b.length()-1;
    int digit = max(aIndex, bIndex);
    string complement = getComplement(digit, b);
    string ret = a + complement;
    int pos = 1;
    while (ret[pos++] == '0' && pos < ret.length());
    ret = ret.substr(pos-1);
    if (minus) {
        reverse(ret.begin(), ret.end());
        ret.push_back('-');
        reverse(ret.begin(), ret.end());
    }
    return ret;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}