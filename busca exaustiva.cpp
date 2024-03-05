sq/////////////////////////////////////////////////////
//programa que implementa a busca exaustiva//////////
/////////////////////////////////////////////////////

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

////////////////////////////////////////////////////
//função principal de execução do programa//////////
////////////////////////////////////////////////////

int main(){
	//declaração de variáveis
	int vetor[100000];
	int i;
	int procura;
	int achei;
	
	//inicialização da aleatoriedade
	time_t t;
	srand(time(&t));
	
	//preenchimento do vetor
	for (i=0;i<100000;i++){
		vetor[i]=(rand() % 100000);
		
	}
	
	//definir o parâmetro de pesquisa
	printf("digite o valor a ser buscado: ");
	scanf("%d", &procura);
	
	//busca exaustiva propriamente dita
	achei = -1;
	for (i=0;i<100000;i++){
		if (vetor[i] == procura){
			achei = i;
			break;
		}
	}
	
	//resposta
	if(achei==-1){
		printf("me fodi | não encontrei \n");
	} else {
		printf("encontrei na posição %d\n");
	}
}
