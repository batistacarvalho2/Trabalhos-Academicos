

#include "interface.h"

int convertInt(string _string){ // converte string para inteiro
    int k = 0;
    for(int i = 0; i<(int)_string.length(); i++){
        k = (_string[i] + 256 * k*i)%max;
    }
    return k;
}

Interface::~Interface(){
    finalizar();
}

TabelaHash<string,DocPalavra> Interface::tabela;
char* Interface::_entradaArquivo;
Documento** Interface::_arquivoTexto;
int Interface::_numeroArquivos;
Node<string,DocPalavra>* Interface::_retono = 0;
int Interface::_numRetorno = 0;
int Interface::_numBuscado = 0;
Relevancia* Interface::_arquivoRelevancia = 0;
int Interface::_numArquivosEmBusca = 0;
float Interface::logNumeroArquivo;
Ordena<Relevancia> Interface::heap;


void Interface::indexar(string _palavra){
    Interface::finalizar();
    tabela.setFuncoesHash(convertInt);
    _entradaArquivo = convertChar(_palavra);
    FILE *arqEntrada = fopen(_entradaArquivo,"r");
    if(arqEntrada == 0){
        throw (string("Arquivo de indexação...\nNome do Arquivo não existe!"));
    }
    try{
        indexarArquivo(arqEntrada);
        fclose(arqEntrada);
    }
    catch(int erro){
        printf("Ocorreu um erro na int %d", erro);
    }
    catch (string erro){
        printf("ocorreu um erro na string entrada.txt");
    }
    catch (...){
        printf("ocorreu um erro entrada.txt");
    }
}

void Interface::indexarArquivo(FILE* _arquivo){

    if(_arquivo==0){
         throw(string("Ponteiro para arquivo invalido"));
    }
    fscanf(_arquivo," %d",&_numeroArquivos);
    if(_numeroArquivos<1){
        throw(string("Arquivo com entrada anormal(n<1)\n"));
    }
    logNumeroArquivo = log10(_numeroArquivos);
    _arquivoTexto = new Documento*[_numeroArquivos];
    int i;
    try{
        for(i=0;i<_numeroArquivos;i++){
            char* caminho= new char[MAX_ARQUIVO];
            fscanf(_arquivo," %s",caminho);
            indexarDocumento(caminho,i);
        }
        printf("\nNumeros de palavras indexadas:%d\n",tabela.contador);
        printf("\ntabela colisoes:%d\n",tabela.tempo);
        printf("\n\nINDEXADO COM SUCESSO...\n");

//        for(i=0;i<_numeroArquivos;i++){
//            printf("\n\"%s\" possui %d palavras distintas\n",_arquivoTexto[i]->getNomeDocumento(),_arquivoTexto[i]->getPalavraDistintas());
//        }
    }
    catch(int a){
        throw(a);
    }
    catch(string a){
        throw(a+"\n");
    }
    catch(...){
        throw("erro ao indexar o arquivo ");
    }

//  apt-get upgrade
}
void Interface::indexarDocumento(char* _entrada, int _arquivo){
    FILE * arq=fopen(_entrada,"r");
    if(arq==0){
        throw(string("Arquivo para indexar nao existe"));//ponteiro para todos os arquivos
    }
    //    qDebug() << " to aquiiii";
    _arquivoTexto[_arquivo]=new Documento(_entrada);
    char lerPalavra[MAX_PALAVRA];
    while(*lerPalavra=0,fscanf(arq," %s",lerPalavra)!=EOF){
        try{
            validaPalavra(lerPalavra);
            string chave(lerPalavra);
            if(tabela.conteins(chave)){
                if(tabela.getDado(chave).existePalavraLista(_entrada)){//arquivo já existe
                    DocPalavra aux=tabela[chave];
                    aux.getDocPalavra(_entrada)->incrementaNumeroVezesPalavra();
                    tabela.put(string(aux.getPalavra()),aux); // indexar na tabela
                }
                else{//arquivo não existe
                    ListaDePalavra aux2;
                    aux2.setDocumentoLista(_arquivoTexto[_arquivo]);
                    aux2.setNumeroPalavraLista(1);
                    DocPalavra auxPalavra = tabela.getDado(chave);
                    auxPalavra.addListaDeDoc(aux2);
                    tabela.put(chave,auxPalavra); //indexar na tabela hash
                    _arquivoTexto[_arquivo]->AdicionaPalavraDestintas(); //incrementa ++
                }
            }
            else{
                DocPalavra auxDocPala;
                ListaDePalavra auxPalavraListaPalavra;
                auxPalavraListaPalavra.setDocumentoLista(_arquivoTexto[_arquivo]);
                auxPalavraListaPalavra.setNumeroPalavraLista(1);
                auxDocPala.setPalavra(lerPalavra);
                auxDocPala.addListaDeDoc(auxPalavraListaPalavra);
                tabela.put(chave,auxDocPala); // indexa na tabela
                _arquivoTexto[_arquivo]->AdicionaPalavraDestintas(); //incrementa palavras destintas do documento
            }
        }

        catch(int a){
            if(a==0){
                throw(string("Tabela Hash cheia!"));
                printf("parando de indexar o arquivo %s , tabela hash cheia\n",_entrada);
                return;
            }
            printf("(erro: %d) palavra \"%s\" iguinorada\n",a,lerPalavra);
        }
        catch(...){
            printf("\nerro inesperado continuar\n");
        }
    }

}

char* Interface::convertChar(string palav){ //converte no em string
    int n=palav.size(), i;
    char *a = new char[n+1];
    for(i=0;i<n;i++){
        a[i]=palav[i];
    }
    a[i]='\0';
    return a;
}

void Interface::validaPalavra(char* palavra){ // converte palavra maiucaula para minuscula
    int i;
    for(i=0; palavra[i] != '\0'; i++){
        palavra[i] = tolower(palavra[i]); //Converter letras maiúsculas em minúsculas
    }
    i--;
    if(!(palavra[i] > 97 && palavra[i] <122)) //restinge se for caracter especial
        palavra[i] = '\0';
}

int compare(Relevancia palavra1,Relevancia palavra2){
    if(palavra1.getRelevancia() > palavra2.getRelevancia())
        return -1;
    if(palavra1.getRelevancia() < palavra2.getRelevancia())
        return 1;
    return 0;
}

void Interface::finalizar(){
    for(int i=0;i<_numeroArquivos ;i++){
        delete _arquivoTexto[i];
    }
    delete [] _arquivoTexto;
    delete [] _entradaArquivo;
    delete [] _retono;
    delete [] _arquivoRelevancia;
    tabela.clean();
    tabela.inicializarTabela(tabela.getTamanhoTabela());
}

string Interface::buscaPalavra(string _palavra, bool verdade){//bool caso true pelo menos uma palavra//caso false pelo todas

    string striRelevancia="";
    delete [] _arquivoRelevancia;
    _arquivoRelevancia = 0;
    int i;
    if(tabela.size()==0){
        throw(string("Antes de buscar, indexe os arquivos."));
    }
    buscaPalavraTermo(_palavra);
    for(i=0;i<_numRetorno;i++){
        if(tabela.conteins(_retono[i].getChave())){
            DocPalavra retoAux;
            retoAux = (tabela.getDado(_retono[i].getChave()));
            _retono[i].setDadoNode(retoAux);
        }
    }
    _numBuscado = _numRetorno;
   organizaRetorno();//a partir da ki as palavras est~ao organizadas dentro de retorno[];
    for(int z=0; z<_numRetorno; z++)
    {
        qDebug()<<"\nO retorno encontrado ["<<_retono[z].getChave().c_str()<<"] Num Arquivos: ["<<_retono[z].getDadoNode().getNumerosDocumentos()<<"]";;
    }

    if(_numBuscado != _numRetorno && !verdade){//impossivel fazer a busca de todos os termos, pois nem todos estao catalogados na tabela
        striRelevancia += "impossivel fazer a busca de todos os termos! nem todos estao indexados\n";
        return striRelevancia;
    }
//    if(_numRetorno==0){
//        striRelevancia += "Nao existe nelhum dos termos que procuras!!\n";
//        return striRelevancia;
//    }
//    if(verdade ||_numRetorno==1){//fazer união dos arquivos
//        uniao();
//    }
//    else{//fazer intersecção
//        interseccao();
//    }
//    calcularRelevancia();
//     //ordena crescente
//    heap.heapSort(_arquivoRelevancia, _numArquivosEmBusca, compare);
//   //fazer somatorio da string com nome dos arquivos
//    for(i=0;i<_numArquivosEmBusca;i++){
//        striRelevancia+= string(_arquivoRelevancia[i].getRelevanciaDocumento()->getNomeDocumento());
//        striRelevancia+= " -> relevancia:  " + QString::number(_arquivoRelevancia[i].getRelevancia()).toStdString();
//        striRelevancia+="\n";

//    }
    return striRelevancia;
}

void Interface::buscaPalavraTermo(string termo){
    int espacos=0,i,j;
    string a="";
    for(i=0;termo[i]!='\0';i++){
        if(termo[i] == ' ')espacos++;
    }
    char *pala = convertChar(termo);
    validaPalavra(pala);

    termo = string(pala);
    _numRetorno = espacos + 1;
 qDebug()<<"Tamanho _numReturno-> "<<_numRetorno;
    _retono = new Node<string,DocPalavra>[_numRetorno];//construtor para string

    for(i=0;i<_numRetorno; i++)
        _retono[i].setChave(string("777"));
    for(i=j=0; termo[i]!='\0';i++){
        if(termo[i]!=' ' && (termo[i]>=97 && termo[i] <= 122) ){
            a+=termo[i];
        }else
            if(termo[i]==' '){
                _retono[j++].setChave(a);
                a="";
            }
    }
    _retono[j].setChave(a);
}

void Interface::organizaRetorno(){
    int i,j;
    for(i=j=0;i<_numRetorno;i++){
        if(tabela.conteins(_retono[i].getChave())){
            _retono[j++]=_retono[i];
        }
    }
    _numRetorno=j;
    qDebug()<<"Foram encontradas palavras na busca"<<j<<"\n";
    //printf("\nForam encontradas %d palavras na busca\n",j);
    for(i=0;i<_numRetorno;i++){//adiciona palavra documento como dado no retorno
        _retono[i].setDadoNode(tabela[_retono[i].getChave()]);
    }
    for(i=_numArquivosEmBusca=0;i<_numRetorno;i++){
        _numArquivosEmBusca+=_retono[i].getDadoNode().getNumerosDocumentos();
    }
     qDebug()<<"Foram encontradas arquivos na buscaaaa"<<_numArquivosEmBusca<<"\n";
    //printf("Numero de arquivos encontradados %d \n" ,_numArquivosEmBusca);
//qDebug()<<" OOOOIII TO AQUI"<<_numRetorno;
}

void Interface::calcularRelevancia(){
    int i,j;
    float _relevancia;
    for(i=0;i<_numArquivosEmBusca;i++){
        _relevancia=0;
        int fij,dj;
        _arquivoRelevancia[i].setRelevancia(0);
        //calcular relevancia de cada arquivo a partir da ki
        for(j=0;j<_numRetorno;j++){
            ListaDePalavra *list= _retono[j].getDadoNode().getDocPalavra(_arquivoRelevancia[i].getRelevanciaDocumento()->getNomeDocumento());
            if(list==0){
                fij=0;
            }
            else{
                fij = list->getNumeroPalavraLista();
            }
            dj = _retono[j].getDadoNode().getNumerosDocumentos();
            _relevancia+=fij*(logNumeroArquivo/dj);
        }
        _arquivoRelevancia[i].setRelevancia((1.0/_arquivoRelevancia[i].getRelevanciaDocumento()->getPalavraDistintas())*_relevancia);
        printf("%s  \nRelevancia do arquivo e : %f\n\n",_arquivoRelevancia[i].getRelevanciaDocumento()->getNomeDocumento(), _arquivoRelevancia[i].getRelevancia());
    }
     qDebug()<<" OOOOIII TO AQUI NO CULC"<<_numRetorno;
}

void Interface::uniao(){
    int i,j=0;//palavras estão em retorno
    _arquivoRelevancia = new Relevancia[_numArquivosEmBusca];//fazer união dos arquivos
    for(i=0;i<_numRetorno;i++){//passar de palavra em palavra
        ListaDePalavra* lista = _retono[i].getDadoNode().getVetorDocumento();//em lista tenho todos os arquivos encontrados na palavra I
        int k,n;
        n = _retono[i].getDadoNode().getNumerosDocumentos();
        for(k=0;k<n;k++){//para cada documento da palavra i
            int cont=0;
            for(;cont<(j);cont++){//procurar se o arquivo k existe em arquivosRetorno
                if(strcmp(lista[k].getNomeDocumentoLista()->getNomeDocumento(),_arquivoRelevancia[cont].getRelevanciaDocumento()->getNomeDocumento())==0){
                    break;
                }
            }
            if(cont==j){//foi até o final e não encotrou nada
                _arquivoRelevancia[j++].setRelevanciaDocumento(lista[k].getNomeDocumentoLista());
            }
        }
        delete []lista;
    }
    _numArquivosEmBusca = j;
    //união ok, os arquivos que contem as palavras estão em arquivosRetorno e são numArquivosEnBusca
}

void Interface::interseccao(){
    int i,j,k=0,n,selecionaPrimeiro=0;
    _arquivoRelevancia = new Relevancia[_numArquivosEmBusca];
    ListaDePalavra** matrizBusca = new ListaDePalavra*[_numRetorno]; //numero de relevancia
    for(i=0;i<_numRetorno;i++){//
        matrizBusca[i] = _retono[i].getDadoNode().getVetorDocumento();
    }

    for(selecionaPrimeiro=0; selecionaPrimeiro < _retono[0].getDadoNode().getNumerosDocumentos(); selecionaPrimeiro++){
        bool busca=false;
        for(i=1;i<_numRetorno;i++){
            n = _retono[i].getDadoNode().getNumerosDocumentos();
            for(j=0;j<n;j++){
                if(strcmp(matrizBusca[0][selecionaPrimeiro].getNomeDocumentoLista()->getNomeDocumento(), matrizBusca[i][j].getNomeDocumentoLista()->getNomeDocumento())==0){
                    busca=true;
                    break;
                }
            }
            if(busca)break;
        }
        if(busca){//busca tudo e achei o arquivo
            _arquivoRelevancia[k++].setRelevanciaDocumento(matrizBusca[i][j].getNomeDocumentoLista());
        }
    }

    for(i=0;i<_numRetorno;i++){
        delete matrizBusca[i];
    }
    delete matrizBusca;
    _numArquivosEmBusca = k;
}
