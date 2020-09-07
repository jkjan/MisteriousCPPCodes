#include <iostream>
#include <algorithm>
#define MAX_SIZE 100002
using namespace std;

int preOrder[MAX_SIZE];
void getPostOrder(int start, int end);

int main() {
    int i = 0;
    int num;
    while (scanf(" %d", &num) != -1) {
        preOrder[i++] = num;
    }
    getPostOrder(0, i);
    return 0;
}

void getPostOrder(int start, int end) {
    if(start >= end)
        return; 
    int upperIndex = distance(preOrder, upper_bound(preOrder+start+1, preOrder + end, preOrder[start]));
    getPostOrder(start + 1, upperIndex);
    getPostOrder(upperIndex, end);
    printf("%d\n", preOrder[start]); 
}
