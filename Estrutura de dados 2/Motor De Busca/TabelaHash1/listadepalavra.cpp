#include "listadepalavra.h"

ListaDePalavra::ListaDePalavra(){
    this->numeroPalavraLista=0;
}

Documento* ListaDePalavra::getNomeDocumentoLista(){
    return documentoLista;
}

int ListaDePalavra::getNumeroPalavraLista(){
    return this->numeroPalavraLista;
}

void ListaDePalavra::setDocumentoLista(Documento* nomeDocumentoLista){
    this->documentoLista = nomeDocumentoLista;
}

void ListaDePalavra::setNumeroPalavraLista(int num){
    this->numeroPalavraLista = num;
}
void ListaDePalavra::incrementaNumeroVezesPalavra(){
    this->numeroPalavraLista++;
}

