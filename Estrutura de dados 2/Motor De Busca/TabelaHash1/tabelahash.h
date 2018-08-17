#ifndef TABELAHASH_H
#define TABELAHASH_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <string>
#include <string.h>
#include <time.h>
#include "node.h"
#include <QDebug>
using namespace std;

#define temp template <class K, class D>

#define max 9931

temp
class TabelaHash
{
private:
    int (*hash1)(K);
    int (*_comparar)(K,K);
    int funcaoHash(int k);  //função hash simples
    int funcaoHash2(int k); //funcao hash linear
    int hashDuplo(int k, int i); //funcao hash quadratica
    Node<K,D>** vetor;
    int _elemento,n;
    double multiplica;
    void setFuncao(int (*_compa)(K,K),int (*has)(K));
    bool ehPrimo(int num);
    void proximoPrimo(int& primo);
    void incrementaElemento();

public:
    TabelaHash(int (*chave)(K)); //cache para chave
    TabelaHash();
    ~TabelaHash();
    int tempo;
    int contador;  //contador
    void put(K key,D dado); //inserir
    D getDado(K key); //Buscar
    void remover(K);
    Node<K,D>* Key();
    int size();
    int (*chaveInt)(K); // converte key em int
    bool isEmpty();
    bool conteins(K key);  //existe chave
    void setFuncoesHash(int (*hah1)(K)){ chaveInt = hash1 = hah1;}
    void setCompare(int (*comp)(K,K)) { _comparar = comp;}
    void inicializarTabela(int n);
    int getTamanhoTabela(){return n;}
    void clean();
    int buscaItem(int);
    K* getKey();
   inline D operator [] (K ch){return getDado(ch);}


};

#endif // TABELAHASH_H
