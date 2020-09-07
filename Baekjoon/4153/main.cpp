#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isRightTriangle(int* triangle);

int main() {
    int triangle[3];
    while (true) {
        cin >> triangle[0] >> triangle[1] >> triangle[2];
        if (triangle[0] == triangle[1] && triangle[1] == triangle[2] && triangle[2] == 0) {
            break;
        }
        sort(triangle, triangle+3);
        cout << (isRightTriangle(triangle) ? "right" : "wrong") << endl;
    }
    return 0;
}

bool isRightTriangle(int* triangle) {
    return (pow(triangle[0], 2) + pow(triangle[1], 2) == pow(triangle[2], 2));
}

