
#include<stdio.h>
#include "steak.h"
#include<iostream>
int main()
{
    const int size = 20;
    stak<int> S(size);
    try {




    for (int i = 0; i < size; i++) {

        S.push(i);
    }
   // S.push(1);


    for (int i = 0; i < size; i++) {

        S.pop();
    }
    S.pop();
    }
   catch (exc:: Exception &err) {
       std::cout<<err.what();
    }
    return 0;
}
