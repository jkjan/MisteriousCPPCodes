#include <iostream>
#include <vector>
#include <map>
#define L true
#define R false

using namespace std;

typedef struct node {
    char alpha;
    node* l;
    node* r;
} node;

class tree {
private:
    node** possibleRoots;

    void connect(node* subRoot, char X, bool isL) {
        if (X != '.') {
            node* child = this->pack(X);
            (isL ? subRoot->l : subRoot->r) = child;
        }
    }

    void preOrder(node* now) {
        if (now == nullptr)
            return;
        printf("%c", now->alpha);
        preOrder(now->l);
        preOrder(now->r);
    }

    void inOrder(node* now) {
        if (now == nullptr)
            return;
        inOrder(now->l);
        printf("%c", now->alpha);
        inOrder(now->r);
    }

    void postOrder(node* now) {
        if (now == nullptr)
            return;
        postOrder(now->l);
        postOrder(now->r);
        printf("%c", now->alpha);
    }

    node* pack(char X) {
        node* now = this->possibleRoots[X-'A'];
        if (now == nullptr) {
            now = new node;
            now->l = now->r = nullptr;
            now->alpha = X;
            this->possibleRoots[X-'A'] = now;
        }
        return now;
    }

public:
    tree() {
        this->possibleRoots = new node*[26];
        fill(this->possibleRoots, this->possibleRoots+26, nullptr);
    }

    ~tree() {
        delete [] this->possibleRoots;
    }

    void insert(char A, char B, char C) {
        node* subRoot = this->pack(A);
        this->connect(subRoot, B, L);
        this->connect(subRoot, C, R);
    }

    void preOrder() {
        this->preOrder(this->possibleRoots[0]);
    }

    void inOrder() {
        this->inOrder(this->possibleRoots[0]);
    }

    void postOrder() {
        this->postOrder(this->possibleRoots[0]);
    }
};

void input(tree* myTree);

int main() {
    tree myTree;
    input(&myTree);
    myTree.preOrder();
    printf("\n");
    myTree.inOrder();
    printf("\n");
    myTree.postOrder();
    return 0;
}

void input(tree* myTree) {
    int N;
    char A, B, C;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %c %c %c", &A, &B, &C);
        myTree->insert(A, B, C);
    }
}