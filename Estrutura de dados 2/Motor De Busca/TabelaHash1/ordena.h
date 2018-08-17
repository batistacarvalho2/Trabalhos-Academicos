#ifndef ORDENA_H
#define ORDENA_H
#include "relevancia.h"
#include <QDebug>
#define ordem template<class ORDEM>

ordem
class Ordena{
public:
//  Ordena(){ }
//   ~Ordena() {}
    //Declara Metodos de ordenação
    int left(int i) {return (2 * i) + 1;}
    int right(int i) {return (2 * i) + 2;}
    void maxHeapity(ORDEM *arvore, int i, int tamanhoHeap, int(*comparar)(ORDEM,ORDEM));
    void buildHeap(ORDEM *arvore, int tamanhoHeap, int(*comparar)(ORDEM,ORDEM));
    void heapSort(ORDEM *arvore, int tamanhoHeap, int(*comparar)(ORDEM,ORDEM));

};

#endif // Ordena_H
