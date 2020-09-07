#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int months[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for (int i = 1; i < a; ++i) {
        days += months[i];
    }
    days += (b - 1);
    string dayName[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    return dayName[days%7];
}

int main() {
    double A,B;
    scanf(" %lg %lg",&A,&B);
    printf("%.9g",A/B);
    return 0;
}
