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
    ASList();                          

    bool isFull() const;               
    bool isEmpty() const;              

    void insert(const T& item);        
    void print() const;                
};

#include "ASList.cpp"

#endif

