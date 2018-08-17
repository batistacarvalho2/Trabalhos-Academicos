#include "docpalavra.h"

// verifica se lista de palavra contem palavra destinta
bool DocPalavra::existePalavraLista(char* palavra){ // string nome do arquivo
    list<ListaDePalavra>::iterator it;
    for(it=ListaDocumentoPalavra.begin(); it!=ListaDocumentoPalavra.end(); it++){
        //strcmp, Esta função começa comparando o primeiro caractere de cada seqüência de caracteres
        if(strcmp(palavra, it->getNomeDocumentoLista()->getNomeDocumento()) == 0){ // mome do documento da lista + caminho
            return true;
        }
      }
    return false;
}
// adiciona nomeDocumento na lista
void DocPalavra::addListaDeDoc(ListaDePalavra addPalavralista){
    ListaDocumentoPalavra.push_back(addPalavralista);
}
ListaDePalavra* DocPalavra::getDocPalavra(char* nomeDocumento){
     if(existePalavraLista(nomeDocumento)){
        list<ListaDePalavra>::iterator it;
        for(it = ListaDocumentoPalavra.begin(); it!=ListaDocumentoPalavra.end();it++){
        //strcmp, Esta função começa comparando o primeiro caractere de cada seqüência de caracteres
        if(strcmp(nomeDocumento, it->getNomeDocumentoLista()->getNomeDocumento()) == 0){
            return &*it;
            }
        }
     }
     return 0;
 }

//numeros de documentos da lista
int DocPalavra::getNumerosDocumentos(){
    return ListaDocumentoPalavra.size();
}

ListaDePalavra*  DocPalavra::getVetorDocumento(){
     ListaDePalavra *temp;
     temp = new ListaDePalavra[ListaDocumentoPalavra.size()];
    list<ListaDePalavra>::iterator it;
    int i=0;
     for(it=ListaDocumentoPalavra.begin(); it!=ListaDocumentoPalavra.end() ;it++){
         temp[i++]= *it;
     }
     return temp;
}


