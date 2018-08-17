#include "relevancia.h"

Relevancia::Relevancia(){
    _relevancia=0;
}

void Relevancia::setRelevancia(float _relevancia){
    this->_relevancia = _relevancia;
}

float Relevancia::getRelevancia(){
    return this->_relevancia;
}

void Relevancia::setRelevanciaDocumento(Documento *_documentoRelevancia){
    this->_documentoRelevancia =  _documentoRelevancia;
}

Documento* Relevancia::getRelevanciaDocumento(){
    return this->_documentoRelevancia;
}
