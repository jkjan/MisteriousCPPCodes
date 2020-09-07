#include <iostream>
#define MAX_SIZE 100001

using namespace std;
int n;

int inOrder[MAX_SIZE];
int postOrder[MAX_SIZE];
void input();
void getPreOrder(int inBegin, int inEnd, int postBegin, int postEnd);

int main() {
    input();
    getPreOrder(0, n-1, 0, n-1);
    return 0;
}

void inputArr(int* arr) {
    for (int i = 0; i < n; ++i) {
        scanf(" %d", arr + i);
    }
}

void input() {
    scanf(" %d", &n);
    inputArr(inOrder);
    inputArr(postOrder);
}

void getPreOrder(int inBegin, int inEnd, int postBegin, int postEnd) {
    if (inBegin == inEnd) {
        printf("%d ", inOrder[inBegin]);
        return;
    }

    int i;
    int root = postOrder[postEnd];
    for (i = inBegin; i <= inEnd; i++) {
        if (inOrder[i] == root)
            break;
    }

    printf("%d ", root);
    int left = i - inBegin - 1;
    if (inBegin < i) {
        getPreOrder(inBegin, i-1, postBegin, postBegin + left);
    }

    int right = inEnd - i;
    if (i < inEnd) {
        getPreOrder(i+1, inEnd, postEnd - right, postEnd-1);
    }
}