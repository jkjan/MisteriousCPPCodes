#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int tokenizer(string sik);

int main() {
    string sik;
    cin >> sik;
    cout << tokenizer(sik);
    return 0;
}

int tokenizer(string sik) {
    int answer = 0;
    int num = 0;
    bool bracketOpened = false;
    for (int i = 0; i < sik.size(); i++) {
        if (isdigit(sik[i])) {
            num += (sik[i] - '0');
            num *= 10;
        }
        if (!isdigit(sik[i]) || i == (sik.size() - 1)) {
            num /= 10;
            answer = answer + (bracketOpened ? -1 : 1) * num;
            if (sik[i] == '-' && !bracketOpened)
                bracketOpened = true;
            num = 0;
        }
    }
    return answer;
}