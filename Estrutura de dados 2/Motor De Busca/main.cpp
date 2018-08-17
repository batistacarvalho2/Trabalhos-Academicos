#include <cstdio>
#include <string.h>
#include "interface.h"

int main()
{
    Interface a;
    char texto[100];

    try{
        printf("Digite a entrada dos arquivos: ");
        scanf(" %[^\n]",texto);
        a.indexar(texto);
        system("clear");
        printf("Indexado com sucesso!\n");
        while(1){
            *texto = 0;
            printf("\nDigite aqui a frase de pesquisa parar digite (SAIR): ");
            scanf(" %[^\n]",texto);
            if(strcmp(texto,"SAIR")==0)break;
            string b = a.buscarTermo(texto,1);
            cout<< " seu termo é"<<b;
        }
    }
    catch(string erro){
        printf("ERRO: %s",erro.c_str());
    }

    cout << "\n..BAY..\n";
    return 0;

}

