#include <iostream>

using namespace std;

void input(int*);
double getAverage(const int* scores);

int main() {
    int scores[5];
    input(scores);
    cout << getAverage(scores);
    return 0;
}

void input(int* scores) {
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
        if (scores[i] < 40)
            scores[i] = 40;
    }
}

double getAverage(const int* scores) {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += scores[i];
    }
    return sum/5;
}