#include <iostream>
#include <string>
#include <vector>
#define MAX_SIZE 300
using namespace std;

int countGroups(vector<string> related);

int main() {
    vector<string> related;
    related.push_back("1000001000");
    related.push_back("0100010001");
    related.push_back("0010100000");
    related.push_back("0001000000");
    related.push_back("0010100000");
    related.push_back("0100010000");
    related.push_back("1000001000");
    related.push_back("0000000100");
    related.push_back("0000000010");
    related.push_back("0100000001");
    printf("%d", countGroups(related));
    return 0;
}

void dfs(int n, vector<string>* related, bool* visited) {
    visited[n] = true;
    int size = related->at(n).length();
    for (int i = 0; i < size; i++) {
        if (related->at(n)[i] == '1' && i != n) {
            if (!visited[i]) {
                dfs(i, related, visited);
            }
        }
    }
}

int countGroups(vector<string> related) {
    int cnt = 0;
    int n = related.size();
    bool visited[MAX_SIZE] = {false, };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, &related, visited);
            cnt++;
        }
    }
    return cnt;
}