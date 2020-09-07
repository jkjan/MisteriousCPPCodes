#include <iostream>
using namespace std;
int main() {
    int N;
    int temp;
    int cute = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        cute += temp;
    }
    cout << "Junhee is " << ((cute > N/2) ? "" : "not ") << "cute!" << endl;
    return 0;
}
