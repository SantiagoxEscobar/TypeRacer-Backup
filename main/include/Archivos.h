#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <cstring>

class Archivos
{
    private:
    char _keyword[35];

public:
    void setKeyword(const char *k);
    const char *getKeyword();

    void Cargar();
    void Mostrar();

    void cargarCadena(char *pal, int tam);
};

#endif // ARCHIVOS_H
