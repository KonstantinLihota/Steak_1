#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include<iostream>
#include<string>
#include "steak.h"
#include "person.h"



//класс реализованые по шаблону Singlton
/* Singlton порождающий шаблон проектирования, гарантирующий, что в программе будет единственный экземпляр класса,
 *  и предоставляющий  точку доступа к этому экземпляру из любой части программы.
 *  При попытке создания данного объекта он создаётся только в том случае, если ещё не существует,
 *   в противном случае возвращается ссылка на уже существующий экземпляр и нового выделения памяти не происходит.
*/
class PersonKeeper {


private://конструктор, оператор присваивания и конструктор копирования являются приватными
    // что позволяет предотвратить создание экземпляров класса за пределами его реализации

    PersonKeeper(){
        stak<Person> stakPerson;

    }
    ~PersonKeeper(){}
    PersonKeeper( PersonKeeper const&);
    PersonKeeper& operator= ( PersonKeeper const&);
    stak<Person> stakPerson; //приватный для предотвращения доступа за пределами класса
                             //необходим для обращения к стеку внутри класса
public:


      void writePerson(std::string path) ;//функция записи в файл

      stak<Person>  readPersons(std::string path);//функция чтения из файла

      static PersonKeeper& Instance(){//функция сохраняющияя объект статичным

         static PersonKeeper s;
         return s;
     }


};


#endif

