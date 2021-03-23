#include"personkeeper.h"
#include<iostream>
#include<fstream>
stak<Person> PersonKeeper :: readPersons() {//функция чтения

    std::ifstream file;
     file.open("..\\Steak_1\\input.txt");
     Person  pers;

     while (!file.eof()){
         std::string x,y,z;
         file>>x>>y>>z;
         Person  pers(x,y,z);
         PersonKeeper::Instance().stakPerson.push(pers);
        }
      file.close();
  return PersonKeeper::Instance().stakPerson;

}

void PersonKeeper ::writePerson() {//функция записи в файл
    std::ofstream file;
    file.open("..\\Steak_1\\output.txt", std::ofstream::app);
    Person pers;
    int i=PersonKeeper::Instance().stakPerson.get_top()-1;
    while(i>=0){

    pers = PersonKeeper::Instance().stakPerson.get_ptr()[i];
    file<<pers.getFirstName()<<' '<<pers.getLastName()<<' '<<pers.getPatronymic()<<'\n';
    i--;
}
    file.close();
}
