#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Node {
public:
    int num;
    Node* next;
    Node* prev;
    Node() = default;
};

class MyDeq {
public:
    Node* head;
    Node* tail;
    int cnt;
    MyDeq() = default;
    void init();
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    int size();
    bool empty();
    int front();
    int back();
};

void MyDeq::init() {
    this->head = new Node;
    this->head->num = -1;
    this->head->next = nullptr;

    this->tail = new Node;
    this->tail->num = -1;
    this->tail->prev = nullptr;
    this->cnt = 0;
}

void MyDeq::push_front(int x) {
    Node* newNode = new Node;
    newNode->num = x;
    newNode->next = this->head->next;
    newNode->prev = this->head;
    if (this->head->next != NULL) {
        this->head->next->prev = newNode;
    }
    else {
        this->tail->prev = newNode;
        newNode->next = this->tail;
    }
    this->head->next = newNode;
    this->cnt++;
}

void MyDeq::push_back(int x) {
    Node* newNode = new Node;
    newNode->num = x;
    newNode->next = this->tail;
    newNode->prev = this->tail->prev;
    if (this->tail->prev != NULL) {
        this->tail->prev->next = newNode;
    }
    else {
        this->head->next = newNode;
        newNode->prev = this->head;
    }
    this->tail->prev = newNode;
    this->cnt++;
}

int MyDeq::pop_front() {
    if (this->cnt == 0)
        return -1;
    int front = this->head->next->num;
    Node* willBeRemoved = this->head->next;
    this->head->next = willBeRemoved->next;
    willBeRemoved->next->prev = this->head;
    this->cnt--;
    delete [] willBeRemoved;
    return front;
}

int MyDeq::pop_back() {
    if (this->cnt == 0)
        return -1;
    int back = this->tail->prev->num;
    Node* willBeRemoved = this->tail->prev;
    this->tail->prev = willBeRemoved->prev;
    willBeRemoved->prev->next = this->tail;
    this->cnt--;
    delete [] willBeRemoved;
    return back;
}

int MyDeq::size() {
    return this->cnt;
}

bool MyDeq::empty() {
    return this->cnt == 0;
}

int MyDeq::front() {
    return this->cnt == 0 ? -1 : this->head->next->num;
}

int MyDeq::back() {
    return this->cnt == 0 ? -1 : this->tail->prev->num;
}

int main() {
    MyDeq myQueue{};
    myQueue.init();
    int N;
    char command[100];
    int arg;

    cin >> N;

    for (int i = 0; i < N; i++) {
        scanf(" %s", command);
        if (strcmp(command, "push_front") == 0) {
            scanf("%d", &arg);
            myQueue.push_front(arg);
        }
        else if (strcmp(command, "push_back") == 0) {
            scanf("%d", &arg);
            myQueue.push_back(arg);
        }
        else if (strcmp(command, "front") == 0)
            printf("%d\n", myQueue.front());
        else if (strcmp(command, "back") == 0)
            printf("%d\n", myQueue.back());
        else if (strcmp(command, "size") == 0)
            printf("%d\n", myQueue.size());
        else if (strcmp(command, "empty") == 0)
            printf("%d\n", myQueue.empty());
        else if (strcmp(command, "pop_front") == 0)
            printf("%d\n", myQueue.pop_front());
        else if (strcmp(command, "pop_back") == 0)
            printf("%d\n", myQueue.pop_back());
    }
    return 0;
}
