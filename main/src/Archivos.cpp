#include<iostream>
#include "Archivos.h"

using namespace std;

void Archivos::setKeyword(const char *key)
{
    strcpy(_keyword, key);
}
const char *Archivos::getKeyword()
{
    return _keyword;
}
void Archivos::Cargar(){
    cout << "- Keyword: ";
    cargarCadena(_keyword,34);
    cout << endl;
}
void Archivos::Mostrar(){
    cout << "- Keyword: " << _keyword << endl;
}
void Archivos::cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=std::cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
