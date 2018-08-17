#include <iostream>
//#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define INICIO 0
#define S1 1
#define S2 2
#define S3 3
#define ERRO 4

int mais(){
	
	int estado = 0;
	string cadeia;
	cout << "Insira cadeia\n";
	cin >> cadeia;
	char* cadeiaConvert = strdup(cadeia.c_str());
	for(int i=0; cadeia.length(); i++){
		switch (estado){
			case INICIO:
			if(cadeiaConvert[i] == 'h'){
				estado = S1;
			}
			else estado = ERRO;
			break;
			
			case S1:
			if(cadeiaConvert[i] == 'o'){
				estado = S2;
			}
			else estado = ERRO;
			break;
			
			case S2:
			if(cadeiaConvert[i] == 'l'){
				estado = S3;
			}
			else estado = ERRO;
			break;
			
			case S3:
			if(cadeiaConvert[i] == 'a'){
				cout << "Cadeia Permitida\n";
			}
			else estado = ERRO;
			break;
			
			case ERRO:
			cout << "Cadeia não Permitida\n";
			i = cadeia.length() +100;
			break;
			
		}
	}
	
	
	getchar();
	return 0;
}
