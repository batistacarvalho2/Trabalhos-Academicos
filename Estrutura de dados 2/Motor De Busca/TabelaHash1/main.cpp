#include <iostream>
#include <string>
#include <cstdio>

#include "interface.h"
using namespace std;

int main()
{
    Interface a;
    char texto[100];
    // nome do arquivo

//    printf("Digite a entrada dos arquivos: ");
//    scanf(" %[^\n]",texto);
//    try{
//    a.indexar(texto);
//    }
//    catch(string erro){
//     printf("ERRO: %s",erro.c_str());
//    }
//    printf("\nDigite aqui a frase de pesquisa: ");
//    scanf(" %[^\n]",texto);
//    string b = a.buscaPalavra(texto,1);


    a.indexar(string("entrada.txt"));
   // try{
   string b = a.buscaPalavra(string("tempo"),1);
//    }
//    catch(string erro){
//        printf("ERRO: %s",erro.c_str());
//    }
//    catch(int erro){
//        printf("ERRO: %s", erro.c_str());
//    }

 // printf("a palavra:%s",b);


//    TabelaHash<string,int> a;
//   a.put(string("indexado"),2);
//    qDebug()<<a.getDado(string("indexado"));

    cout << "\n..BAY..\n";
    return 0;
}
