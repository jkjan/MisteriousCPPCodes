#include <iostream>

int main() {
    short stu;
    bool submitted[31] = {false, };
    for (int i = 0; i < 28; ++i) {
        scanf(" %hd", &stu);
        submitted[stu] = true;
    }
    for (int i = 1; i <= 30; ++i) {
        if (!submitted[i])
            printf("%d\n", i);
    }
    return 0;
}
