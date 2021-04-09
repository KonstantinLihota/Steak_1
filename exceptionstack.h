
#include <string.h>

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



class ExceptionStackOverflor: public Exception //функция проверки переполнения стэка
    {
    public:
    explicit ExceptionStackOverflor(const char* arg): Exception(arg) {}


    };


class ExceptionStackEmpty: public Exception{//функция проверки пустоты стэка
    public:
    explicit ExceptionStackEmpty(const char* arg) : Exception(arg){}

    };


class ExceptionData: public Exception{//функция проверки пустоты стэка
    public:
    explicit ExceptionData(const char* arg) : Exception(arg){
    }

    };

    }
