#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node* next;
} Node;

typedef struct myQueue {
    Node* queue;
    Node* head;
    Node* tail;
    int cnt;
} MyQueue;

void init(MyQueue* this) {
    Node *init = (Node*)malloc(sizeof(Node));
    init->num = -1;
    init->next = NULL;
    this->queue = init;
    this->head = this->queue;
    this->tail = this->queue;
    this->cnt = 0;
}

void push(MyQueue* this, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = x;
    newNode->next = NULL;
    this->tail->next = newNode;
    this->tail = newNode;
    this->cnt++;
}

int pop(MyQueue* this) {
    if (this->cnt == 0)
        return -1;
    int front = this->head->next->num;
    Node* willBeRemoved = this->head->next;
    this->head->next = this->head->next->next;
    this->cnt--;
    if (this->cnt == 0)
        init(this);
    free(willBeRemoved);
    return front;
}

int size(MyQueue* this) {
    return this->cnt;
}

int empty(MyQueue* this) {
    return this->cnt == 0;
}

int front(MyQueue* this) {
    return this->cnt == 0 ? -1 : this->head->next->num;
}

int back(MyQueue* this) {
    return this->cnt == 0 ? -1 : this->tail->num;
}

int main() {
    MyQueue myQueue;
    init(&myQueue);
    int N;
    char command[6];
    int arg;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %s", command);
        if (strcmp(command, "push") == 0) {
            scanf("%d", &arg);
            push(&myQueue, arg);
        }
        else if (strcmp(command, "front") == 0)
            printf("%d\n", front(&myQueue));
        else if (strcmp(command, "back") == 0)
            printf("%d\n", back(&myQueue));
        else if (strcmp(command, "size") == 0)
            printf("%d\n", size(&myQueue));
        else if (strcmp(command, "empty") == 0)
            printf("%d\n", empty(&myQueue));
        else if (strcmp(command, "pop") == 0)
            printf("%d\n", pop(&myQueue));
    }

    return 0;
}