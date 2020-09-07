#include <iostream>
#include <vector>
#include <fstream>
#define TOP 0
#define BOTTOM 1
#define MAX_HEIGHT 10
#define MAX_WIDTH 100
using namespace std;
int n, w, b;

void tc();
void stackNewDeco(int* top, int* height, vector<int>* boxes);

int main() {
    tc();
}

void tc() {
    scanf(" %d %d %d", &n, &w, &b);
    int top[MAX_WIDTH] = {0, };
    int height = 0;
    vector<int> boxes;
    for (int i = 0; i < n; ++i) {
        stackNewDeco(top, &height, &boxes);
    }
    if (height != 0)
        boxes.push_back(height);
    for (auto box : boxes) {
        printf("%d ", box);
    }
    printf("\n");
}

int getNewDeco(int newDeco[][MAX_WIDTH]) {
    int h;
    scanf(" %d", &h);
    fill(newDeco[TOP], newDeco[TOP] + MAX_WIDTH, MAX_HEIGHT+1);
    fill(newDeco[BOTTOM], newDeco[BOTTOM] + MAX_WIDTH, MAX_HEIGHT+1);
    char deco;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf(" %c", &deco);
            if (deco == 'X') {
                newDeco[TOP][j] = min(newDeco[TOP][j], i);
                newDeco[BOTTOM][j] = min(newDeco[BOTTOM][j], h - 1 - i);
            }
        }
    }
    return h;
}

void move(int original, int* height, int h, vector<int>* boxes) {
    if (*height >= b) {
        if (*height > b) {
            boxes->push_back(*height - h);
            *height = original;
        }
        else {
            boxes->push_back(b);
            *height = 0;
        }
    }
}

int getMostPushableHeight(int* top, int* bottom) {
    int mostPushableHeight = MAX_HEIGHT * 2;
    for (int i = 0; i < w; ++i) {
        mostPushableHeight = min(mostPushableHeight, top[i] + bottom[i]);
    }
    return mostPushableHeight;
}

void newTop(int* arr1, const int* arr2, int addedHeight) {
    for (int i = 0; i < MAX_WIDTH; ++i) {
        if (arr2[i] == MAX_HEIGHT+1)
            arr1[i] = addedHeight + arr1[i];
        else
            arr1[i] = arr2[i];
    }
}

void stackNewDeco(int* top, int* height, vector<int>* boxes) {
    int newDeco[2][MAX_WIDTH];
    int h = getNewDeco(newDeco);
    int mostPushableHeight = getMostPushableHeight(top, newDeco[BOTTOM]);
    int addedHeight = (h - mostPushableHeight);

    if (addedHeight > 0) {
        *height += addedHeight;
        move(h, height, addedHeight, boxes);
        newTop(top, newDeco[TOP], addedHeight);
    }

    else {
        for (int i = 0; i < MAX_WIDTH; ++i) {
            int decoHeight = h - newDeco[TOP][i] - newDeco[BOTTOM][i];
            decoHeight = (decoHeight > 0 ? decoHeight : 0);
            top[i] -= decoHeight;
        }
    }
}