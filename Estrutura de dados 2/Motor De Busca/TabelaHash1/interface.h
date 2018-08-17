#ifndef INTERFACE_H
#define INTERFACE_H
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include "tabelahash.hpp"
#include <listadepalavra.h>
#include "docpalavra.h"
#include "documento.h"
#include "relevancia.h"
#include "ordena.hpp"

#include <iostream>
using namespace std;

// interface
class Interface
{
public:

    static void indexar(string _palavra); //indexar palavra do arquivo
    static char* convertChar(string _string); //converte string para int
    static string buscaPalavra(string _palavra, bool verdade);
    static string entradaArquivo(){return _entradaArquivo;}
    static void finalizar();

    ~Interface();
private:

    static TabelaHash<string,DocPalavra> tabela;
    static char* _entradaArquivo;
    static Documento** _arquivoTexto;
    static int _numeroArquivos;
    static float logNumeroArquivo;
    static Node<string,DocPalavra>* _retono;
    static int _numRetorno; // numero da palavra indexada na tabela
    static int _numBuscado; // numero de achada na busca
    static Relevancia* _arquivoRelevancia;
    static int _numArquivosEmBusca; //
    static Ordena<Relevancia> heap;


    //funçoes para organizar relevancia na busca
    static void organizaRetorno();
    static void calcularRelevancia();
    static void indexarArquivo(FILE* _arquivo);
    static void indexarDocumento(char* _entrada, int _arquivo);
    static void validaPalavra(char* palavra);
    static void buscaPalavraTermo(string termo);
    static void uniao();
    static void interseccao();




};
#endif // INTERFACE_H
