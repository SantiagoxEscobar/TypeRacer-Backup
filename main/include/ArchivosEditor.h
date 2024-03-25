#ifndef ARCHIVOSEDITOR_H
#define ARCHIVOSEDITOR_H
#include "Archivos.h"

class ArchivosEditor
{
private:
    char _nombre[30];
public:
    ArchivosEditor(const char *n);

    bool grabarArchivo(Archivos reg);
    int contarRegistros();
    Archivos leerRegistro(int pos);
};

#endif // ARCHIVOSEDITOR_H
