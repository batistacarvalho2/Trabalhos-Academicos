#ifndef DOCUMENTOPALAVRA_H
#define DOCUMENTOPALAVRA_H

#include "documento.h"
class DocumentoPalavra{
private:
    Documento * documento;
    int numeroVezesPalavra;
public:
    DocumentoPalavra();
    Documento * getDocumento();
    int getNumeroVezesPalavra();
    void setDocumento(Documento*);
    void setNumeroVezesPalavra(int);
    void incrementaNumeroVezesPalavra();

};

#endif // DOCUMENTOPALAVRA_H
