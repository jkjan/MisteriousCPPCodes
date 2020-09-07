//
// Created by jkjan on 2020-02-08.
//

#ifndef ARRAY_MYARRAY_H
#define ARRAY_MYARRAY_H
#include <iostream>
using namespace std;
template <typename T>
class MyArray {
public:
    T* arr;
    int cnt;
    int capacity;

    MyArray(int size) {
        this->arr = (T*)malloc(sizeof(T)* size);
        this->cnt = 0;
    }
    MyArray()=default;
    int at(int index);
    int operator[](int index);
    MyArray operator+(MyArray b);
    MyArray<T>& operator=(MyArray b);
    void resize(int size);
    vector<int> search(T t);
    void push_back(T t);
    void remove_at(int index);
    bool remove(T t);
    int count(T t);
    void insert(int index, T t);
    int size();
    bool isEmpty();
    bool isFull();
};

template<typename T>
int MyArray<T>::at(int index) {
    int num;
    try {
        if (index >= this->size()) throw index;
        else
            return this->arr[index];
    } catch (int index) {
        cout << "index out of bounds : index : " << index << ", size : " << this->cnt << endl;
        return -1;
    }
}

template<typename T>
int MyArray<T>::operator[](int index) {
    return this->arr[index];
}

template<typename T>
MyArray<T> MyArray<T>::operator+(MyArray b) {
    MyArray newArray(this->cnt + b.cnt);
    for (int i = 0; i < this->cnt; i++) {
        newArray.arr[i] = this->arr[i];
    }
    for (int i = this->cnt; i < this->cnt+b.cnt; i++) {
        newArray.arr[i] = b.arr[i];
    }
    newArray.cnt = this->cnt + b.cnt;
    return newArray;
}

template<typename T>
MyArray<T>& MyArray<T>::operator=(MyArray b) {
    if (this->capacity < b.cnt) {
        this->resize(b.cnt);
    }
    for (int i = 0; i < b.cnt; i++) {
        this->arr[i] = b.arr[i];
    }
}

template<typename T>
void MyArray<T>::resize(int size) {
    this->arr = (T*)realloc(this->arr, size*sizeof(T));
    this->capacity = size;
}

template <typename T>
vector<int> MyArray<T>::search(T t) {
    vector<int> indices;
    for (int i = 0; i < this->cnt; i++) {
        if (this->arr[i] == t)
            indices.push_back(i);
    }
    return indices;
}

template<typename T>
void MyArray<T>::push_back(T t) {
    if (this->isFull())
        this->resize(this->size()+1);
    this->arr[this->cnt] = t;
}

template<typename T>
void MyArray<T>::remove_at(int index) {
    if (this->isEmpty())
        return;

    this->cnt--;
    for (int i = index; i < this->cnt; i++) {
        this->arr[i] = this->arr[i+1];
    }
}

template<typename T>
bool MyArray<T>::remove(T t) {
    if (this->isEmpty())
        return false;

    vector<int> indices = this->search(t);
    for (int&index : indices) {
        this->remove_at(index);
    }

    return true;
}

template<typename T>
int MyArray<T>::count(T t) {
    int cnt = 0;
    for (int i = 0; i < this->cnt; i++) {
        if (this->arr[i] == t)
            cnt++;
    }
    return cnt;
}

template<typename T>
void MyArray<T>::insert(int index, T t) {
    if (this->isFull())
        this->resize(this->capacity+1);
    for (int i = this->cnt - 1; i >= index; i++) {
        this->arr[i+1] = this->arr[i];
    }
    this->arr[index] = t;
    this->cnt++;
}

template<typename T>
int MyArray<T>::size() {
    return this->cnt;
}

template<typename T>
bool MyArray<T>::isEmpty() {
    return this->cnt == 0;
}

template<typename T>
bool MyArray<T>::isFull() {
    return this->cnt == this->capacity;
}

#endif //ARRAY_MYARRAY_H
