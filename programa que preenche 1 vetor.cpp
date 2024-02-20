////////////////////////////////////////
// PROGRAMA QUE PREENCHE UM VETOR :D ///
////////////////////////////////////////

#include <stdio.h>

////////////////////////////////////////
// declaração de variáveis /////////////
////////////////////////////////////////

int vetor[10]; 
int i; 

////////////////////////////////////////
// função principal de execução do programa 
////////////////////////////////////////

int main(){
	// mandar o usuário preencher o vetor
	for (i=0 ; i<10 ; i++) {
		printf("digite o valor da posição %d do vetor: ", i);
		scanf("%d", &vetor[i]);
	}
	
	//imprimir o vetor na tela
	for (i=0; i<10; i++) {
		printf("vetor[%d] = %d\n", i, vetor[i]);
	}
}
