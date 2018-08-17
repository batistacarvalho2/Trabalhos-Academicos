#include "documento.h"

Documento::Documento(char caminhoDocumento[]){
    strcpy(this->caminhoDocumento, caminhoDocumento); //Ponteiro para a matriz de destino onde o conteúdo deve ser copiado.
    palavraDistintas = 0;
}

void Documento::AdicionaPalavraDestintas(){
    this->palavraDistintas++;
}
