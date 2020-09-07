#include <iostream>
using namespace std;

int main() {
    int date;
    int cars[5];
    int cnt = 0;
    cin >> date;
    for (int & car : cars) {
        cin >> car;
        if (car == date)
            cnt++;
    }
    cout << cnt;
    return 0;
}
