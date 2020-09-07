#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M;
    set<string> neverHeard;
    set<string> neverHeardAndSeen;
    string temp;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        neverHeard.insert(temp);
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (neverHeard.count(temp)) {
            neverHeardAndSeen.insert(temp);
        }
    }
    cout << neverHeardAndSeen.size() << endl;
    for (const auto & itor : neverHeardAndSeen) {
        cout << itor << endl;
    }
    return 0;
}
