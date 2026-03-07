#ifndef ASLIST_H
#define ASLIST_H

#include <iostream>
#include <stdexcept>

const int DEFAULT_CAPACITY = 100;

template <typename T>
class ASList {
private:
    T* data;
    int capacity;
    int size;

public:
    ASList(int cap = DEFAULT_CAPACITY);
    ~ASList();
    ASList(const ASList<T>& other);
    ASList<T>& operator=(const ASList<T>& other);
    void insert(const T& item);
    void print() const;
    bool isFull() const;
    bool isEmpty() const;
    int getSize() const;
};

template <typename T>
ASList<T>::ASList(int cap) : capacity(cap), size(0) {
    data = new T[capacity];
}

template <typename T>
ASList<T>::~ASList() {
    delete[] data;
}

template <typename T>
ASList<T>::ASList(const ASList<T>& other) : capacity(other.capacity), size(other.size) {
    data = new T[capacity];
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];
}

template <typename T>
ASList<T>& ASList<T>::operator=(const ASList<T>& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
void ASList<T>::insert(const T& item) {
    if (isFull())
        throw std::overflow_error("List is full.");
    int pos = size;
    for (int i = 0; i < size; ++i) {
        if (item < data[i]) { pos = i; break; }
    }
    for (int i = size; i > pos; --i)
        data[i] = data[i - 1];
    data[pos] = item;
    ++size;
}

template <typename T>
void ASList<T>::print() const {
    if (isEmpty()) { std::cout << "List is empty.\n"; return; }
    for (int i = 0; i < size; ++i)
        std::cout << data[i] << "\n";
}

template <typename T>
bool ASList<T>::isFull() const { return size >= capacity; }

template <typename T>
bool ASList<T>::isEmpty() const { return size == 0; }

template <typename T>
int ASList<T>::getSize() const { return size; }

#endif
