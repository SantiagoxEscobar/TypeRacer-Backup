#include "Keyword.h"
#include<iostream>
#include<cstring>
#include<conio.h>

//constructor
Keyword::Keyword()
{

}

//getters
const char *Keyword::getP()
{
    return _p;
}
int Keyword::getTam()
{
    return _tam;
}

//setters
void Keyword::setP(const char *p)
{
    _tam = strlen(p)+1;
    _p = new char [_tam];
    if(_p == NULL)
    {
        std::cout << "ERROR DE ASIGNACION DE MEMORIA" << std::endl;
        exit(1);
    }
    strcpy(_p, p);
    _p[_tam-1] = '\0';
}

//desstructor
Keyword::~Keyword()
{
    delete _p;
}
