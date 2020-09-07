#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> possibleQuery;
string wildcard(10000, '?');

void doingForward(string* word) {
    for (int i = 0; i <= word->length(); ++i) {
        string q = wildcard.substr(0, i);
        q += word->substr(i);
        possibleQuery[q]++;
    }
}

void doingBackward(string* word) {
    for (int i = 1; i < word->length(); ++i) {
        string q = word->substr(0, i);
        q += wildcard.substr(0, word->length()-i);
        possibleQuery[q]++;
    }
}

void makeQuery(string* word) {
    doingForward(word);
    doingBackward(word);
}

vector<int> solution(vector<string> words, vector<string> queries) {
    for (auto word : words) {
        makeQuery(&word);
    }
    vector<int> answer(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
        answer[i] = possibleQuery[queries[i]];
    }
    return answer;
}

int main() {
    vector<string> words = {
            "frodo", "front", "frost", "frozen", "frame", "kakao"
    };
    vector<string> queries = {
            "fro??", "????o", "fr???", "fro???", "pro?"
    };
    auto answer = solution(words, queries);
    for (auto a : answer)
        cout << a << " ";
    return 0;
}