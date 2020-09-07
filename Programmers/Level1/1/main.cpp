#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

void change(string* word) {
    int cnt = 0;
    for (int i = 0; i < word->length(); i++) {
        if (cnt%2)
            word->at(i) = tolower(word->at(i));
        else
            word->at(i) = toupper(word->at(i));
        if (isalpha(word->at(i)))
            cnt++;
    }
}

string solution(string s) {
    string answer;
    string word;
    stringstream tokenizer(s);
    while (getline(tokenizer, word, '')){
        change(&word);
        answer += (word + " ");
    }
    return answer.substr(0, answer.length()-1);
}

int main() {
    cout << solution("");
    return 0;
}