#include <iostream>

template<typename ty>
struct node {
    ty data;
    node* prev;
    node* next;
};

template<typename ty>
class deque {
    int size;
    node<ty>* head;
    node<ty>* tail;

    node<ty>* nodeInit(ty data) {
        auto newNode = new node<ty>;
        *newNode = {data, nullptr, nullptr};
        return newNode;
    }

    void init() {
        head->next = tail;
        tail->prev = head;
    }

public:
    deque() : head(nodeInit(NULL)), tail(nodeInit(NULL)), size(0) {
        init();
    }

    void push_front(ty data) {
        auto newNode = nodeInit(data);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        size++;
    }

    void push_back(ty data) {
        auto newNode = nodeInit(data);
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
        size++;
    }

    void pop_front() {
        auto deletedNode = head->next;
        head->next->next->prev = head;
        head->next = head->next->next;
        delete deletedNode;
        size--;
    }

    void pop_back() {
        auto deletedNode = tail->prev;
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        delete deletedNode;
        size--;
    }

    ty front() {
        return head->next->data;
    }

    ty back() {
        return tail->prev->data;
    }

    int distFromFront(ty data) {
        int dist = 0;
        node<ty>* i = head->next;
        while (i->data != data) {
            dist++;
            i = i->next;
        }
        return dist;
    }

    int distFromBack(ty data) {
        int dist = 0;
        node<ty>* i = tail->prev;
        while (i->data != data) {
            dist++;
            i = i->prev;
        }
        return dist;
    }
};

deque<int> test;
int op2cnt = 0, op3cnt = 0;

template<typename ty>
void pop(ty n);

int main() {
    int N, M, wishList[50];
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        test.push_back(i);
    }

    for (int i = 0; i < M; ++i) {
        scanf(" %d", wishList + i);
    }
    for (int i = 0; i < M; ++i) {
        pop(wishList[i]);
    }

    printf("%d", op2cnt + op3cnt);

    return 0;
}

void op2() {
    int data = test.front();
    test.pop_front();
    test.push_back(data);
    op2cnt++;
}

void op3() {
    int data = test.back();
    test.pop_back();
    test.push_front(data);
    op3cnt++;
}

void pop(int times, void(*op)()) {
    for (int i = 0; i < times; ++i) {
        op();
    }
    test.pop_front();
}

template <typename ty>
void pop(ty n) {
    int fromFront = test.distFromFront(n);
    int fromBack = test.distFromBack(n);
    if (fromBack < fromFront) {
        pop(fromBack + 1, op3);
    }
    else {
        pop(fromFront, op2);
    }
}
