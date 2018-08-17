#ifndef PALAVRADOCUMENTO_H
#define PALAVRADOCUMENTO_H
#include <list>
#include <cstdio>
#include <cstring>
#include "documentopalavra.h"
#include "defines.h"

class PalavraDocumento
{
private:
    list<DocumentoPalavra> documentoPalavra;
    char palavra[MAX_PALAVRA];
public:
    bool arquivoExiste(char*);
    void addArquivo(DocumentoPalavra);
    DocumentoPalavra* getDocumentoPalavra(char*);//retorna vetor de DocumentoPalavra que contem arquivos da lista
    DocumentoPalavra* getVetorDocumentoPalavra();
    void setPalavra(char*);
    char* getPalavra();
    int getNumArquivos();

};

#endif // PALAVRADOCUMENTO_H
