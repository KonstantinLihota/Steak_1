
#include <string.h>
#include<iostream>
/*Класс Exception  - базовый класс для обрабоотки исключительных ситуаций от которого мы наследуем классы обработки конкретных исключений
*/

namespace exc {

class Exception

{

    private:

        char* message;

    public:


    Exception(const char* arg_message)
    {
        message = new char[strlen(arg_message)+1];

        strcpy(message,arg_message);
     }

    Exception(const Exception& arg)
    {
        message = new char[strlen(arg.message)+1];

        strcpy(message,arg.message);
    }

    ~Exception()
    {
    delete message;
    }

    const char* what() const{ return message; }

    };



class ExceptionStackOverflor: public Exception //класс обработки исключения переполнения стэка
    {
    public:
    explicit ExceptionStackOverflor(const char* arg): Exception(arg) {}


    };


class ExceptionStackEmpty: public Exception{//класс обработки исключения пустоты стека
    public:
    explicit ExceptionStackEmpty(const char* arg) : Exception(arg){}

    };


class ExceptionData: public Exception{//класс обработки исключения не валидных данных
    public:
    explicit ExceptionData(const char* arg) : Exception(arg){
    }

    };

    }
