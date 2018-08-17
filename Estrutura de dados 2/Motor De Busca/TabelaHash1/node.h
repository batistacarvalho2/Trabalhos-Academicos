#ifndef NODE_H
#define NODE_H

template <class K, class D>
class Node{
public:
     K key;
     D dado;
     Node(D item, K chave) {this->dado=item, this->key=chave;}
     Node(K chave){ this->key=chave;}
     Node(){ }
     void setChave(K chave){this->key=chave;}
     K getChave(){return this->key;}
     void setDadoNode(D dado) {this->dado=dado;}
     D getDadoNode(){return this->dado;}
};

#endif // NODE_H
