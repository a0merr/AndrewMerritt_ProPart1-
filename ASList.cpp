#ifndef ASLIST_CPP
#define ASLIST_CPP

#include "ASList.h"
#include <iostream>
using namespace std;

template <class T>
ASList<T>::ASList() : length(0) {}

template <class T>
bool ASList<T>::isFull() const {
    return length == MAX_SIZE;
}

template <class T>
bool ASList<T>::isEmpty() const {
    return length == 0;
}

template <class T>
void ASList<T>::insert(const T& item) {
    if (isFull()) {
        cout << "List is full, cannot insert more items.\n";
        return;
    }

    int i = length - 1;
    while (i >= 0 && item < elements[i]) {
        elements[i + 1] = elements[i];
        i--;
    }

    elements[i + 1] = item;
    length++;
}

template <class T>
void ASList<T>::print() const {
    for (int i = 0; i < length; i++) {
        cout << elements[i].country << ", "
             << elements[i].literacyRate << ", "
             << elements[i].gdpPerCapita << endl;
    }
}

#endif
