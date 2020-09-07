#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    int where;
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            where = i;
            break;
        }
    }
    return "김서방은 " + to_string(where) + "에 있다";
}

int main() {
    return 0;
}
