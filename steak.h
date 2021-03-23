#pragma once
#ifndef STAK_H
#define STAK_H
#include "exceptionstack.h"
#include <iostream>
//Класс шаблон стек
template <typename T>
class stak
{
private:
    T* stackPtr;
    int size ;
    int top;
public:
    stak(int =40);
    stak(const stak<T>&);
    ~stak();

    int push(const T&);
    T pop();
    int getSize() const;
    T* get_ptr() const;
    int get_top() const;
    void print() const;
};





template<typename  T>
int stak<T>::push(const T& value) { //добавление элемента в стек
    if (size == top) {
    throw exc::ExceptionStackOverflor("Stack overflor");
    }
    stackPtr[top++] = value;
    //return top;
}


template<typename T>
stak<T>::stak(int _size): //конструктор создающий стэк длины _size
    size(_size)
{
    stackPtr = new T[size];
    top = 0;
}


template <typename T>
stak<T>::stak(const stak<T>& other): //конструктор копирования
    size(other.getSize())
{
    stackPtr = new T[size];
    top = other.get_top();
    for (int i = 0; i<top; i++){
        stackPtr[i] = other.get_ptr()[i];
    }

}


template<typename T> //деструктор
stak<T>::~stak() {
    delete[] stackPtr;
}


template<typename T> //удаление элемента
T stak<T>::pop() {
    if (top == 0) {
        throw exc::ExceptionStackOverflor("Stack empty");
    }

    top--;
    stackPtr[top];
    return stackPtr[top];
}


template <typename T>
int stak<T>::getSize() const
{
    return size;
}


template <typename T>
T* stak<T>::get_ptr()const
{
    return stackPtr;
}


template <typename T>
int stak<T>::get_top() const
{
    return top;
}
/*
template <typename T>
void stak<T>::print() const{
    for (int i=1; i < top; i++)
        std::cout << stackPtr[i]<<' ';

}*/
#endif // STAK_H
