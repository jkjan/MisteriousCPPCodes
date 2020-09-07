#include <iostream>
#include <string>
using namespace std;
typedef unsigned short us;
string A, B;
us getDiff(int i);

int main() {
    cin >> A >> B;
    us minDiff = 51;
    us lenDiff = B.length() - A.length();
    for (int i = 0; i <= lenDiff; ++i)
        minDiff = min(minDiff, getDiff(i));
    cout << minDiff;
    return 0;
}

us getDiff(int i) {
    us cnt = 0;
    for (auto cA : A)
        cnt += cA != B[i++];
    return cnt;
}