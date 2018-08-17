#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include "defines.h"
using namespace std;

class Documento{
private:
    char caminho[MAX_NOME_ARQUIVO];
    int palavrasDistintas;
public:
    Documento(char[]);
    int getPalavrasDistintas();
    char * getCaminho();
    void setPalavrasDistintas(int);
    void incrementaPalavrasDistintas();

};

#endif // DOCUMENTO_H
