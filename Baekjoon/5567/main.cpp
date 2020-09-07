#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000

using namespace std;

void input(vector<int>*, int, int);
int getInvitedFriends(vector<int>*, int);

int main() {
    int n, m; // 동기 수, 동기 리스트 길이
    cin >> n >> m;
    vector<int> friends[n+1];
    input(friends, n, m);
    cout << getInvitedFriends(friends, n);
    return 0;
}

void input(vector<int>* friends, int n, int m) {
    int a, b; // 친구 a, b
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
}

int getInvitedFriends(vector<int>* friends, int n) {
    queue<int> willVisit;
    int nowVisit;
    int cnt = 0;

    int* distance = new int[n+1];
    bool* visited = new bool[n+1];

    for(int i = 2; i <= n; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[1] = 0; // 상근이는 1
    visited[1] = true;
    willVisit.push(1);

    while (!willVisit.empty()) {
        nowVisit = willVisit.front();
        willVisit.pop();
        for (auto itor = friends[nowVisit].begin(); itor != friends[nowVisit].end(); ++itor) {
            if (distance[nowVisit] >= 2)
                break;

            if (!visited[*itor]) {
                distance[*itor] = distance[nowVisit] + 1;
                willVisit.push(*itor);
                cnt++;
                visited[*itor] = true;
            }
        }
    }

    delete [] distance;
    delete [] visited;

    return cnt;
}
