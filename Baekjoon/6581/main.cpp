#include <iostream>
#include <cstring>

int main() {
    char w[81];
    int cnt = 0;
    char br[] = "<br>";
    char hr[] = "<hr>";
    while (fscanf(stdin, " %s", w) != EOF) {
        if (strcmp(w, br) == 0) {
            printf("\n");
            cnt = 0;
        }
        else if (strcmp(w, hr) == 0) {
            if (cnt != 0)
                printf("\n");
            for (int i = 0; i < 80; ++i) {
                printf("-");
            }
            printf("\n");
            cnt = 0;
        }
        else {
            int len = strlen(w);
            if (cnt + len > 80) {
                cnt = 0;
                printf("\n");
            }
            else if (cnt != 0)
                printf(" ");
            cnt += (len + 1);
            printf("%s", w);
        }
    }

    return 0;
}
