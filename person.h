#ifndef PERSON_H
#define PERSON_H


#include <string>
class Person
{
private:
//long key;
std::string patronymic;
std::string last_name;
std::string first_name;
public:
Person(){
    last_name = "";
    first_name =  "";
    patronymic = "";

}
Person(std::string  l_name, std::string  f_name, std::string patr ){
    last_name =  l_name;
    first_name = f_name;
    patronymic = patr;
};
Person(const Person&other ){
    std::string last_name;
    last_name = other.getLastName();
    first_name = other.getFirstName();
    patronymic = other.getPatronymic();

};

const std::string& getLastName() const { return last_name; }
const std::string& getPatronymic() const { return patronymic; }
const std::string& getFirstName() const { return first_name; }
void setLastName(const std::string&);
void setFirstame(const std::string&);
};
#endif


