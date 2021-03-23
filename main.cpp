
#include<stdio.h>
#include "steak.h"
#include "personkeeper.h"
#include<iostream>
#include <string>

int main()
{
    const int size = 20;

    stak<int> S(size);
    try {
       PersonKeeper& instance = PersonKeeper ::Instance();
       instance.readPersons();
       instance.writePerson();


    }
    catch (exc:: Exception &err) {
        std::cout<<err.what();
    }

    return 0;
}
