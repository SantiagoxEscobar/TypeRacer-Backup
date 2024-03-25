#include "ArchivosEditor.h"

ArchivosEditor::ArchivosEditor(const char *n)
{
    strcpy(_nombre, n);
}

bool ArchivosEditor::grabarArchivo(Archivos reg){
    FILE *p;
    p = fopen(_nombre, "ab");
    if(p == NULL) return false;
    bool escribio = fwrite(&reg, sizeof reg,1, p);
    fclose(p);
    return escribio;
}

int ArchivosEditor::contarRegistros(){
    FILE *p;
        p = fopen(_nombre, "rb");
        if(p == NULL) return -1;
        fseek(p, 0,2);
        int tam = ftell(p);
        fclose(p);
        return tam/sizeof(Archivos);
}
Archivos ArchivosEditor::leerRegistro(int pos){
    Archivos reg;
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == NULL) return reg;
    fseek(p, sizeof reg *pos,0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}
