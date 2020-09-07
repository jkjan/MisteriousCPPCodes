#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int a[2048][2048];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] == 0 || a[i][k] == 0 || a[j][k] == 0)continue;
                if (a[i][j] + a[i][k] <= a[j][k])a[j][k] = 0;
                else if (a[i][j] + a[j][k] <= a[i][k])a[i][k] = 0;
                else if (a[i][k] + a[j][k] <= a[i][j])a[i][j] = 0;
            }

    vector<int> res[1024];
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][j] != 0) {
                res[i].push_back(j + 1);
                res[j].push_back(i + 1);
            }
    for (int i = 0; i < n; i++) {
        sort(res[i].begin(), res[i].end());
        int t = res[i].size();
        cout << t << " ";
        for (int j = 0; j < t - 1; j++)cout << res[i][j] << " ";
        cout << res[i][t - 1] << endl;
    }
    return 0;
}