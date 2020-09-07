#include <iostream>
#include <vector>
using namespace std;

int N;

int getDiff(int a, int b) {
    if (a < b)
        return b - a;
    else
        return N - a + b;
}

vector<int> getDiff(vector<int>* weak) {
    vector<int> diff(weak->size()-1);
    for (int i = 0; i < weak->size() - 1; ++i) {
        diff[i] = getDiff(weak->at(i), weak->at(i+1));
    }
    return diff;
}

void rotate(vector<int>* weak) {
    int last = weak->back();
    for (int i = weak->size()-1; i >= 1; i--) {
        weak->at(i) = weak->at(i-1);
    }
    weak->at(0) = last;
}

int cover(int n, vector<int>* distMap) {
    for (int i = n; i <= 200; i++) {
        if (distMap->at(i) > 0)
            return i;
    }
    return -1;
}

int sendEm(vector<int>* weak, vector<int>* dist) {
    auto diff = getDiff(weak);
    for (auto d : diff)
        cout << d << " ";
    cout << endl;
    vector<int> distMap(201, 0);

    for (int d : *dist) {
        distMap[d]++;
    }
    int i = 0;
    int cnt = 0;
    int fixed = 0;
    while (true) {
        if (i >= diff.size()) {
            if (dist->size() - cnt > 0) {
                cnt++;
            }
            break;
        }
        if (cover(diff[i], &distMap) == -1) {
            if (weak->size()-fixed > dist->size() + cnt)
                return 9;
            else
                return cnt + weak->size()-fixed;
        }
        int sum = diff[i];
        fixed+=2;
        cnt++;

        do {
            sum += diff[++i];
            fixed++;
        } while (cover(sum, &distMap) != -1 && i < diff.size());

        if (i < diff.size()) {
            sum -= diff[i];
            fixed--;
            distMap[cover(sum, &distMap)]--;
            i++;
        }
        else
            break;
    }
    cout << "cnt : " << cnt << endl;
    return cnt;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;
    N = n;

    for (int i = 0; i < weak.size(); ++i) {
        for (auto w : weak)
            cout << w << " ";
        cout << endl;
        answer = min(answer, sendEm(&weak, &dist));
        if (answer == 1)
            return 1;
        rotate(&weak);
    }

    if (answer != 9) {
        if (answer > dist.size())
            return -1;
        else
            return answer;
    }
    else if (dist.size() >= weak.size())
        return weak.size();
    else
        return -1;
}

int main() {
    int n = 200;
    vector<int> weak = {10, 20, 30, 40, 50, 60};
    vector<int> dist = {1, 1, 1, 1, 1, 1};
    cout << solution(n, weak, dist);
    return 0;
}