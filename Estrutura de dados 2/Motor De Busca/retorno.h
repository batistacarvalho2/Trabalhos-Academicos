#ifndef RETORNO_H
#define RETORNO_H
#include "palavradocumento.h"
#include "documento.h"

#include <iostream>
using namespace std;
class Retorno
{
private:
     Documento *documentoRetorno;
     float relevancia;
public:
    Retorno();
    void setRelevancia(float);
    float getRelevancia();
    void setDocumentoRetorno(Documento*);
    Documento* getDocumentoRetorno();

};

#endif // RETORNO_H
