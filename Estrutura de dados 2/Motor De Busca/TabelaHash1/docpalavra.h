#ifndef DOCPALAVRA_H
#define DOCPALAVRA_H
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string.h>
#include <list>
#include "listadepalavra.h"
//#include "documento.h"

// palavraDocumento

using namespace std;

class DocPalavra
{
private:
    list<ListaDePalavra> ListaDocumentoPalavra;
    char palavra[MAX_PALAVRA]; // chave
public:
    bool existePalavraLista(char* palavra);
    void addListaDeDoc(ListaDePalavra addPalavralista);
    void setPalavra(char* palavra) {strcpy(this->palavra,palavra);} //STRCPY -> Ponteiro para a matriz de destino onde o conteúdo deve ser copiado.
    char* getPalavra() {return this->palavra;}
    ListaDePalavra* getDocPalavra(char* nomeDocumento);
    ListaDePalavra* getVetorDocumento();
    int getNumerosDocumentos();
};

#endif // DOCPALAVRA_H
