#include <iostream>
#include <cmath>
using namespace std;

int size;
int* segTree;
int* rangeBits;
int N;
int start;
int leaves;

void initializeTree();
int buildTree(int index);
void change(int index, int value);

int main() {
    int M, K;
    cin >> N >> M >> K;
    leaves = pow(2, int(log(N)/log(2)) + 1);
    size = leaves * 2 - 1;
    cout << "leaves : " << leaves << ", size : " << size << endl;
    start = size - leaves + 1;
    segTree = new int[size+1];
    rangeBits = new int[size+1];

    initializeTree();
    buildTree(1);

    for (int i = 1; i <= size; i++) {
        cout << segTree[i] << "  ";
    }
    cout << endl;
    change(3, 6);

    for (int i = 1; i <= size; i++) {
        cout << segTree[i] << "  ";
    }

    delete [] segTree;
    return 0;
}

int bitMaker(int from, int to) {
    int s = pow(2, leaves - from);
    int bits = 0;
    for (int i = 0; i < from - to + 1; i++) {
        bits += s;
        s /= 2;
    }
    return bits;
}

void initializeTree() {
    int i;
    int index = 1;
    for (i = start; i < start + N; i++) {
        cin >> segTree[i];
        rangeBits[i] = bitMaker(index, index);
        index++;
    }
    for (i = start + N; i <= size; i++) {
        segTree[i] = 0;
        rangeBits[i] = bitMaker(index, index);
        index++;
    }
}

int buildTree(int index) {
    if (index * 2 > size) {
        return segTree[index];
    }
    segTree[index] = buildTree(index * 2) + buildTree(index * 2 + 1);
    rangeBits[index] = rangeBits[index * 2] | rangeBits[index * 2 + 1];
    return segTree[index];
}

void change(int index, int value) {
    int segIndex = start + index - 1;
    int feature = value - segTree[segIndex];
    for (int i = segIndex; i >= 1; i /= 2) {
        segTree[i] += feature;
    }
}