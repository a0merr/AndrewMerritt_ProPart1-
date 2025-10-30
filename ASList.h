#ifndef ASLIST_H
#define ASLIST_H

#include <iostream>
using namespace std;

template <class T>
class ASList {
private:
    static const int MAX_SIZE = 1000;  
    T elements[MAX_SIZE];
    int length;

public:
    ASList() : length(0) {}

    bool isFull() const {
        return length == MAX_SIZE;
    }

    bool isEmpty() const {
        return length == 0;
    }

    void insert(const T& item) {
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

    void print() const {
        for (int i = 0; i < length; i++) {
            cout << elements[i].country << ", "
                 << elements[i].literacyRate << ", "
                 << elements[i].gdpPerCapita << endl;
        }
    }
};

#endif
