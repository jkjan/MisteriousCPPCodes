#include <iostream>
#include <algorithm>
#define MAX_SIZE 100000
typedef struct pos {
    int x, y;
}pos;
int main() {
    int N;
    pos list[MAX_SIZE];
    scanf(" %d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %d %d", &(list[i].x), &(list[i].y));
    }
    std::sort(list, list+N, [](pos a, pos b){
        return (a.y == b.y ? a.x < b.x : a.y < b.y);
    });
    for (int i = 0; i < N; i++)
        printf("%d %d\n", list[i].x, list[i].y);
    return 0;
}