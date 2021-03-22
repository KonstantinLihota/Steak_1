#pragma once
#ifndef STAK_H
#define STAK_H
#include<exceptionstack.h>
#include <iostream>
template <typename T>
class stak
{
private:
    T* stackPtr;
    int size;
    int top;
public:
    stak( int = 20);
    stak(const stak<T>&);
    ~stak();

    int push(const T&);
    T pop();
    int getSize();
    T* get_ptr() ;
    int get_top() ;
    void print() ;
};
#endif // STAK_H




template<typename  T>
int stak<T>::push(const T& value) {
    if (size == top) {
    throw exc::ExceptionStackOverflor("Stack overflor");
    }
    top++;
    stackPtr[top] = value;
    return top;
}
template<typename T>
stak<T>::stak(int size)
{
    stackPtr = new T[size];
    top = 0;
}

template <typename T>
stak<T>::stak(const stak<T>& other)
{
    stackPtr = new T[size];
    top = other.get_top();
    for (int i = 0; i<top; i++){
        stackPtr[i] = other.get_ptr()[i];
    }

}
template<typename T>
stak<T>::~stak() {
    delete[] stackPtr;
}
template<typename T>
T stak<T>::pop() {
    if (top == 0) {
        throw exc::ExceptionStackOverflor("Stack empty");
    }

    top--;
    stackPtr[top];

    return stackPtr[top];
}

template <typename T>
int stak<T>::getSize()
{
    return size;
}


template <typename T>
T* stak<T>::get_ptr()
{
    return stackPtr;
}


template <typename T>
int stak<T>::get_top()
{
    return top;
}
template <typename T>
void stak<T>::print() {
    for (int i=1; i < top; i++)
        std::cout << stackPtr[i]<<' ';

}
