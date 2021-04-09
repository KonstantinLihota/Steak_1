
#include<stdio.h>
#include "steak.h"
#include "personkeeper.h"
#include<iostream>
#include <string>

int main()
{

    const int size = 20;

    stak<int> S(size);
    try {//Проверка исключительных ситуация
        //переполнения
        for (int i = 0; i < size; i++) {
            S.push(i);
        }

        // S.push(1);

        //пустота
        for (int i = 0; i < size; i++) {
            S.pop();
        }
        // S.pop();

        //Мы используем singlton для того что бы у нас создавался единственный обьект
        //стека, это необходимо по причине того
        //что он используется в качестве баззы данных и нам нет необходимости
        //что бы он копировался или был в нескольких эккземплярах,
        //так же singlton дает возможность доступа к нему из любой части программы
       PersonKeeper& instance = PersonKeeper ::Instance(); //используем паатерн синглтон для создания для создания единственно обьекта
       instance.readPersons();//реализуем потоковое чтение объектов класса Person в стек из файла 'input.txt'
       instance.writePerson();//реализуем  запись объектов класса Person в стек из файла 'output.txt'


    }
    catch (exc:: Exception &err) {
        std::cout<<err.what();
    }

    return 0;
}
