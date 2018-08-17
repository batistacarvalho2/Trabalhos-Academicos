#ifndef LISTADEPALAVRA_H
#define LISTADEPALAVRA_H
#include <iostream>
#include "documento.h"

// documentoPalavra
using namespace std;

class ListaDePalavra
{
private:
    Documento* documentoLista; //ponteiro para documento lista de documento
    int numeroPalavraLista;//contador palavra iguais no mesmo arquivo
public:
    ListaDePalavra();
    Documento* getNomeDocumentoLista();
    int getNumeroPalavraLista();
    void setDocumentoLista(Documento* nomeDocumentoLista);
    void setNumeroPalavraLista(int num);//
    void incrementaNumeroVezesPalavra();

};
#endif // LISTADEPALAVRA_H
