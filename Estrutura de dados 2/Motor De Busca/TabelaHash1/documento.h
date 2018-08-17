#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <iostream>
#include <string.h> // strcpy(), ponteiro para matriz de destino onde o conteudo deve ser copiado

#define MAX_ARQUIVO 300 // define tamanho maximo para nome do arquivo
#define MAX_PALAVRA 150 // Define tamanho maximo para palavra
// documento
using namespace std;

class Documento
{
private:
    char caminhoDocumento[MAX_ARQUIVO]; // nome dop documento
    int palavraDistintas; // contador de palavras distintas
public:
    Documento(char caminhoDocumento[]);

    char* getNomeDocumento() {return this->caminhoDocumento;}
    void setPalavraDistintas(int _palavra) { this->palavraDistintas = _palavra;}
    int getPalavraDistintas() {return palavraDistintas;}
    void AdicionaPalavraDestintas();

};

#endif // DOCUMENTO_H
