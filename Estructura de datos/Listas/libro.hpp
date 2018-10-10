//Archivo que contendrá la estructura del
//elemento al que apuntará el nodo

#ifndef libro_h
#define libro_h

#include <iostream>

typedef struct Book
{
    char title[50];
    char autor[50];
    char isbn[13];
} Book;

#endif /* libro_h */