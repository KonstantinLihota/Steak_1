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
    T* stackPtr; //уазатель на стек
    int size ; //максимальнодоступный размер стека
    int top;// номер верхушки стека
public:
    stak(size_t =20);
    stak(const stak<T>&);
    ~stak();
    //добавление элемента в стек, входной параметр элемент колторый добовляется,
    //выходной параметр измененный номер  вершину
    int push(const T&);
    //возвращениеэлемента из стека
    T pop();
    int getSize() const; //возращаят длиину стекка
    //принципи инкапсуляции не нарушается так как функция не дает доступ к приватным полям напрямую
    T* get_ptr() const;
    int get_top() const; //возвращает длину стека
 //   void print() const;
};





template<typename  T>
int stak<T>::push(const T& value) { //добавление элемента в стек
    if (size == top) {
    throw exc::ExceptionStackOverflor("Stack overflor");
    }
    stackPtr[top++] = value;
    return top;
}

//используется size_t тк логику имеют только положительные индексы
template<typename T>
stak<T>::stak(size_t _size): //конструктор создающий стэк длины _size
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
        stackPtr[i] = other.stackPtr[i];
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
