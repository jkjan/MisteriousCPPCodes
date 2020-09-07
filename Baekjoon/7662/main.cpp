#include <iostream>
#include <cmath>
#include <limits>
#define MAX_SIZE 1048576

void tc();
long input();

int main() {
    int t = (int)input();
    for (int i = 0; i < t; i++) {
        tc();
    }
    return 0;
}

template<typename T>
class minMaxHeap {
private:
    int size;
    T* heap;

    static bool min(T a, T b) {
        return a < b;
    }

    static bool max(T a, T b) {
        return a > b;
    }

    int level(int i) {
        return (int)(log(i)/log(2));
    }

    bool isMin(int i) {
        return (level(i) % 2 == 0);
    }

    void pushDown(int i) {
        pushDownImpl(i, this->isMin(i));
    }

    void getChild(T* s, int* si, int start, int cnt, bool(*compare)(T, T)) {
        for (int j = 0; j < cnt; j++) {
            if (compare(this->heap[start], *s) && start <= this->size) {
                *s = this->heap[start];
                *si = start;
            }
            start++;
        }
    }

    int getChild(int i, bool isMin) {
        bool(*compare)(T, T) = isMin ? min : max;
        T s = isMin ? std::numeric_limits<T>::max() : std::numeric_limits<T>::min();
        int si = -1;
        int i2 = i*2;
        int i4 = i*4;
        getChild(&s, &si, i2, 2, compare);
        getChild(&s, &si, i4, 4, compare);
        return si;
    }

    void pushDownImpl(int i, bool isMin) {
        if (i*2 <= this->size) {
            bool(*compare)(T, T) = isMin ? min : max;
            int child = getChild(i, isMin);
            if (level(child) - level(i) == 2 && child != -1) {
                if (compare(this->heap[child], this->heap[i])) {
                    std::swap(this->heap[child], this->heap[i]);
                    int parent = child / 2;
                    if (compare(this->heap[parent], this->heap[child]))
                        std::swap(this->heap[parent], this->heap[child]);
                    pushDownImpl(child, isMin);
                }
            }
            else if (compare(this->heap[child], this->heap[i])) {
                std::swap(this->heap[child], this->heap[i]);
            }
        }
    }

    void pushUp(int i) {
        if (this->size >= 1)
            pushUpImpl(i, isMin(i));
    }

    void pushUpImpl(int i, bool isMin) {
        int parent = i/2;
        bool(*compare)(T, T) = isMin ? min : max;
        if (compare(this->heap[parent], this->heap[i])) {
            std::swap(this->heap[parent], this->heap[i]);
            this->pushUpImplImpl(parent, !isMin);
        }
        else
            this->pushUpImplImpl(i, isMin);
    }

    void pushUpImplImpl(int i, bool isMin) {
        bool (*compare)(T, T) = isMin ? min : max;
        int grandparent = i / 2 / 2;
        if (grandparent >= 1) {
            if (compare(this->heap[i], this->heap[grandparent])) {
                std::swap(this->heap[i], this->heap[grandparent]);
                pushUpImplImpl(grandparent, isMin);
            }
        }
    }

public:
    minMaxHeap() : size(0), heap(new T[MAX_SIZE]) {}
    ~minMaxHeap() {
        delete [] heap;
    }

    void push(T n) {
        int newlyAppended = this->size + 1;
        this->heap[newlyAppended] = n;
        this->pushUp(newlyAppended);
        this->size++;
    }

    int backIndex() {
        int backIndex = this->size == 1 ? 1 : 2;
        if (this->size >= 3)
            backIndex = this->heap[2] > this->heap[3] ? 2 : 3;
        return backIndex;
    }

    T front() {
        return this->heap[1];
    }

    T back() {
        return this->heap[backIndex()];
    }

    void popFront() {
        this->heap[1] = this->heap[this->size];
        this->pushDown(1);
        this->size--;
    }

    void popBack() {
        int poppedIndex = backIndex();
        this->heap[poppedIndex] = this->heap[this->size];
        this->pushDown(poppedIndex);
        this->size--;
    }

    bool isEmpty() const {
        return !this->size;
    }
};

typedef long long int ll;

void tc() {
    minMaxHeap<ll> mmh;
    int k = (int)input();
    for (int i = 0; i < k; i++) {
        char opt;
        ll n;
        scanf(" %c", &opt);
        n = input();
        if (opt == 'I')
            mmh.push(n);
        else
        if (mmh.isEmpty())
            continue;
        else if (n == 1)
            mmh.popBack();
        else
            mmh.popFront();
    }

    if (mmh.isEmpty())
        printf("EMPTY\n");
    else
        printf("%lld %lld\n", mmh.back(), mmh.front());
}

long input() {
    char* ptr;
    char str[256];
    long ret;
    scanf(" %s", str);
    ret = strtol(str, &ptr, 10);
    return ret;
}