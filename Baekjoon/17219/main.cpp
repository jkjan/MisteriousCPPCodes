#include <iostream>
#include <map>
#include <vector>
using namespace std;

void input();
void output();
map<string, string> memo;
vector<string> req;

int main() {
    input();
    output();
    return 0;
}

void input() {
    int N, M;
    scanf(" %d %d", &N, &M);
    string site, password;
    for (int i = 0; i < N; ++i) {
        cin >> site >> password;
        memo.insert({site, password});
    }
    for (int j = 0; j < M; ++j) {
        cin >> site;
        req.push_back(site);
    }
}

void output() {
    for (const auto& r : req) {
        cout << memo[r] << endl;
    }
}