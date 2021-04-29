#include"personkeeper.h"
#include<iostream>
#include<fstream>
#include <stdio.h>
stak<Person> PersonKeeper :: readPersons(std::string path) {//функция чтения

    std::ifstream file;
     file.open(path);
     if (!file.is_open()){ //Проверяем окрылся ли файл path
           std::string exp = "File "+path+" is not open";

          throw exc::ExceptionData(exp.c_str());

     }

     Person  pers;

     while (!file.eof()){ //читаем пока в файле есть данные
         std::string x,y,z;
         file>>x>>y>>z;
         if (x==""){ //проверка на пустоту файла
             file.close();
             throw exc::ExceptionData("File is empty");

         }
       if (y==""||z==""){//проверка на валидность данных(присутсвуют имя фамилия и отчество)
             file.close();
             throw exc::ExceptionData("Data is not valid");
         }
         Person  pers(x,y,z);
         PersonKeeper::Instance().stakPerson.push(pers);
        }
      file.close();
  return PersonKeeper::Instance().stakPerson;

}

void PersonKeeper ::writePerson(std::string path) {//функция записи в файл
    std::ofstream file;
    file.open(path,  std::ios::trunc);//открываем и очищаем файл от прочих записей
    //Проверяем окрылся ли файл
    if (!file.is_open()){
         throw exc::ExceptionData("File is not open");

    }
    Person pers;
    int i=PersonKeeper::Instance().stakPerson.get_top()-1; //делаем запись в файл начиная с вершины стека
    while(i>=0){

    pers = PersonKeeper::Instance().stakPerson.get_ptr()[i];
    file<<pers.getFirstName()<<' '<<pers.getLastName()<<' '<<pers.getPatronymic()<<'\n';
    i--;
}
    file.close();
}
