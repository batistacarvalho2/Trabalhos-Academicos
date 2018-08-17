#include "tabelahash.h"
template <class K>
int generCompare(K palavraA,K palavraB){
    if(palavraA > palavraB)return 1;
    if(palavraA < palavraB)return 0;
    return 0;
}

template <class K>
int genericHash1(K chave){
    char *test = (char*)&chave;
    int cha=0;
    for(int i=0;i<(int)sizeof(K);i++){
        cha+= test[i] + test[i]*i;
    }
    cha*=3;
    return cha;
}

temp
TabelaHash<K,D>::~TabelaHash(){ //Destrutor
    clean();
}
temp
TabelaHash<K,D>::TabelaHash(int (*chave)(K)){ //chave para chave
    vetor=0;
    hash1 = 0;
    _comparar=0;
    proximoPrimo(chave);
    inicializarTabela(chave);

}

temp
TabelaHash<K,D>::TabelaHash()
{
    vetor=0;
    hash1 = 0;
    _comparar = 0;
    contador = 0;
    inicializarTabela(max);
}



temp
int TabelaHash<K,D>::funcaoHash(int key){ //funcao hash simples
    return ((key)%max)*key*key;
}

temp
int TabelaHash<K,D>::funcaoHash2(int key)
{
    return ((3*key %(max-1))+1);
}

temp
int TabelaHash<K,D>::hashDuplo(int key, int i){ // funcao de sondagem quadratica hash duplo
    return ((funcaoHash(key)+i*funcaoHash2(key))%max);
}

temp
void TabelaHash<K,D>::setFuncao(int (*_compa)(K, K), int (*has)(K))
{
    _comparar = _compa;
    hash1 = has;
}

temp
void TabelaHash<K,D>::clean(){
    if(this->size()==0)return;
    for(int i=0;i<n;i++){
        delete vetor[i];
    }
    delete vetor;
    vetor=0;
    _elemento=0;
}


temp
void TabelaHash<K,D>::put(K key,D dado)
{
//    if(contador == max)    {
//        printf("TABELA CHEIA");
//        return;
//    }
//    tempo=0;
//    int i=0, h; //sondagem quadratica
//    h = hashDuplo((*chaveInt)(key),i);
//    while (vetor[h] != NULL && vetor[h] !=(Node<K,D>*)-1){
//        h=hashDuplo((*chaveInt)(key),i++);
//        tempo+=i;
//    }
//   // cout << "Colisao "<< i << endl;
//    if(!conteins(key)){
//     h=buscaItem((*chaveInt)(key));
//     delete vetor[h];
//    vetor[h]= new Node<K,D>(dado,key);
//    _elemento++;
//    contador+=i-1;
//    if(contador<0)contador = 0;
//    }

//contador++;
//    return;

    if(contador == max)
    {
        printf("TABELA CHEIA");
        return;
    }
    int i=0, h=hashDuplo((*chaveInt)(key),i);
    while (vetor[h] != NULL && vetor[h] !=(Node<K,D>*)-1)
    {//travei
        h=hashDuplo((*chaveInt)(key),i++);
        incrementaElemento();
    }

//    //cout << "Colisao "<< i << endl;
   vetor[h]= new Node<K,D>(dado,key);
    contador++;
    return;
}

temp
void TabelaHash<K,D>::incrementaElemento(){
    this->_elemento=_elemento+1;
}

//
temp
int TabelaHash<K,D>::buscaItem(int chave){
    int posi=hashDuplo(chave,0);
    int i=1;
    while (vetor[posi]!=0 && i<n) {
        if(vetor[posi] == (Node<K,D>*)-1){
            posi=hashDuplo(chave,i++);
        }
        else{
            if((vetor[posi]->getChave(),chave)==0){
                return posi;
            }
            else{
                posi = hashDuplo(chave,i++);
            }
        }
    }
    return posi;
}

temp
int TabelaHash<K,D>::size()
{
    return contador; //contador
}

temp
D TabelaHash<K,D>::getDado(K key)
{
    if(isEmpty())
        throw(0);
    int i=0, h = hashDuplo((*chaveInt)(key),i);
    while (vetor[h] != NULL && vetor[h]->getChave() != key && i != max)
    {
        h = hashDuplo((*chaveInt)(key),i++);
    }
    if(vetor[h] == NULL)
        throw(0);

    return vetor[h]->getDadoNode(); // retorna dado
}

temp
bool TabelaHash<K,D>::isEmpty()  // verifica se esta vazio
{
    if(contador > 0)
        return false;
    return true;
}

temp
void TabelaHash<K,D>::inicializarTabela(int n){
    double randIracional[5]={3.14159265358 , 1.414213562 , 1.732050808 ,4.123105626 , 3.16227766};
    clean();
    _elemento=0;
    srand(time(0));
    this->n = n;
    vetor = new Node<K,D>*[this->n];
    for(int i=0;i<this->n;i++){
        vetor[i] = 0;
    }
    if(hash1 == 0){
        setFuncoesHash(genericHash1);

    }
    if(_comparar== 0){
        setCompare(generCompare);
    }
    multiplica = randIracional[rand()%5];
    contador=0;
    //  qDebug()<<"Tabela com emlementos: "<<this->n;
}

temp
void TabelaHash<K,D>::remover(K key)
{
    if(isEmpty())
        return;

    int i=0, h = hashDuplo((*chaveInt)(key),i);
    while (vetor[h] != NULL && vetor[h]->key != key)
    {
        h = hashDuplo((*chaveInt)(key),i++);
        if(vetor[h] == NULL && i == max)
            return;
    }

    delete vetor[h]; // deleta chave
    vetor[h] = (Node<K,D>*)-1; // adicionar -1 no indice do vetor que exestia uma chave
}

temp
bool TabelaHash<K,D>::conteins(K key){
    int i=0, h = hashDuplo((*chaveInt)(key),i);
    while(vetor[h] != NULL && vetor[h] != (Node<K,D>*)-1){
        if(vetor[h]->key == key)
            return true;

        h = hashDuplo((*chaveInt)(key), i++);
        if(i == max) // limite maximo de verificação
            return false;
    }
    return false;
}
temp
 bool TabelaHash<K,D>::ehPrimo(int num){
     if(num==1)return false;
     int raiz = (int)(sqrt(num));
     for(int i=2; i<=raiz;i++){
         if(num%i == 0)return false;
     }
     return true;
}
temp
void TabelaHash<K,D>::proximoPrimo(int& primo){
    while(!ehPrimo(primo)){
        primo++;
    }
    return;
}
temp
K* TabelaHash<K,D>::getKey(){
    K *chave=new K[_elemento];
    for(int i=0; i<n;i++){
        if(vetor[i]!=0 && vetor[i]!=(Node<K,D>*)-1){
            chave[i]=vetor[i]->getChave();
        }
        return chave;
    }
}
