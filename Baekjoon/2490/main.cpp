#include <iostream>

using namespace std;

void input(bool*);
char getResult(bool*);

int main() {
    bool yut[4];
    for (int i = 0; i < 3; i++) {
        input(yut);
        cout << getResult(yut) << endl;
    }
    return 0;
}

void input(bool* yut) {
    for (int i = 0; i < 4; i++)
        cin >> yut[i];
}

char getResult(bool* yut) {
    int front;
    front = 0;
    for(int i = 0; i < 4; i++) {
        front += yut[i];
    }
    return front == 4 ? 'E' : (68 - front);
}
