#include <iostream>
using namespace std;
int main() {
    int mushroom[10];
    int lessThan = 0;
    int i;
    int greaterThan = 0;
    for (i = 0; i < 10; i++) {
        cin >> mushroom[i];
        if (lessThan + mushroom[i] >= 100) {
            greaterThan = lessThan + mushroom[i];

            if (greaterThan == 100) {
                cout << 100 << endl;
            }

            else if (100 - lessThan > greaterThan - 100) {
                cout << greaterThan << endl;
            }

            else if (100 - lessThan < greaterThan - 100) {
                cout << lessThan << endl;
            }

            else if (100 - lessThan == greaterThan - 100) {
                cout << greaterThan << endl;
            }

            return 0;
        }
        lessThan += mushroom[i];
    }
    cout << lessThan << endl;

    return 0;
}
