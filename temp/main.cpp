#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    string candidate[] = {"교준", "형범", "준영", "정인", "지현"};
    srand(time(NULL));
    int who = rand()%5;
    cout << "다음 주 선생님은 " << candidate[who] << "입니다." << endl;
    return 0;
}
