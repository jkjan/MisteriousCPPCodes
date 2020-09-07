#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream tokenizer(s);
    vector<int> arr;
    string num;
    while (getline(tokenizer, num, ' ')) {
        if (num.length() > 0) {
            arr.push_back(stoi(num));
        }
    }
    sort(arr.begin(), arr.end());
    answer += to_string(arr.front());
    answer += " ";
    answer += to_string(arr.back());
    return answer;
}

int main() {
    cout << solution("-1 -2 -3 -4");
    return 0;
}
