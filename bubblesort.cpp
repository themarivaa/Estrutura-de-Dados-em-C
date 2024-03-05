//////////////////////////////////////////
//programa que implementa o bubblesort////
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////////////
//declaração de variáveis/////////////////
//////////////////////////////////////////

int vetor[1000];
int i;
int j;
int troquei;

//////////////////////////////////////////
//função principal de execução do programa
//////////////////////////////////////////

int main(){
	//inicialização da aleatoriedade
	time_t t;
	srand(time(&t));
	
	//preenchimento do vetor
	for(i=0;i<1000;i++){
		vetor[i]=(rand()%1000);
	}
	
	//impressão do vetor
	for (i=0;i<1000;i++){
		printf("%d\t", vetor[i]);
	}
	//ordenação propriamente dita
	troquei=1;
	while(troquei){
		troquei=0;
		
		for (i=0; i<999; i++){
			if (vetor[i]>vetor[i+1]){
				int temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				
				troquei = 1;
			}
		}
	}
	
	//impressão do vetor
	printf("\n=======================================================================================================================\n");
	for (i=0;i<1000;i++){
		printf("%d\t", vetor[i]);
	}
}
