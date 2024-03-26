////////////////////////////////////
//programa que implementa uma fila//
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//declaração da estrutura do no 

struct no {
	int numero;
	struct no *proximo;
};

//função que insere um no na fila

struct no *inserir(struct no *cabeca, int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	
	//posicionamento do novoNo na entrada da fila
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
	
	return cabeca;
}

//função que remove o no da fila

struct no *remover(struct no *cabeca) {
	//caso da lista estar vazia 
	if (cabeca == NULL) {
		printf("-99\n");
		return cabeca; 
	}
	
	//caso da lista ter apenas 1 no 
	if (cabeca -> proximo == NULL) {
		printf("%d\n", cabeca -> numero);
		free(cabeca);
		cabeca = NULL;
		return cabeca;
	}
	
	//caso a lista tem mais de 1 no 
	//posicionar ponteiro no primeiro no da lista
	struct no *ponteiro = cabeca;
	while (ponteiro -> proximo -> proximo != NULL) {
		ponteiro = ponteiro -> proximo;
	}
	
	printf("%d\n", ponteiro -> proximo -> numero);
	free(ponteiro -> proximo); 
	ponteiro -> proximo = NULL;
	return cabeca;
}

//função de execução
int main(){
	//declaração de variáveis 
	struct no *cabeca = NULL;
	int i =0;
	
	cabeca = remover(cabeca);
	cabeca = inserir(cabeca, 1);
	cabeca = remover(cabeca);
			
	for (i = 0 ; i < 100 ; i++){
		cabeca =  inserir(cabeca, i);
	}
	for (i = 0 ; i < 100 ; i++){
		cabeca = remover(cabeca);
	}
	cabeca = remover(cabeca);
}
