#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include<iostream>
#include<string>
#include "steak.h"
#include "person.h"



//класс реализованые по шаблону Singlton
class PersonKeeper {


private://конструктор, оператор присваивания и конструктор копирования являются приватными

    PersonKeeper(){
        stak<Person> stakPerson;

    }
    ~PersonKeeper(){}
    PersonKeeper( PersonKeeper const&);
    PersonKeeper& operator= ( PersonKeeper const&);
public:
      stak<Person> stakPerson;

      void writePerson(std::string path) ;//функция записи в файл

      stak<Person>  readPersons(std::string path);//функция чтения из файла

     static PersonKeeper& Instance(){//функция сохраняющияя объект статичным
         static PersonKeeper s;
         return s;
     }


};


#endif

