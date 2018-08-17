#include <stdio.h>
#include "ordena.h"

// algoritmo de ordenação Heap Sort
ordem
void Ordena<ORDEM>::maxHeapity(ORDEM *arvore, int tamanhoHeap,  int i, int(*comparar)(ORDEM,ORDEM))
{
    int esq = left(i);
    int dir = right(i);
    int maior;
    ORDEM temp2;

        if(comparar(arvore[esq],arvore[i])>0)
            maior = esq;
        else
            maior = i;
        if(comparar(arvore[dir], arvore[maior])>0)
            maior = dir;
        if(maior != i){
          temp2 = arvore[i];
          arvore[i] = arvore[maior];
          arvore[maior] = temp2;
          maxHeapity(arvore, maior,tamanhoHeap,comparar);
        }
}
ordem
void Ordena<ORDEM>::buildHeap(ORDEM *arvore, int tamanhoHeap,int(*comparar)(ORDEM,ORDEM))
{
    int i;
    for( i = tamanhoHeap/2; i>=0; i--) //cria healp da metade do vetor ate 0
        maxHeapity(arvore,i,tamanhoHeap,comparar);

}
ordem
void Ordena<ORDEM>::heapSort(ORDEM* arvore, int tamanhoHeap, int(*comparar)(ORDEM,ORDEM))
{

    buildHeap(arvore, tamanhoHeap,comparar);
    int i;
    ORDEM temp1;
    for(i=tamanhoHeap; i>0; i--){
        temp1 = arvore[i];
        arvore[i] = arvore[0];
        arvore[0] = temp1;
        tamanhoHeap--;
        maxHeapity(arvore,0,tamanhoHeap,comparar);
    }

}
