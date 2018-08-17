#ifndef RELEVANCIA_H
#define RELEVANCIA_H
#include "documento.h"
#include "docpalavra.h"
#include <iostream>
using namespace std;
// retorno

class Relevancia
{
public:
    Relevancia();
    void setRelevancia(float _relevancia);
    float getRelevancia();
    void setRelevanciaDocumento(Documento* _documentoRelevancia);
    Documento* getRelevanciaDocumento();
private:
    float _relevancia;
    Documento* _documentoRelevancia;

};

#endif // RELEVANCIA_H
