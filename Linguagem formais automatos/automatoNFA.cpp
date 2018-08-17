/* Autor: Kartik Kukreja
  Descrição: Programa para simular um dado NFA em uma string de entrada. Ele lê no
                        NFA de "NFA.txt" e as cadeias de entrada do console e imprime
                        Se as cadeias são aceitas ou rejeitadas no console.
 
                        "NFA.txt" deve ter o seguinte formato:
                                Nm
                                F a1 a2 ... af
                                T
                                S1 y1 T1 t1 t2 ... tt1
                                S2 y2 T2 t1 t2 ... tt2
                                :
                                :
                        Aqui, N -> Nº de estados (estados são numerados 0 ... N-1). 0 é o estado inicial
                                M -> Tamanho do alfabeto de entrada (os símbolos de entrada são
                                        Numerado 1 ... M e 0 é reservado para epsilon)
                                F -> Nº de estados finais, seguido por estados F (0 <= ai <= N-1)
                                T -> Nº de transições, seguidas por linhas T
                                Si -> Estado anterior (0 <= si <= N-1)
                                Yi -> Símbolo de entrada ou epsilon (0 <= yi <= M)
                                Ti -> Nº de estados, a NFA move-se a partir da entrada si em yi, seguida pelos estados Ti
*/

#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <set>
#include <bitset>
#include <cstring>
#define MAX_NFA_STATES 10
#define MAX_ALPHABET_SIZE 10
using namespace std;
 
// Representação de um estado NFA
class NFAstate {
    public:
        int transitions[MAX_ALPHABET_SIZE][MAX_NFA_STATES];
        NFAstate()  {
            for(int i=0; i<MAX_ALPHABET_SIZE; i++)
                for(int j=0; j<MAX_NFA_STATES; j++)
                    transitions[i][j] = -1;
        }
} *NFAstates;
 
set <int> NFA_finalStates;
bitset <MAX_NFA_STATES> currentStates;
char input_string[100000];
int N;
 
// Encontra o fechamento epsilon do estado NFA estado "e armazena-lo em "encerramento "
void epsilonClosure(int state, bitset<MAX_NFA_STATES> &closure )    {
    for(int i=0; i<N && NFAstates[state].transitions[0][i] != -1; i++)
        if(closure[NFAstates[state].transitions[0][i]] == 0)    {
            closure[NFAstates[state].transitions[0][i]] = 1;
            epsilonClosure(NFAstates[state].transitions[0][i], closure);
        }
}
 
// Encontra o encerramento epsilon de um conjunto de estados NFA "estado" e armazena-lo em "encerramento"
void epsilonClosure(bitset<MAX_NFA_STATES> state, bitset<MAX_NFA_STATES> &closure) {
    for(int i=0; i<N; i++)
        if(state[i] == 1)
            epsilonClosure(i, closure);
}
 
// Retorna um bitset que representa o conjunto de estados em que o NFA poderia estar depois de mover
// Do estado X no símbolo de entrada A
void NFAmove(int X, int A, bitset<MAX_NFA_STATES> &Y)   {
    for(int i=0; i<N && NFAstates[X].transitions[A][i] != -1; i++)
        Y[NFAstates[X].transitions[A][i]] = 1;
}
 
// Retorna um bitset que representa o conjunto de estados em que o NFA poderia estar depois de mover
// A partir do conjunto de estados X no símbolo de entrada A
void NFAmove(bitset<MAX_NFA_STATES> X, int A, bitset<MAX_NFA_STATES> &Y)   {
    bitset<MAX_NFA_STATES> tmp;
    for(int i=0; i<N; i++)
        if(X[i] == 1)
            NFAmove(i, A, tmp);
    Y = tmp;
}
 
int main()  {
    int M, F, X, Y, A, i, j, T, symbol;
    char* p;
 
    // Ler no subjacente NFA
    ifstream fin("nfaEntrada.txt");
    fin >> N >> M;
    NFAstates = new NFAstate[N];
    fin >> F;
    for(i=0; i<F; i++)    {
        fin >> X;
        NFA_finalStates.insert(X);
    }
    fin >> T;
    while(T--)   {
        fin >> X >> A >> Y;
        for(i=0; i<Y; i++)  {
            fin >> j;
            NFAstates[X].transitions[A][i] = j;
        }
    }
    fin.close();
 
    // Simular o NFA
    printf("Insira uma string ('.' to exit) : ");
    scanf("%[^\n]%*c", input_string);
    while(input_string[0] != '.')   {
        currentStates[0] = 1;
        epsilonClosure(currentStates, currentStates);
 
        p = strtok(input_string, " ");
        while(p)    {
            symbol = atoi(p);
            if(symbol <= 0 || symbol > M)   {
                printf("Símbolo inválido de entrada %d.\n", symbol);
                return -1;
            } else {
                NFAmove(currentStates, symbol, currentStates);
                epsilonClosure(currentStates, currentStates);
            }
            p = strtok(NULL, " ");
        }
 
        for(i = 0; i < N; i++)
            if(currentStates[i] == 1 && NFA_finalStates.find(i) != NFA_finalStates.end())
                break;
 
        if(i < N)
            printf("String accepted.\n");
        else
            printf("String rejected.\n");
 
        printf("Insira uma string('.' to exit) : ");
        scanf("%[^\n]%*c", input_string);
    }
 
    return 0;
}
