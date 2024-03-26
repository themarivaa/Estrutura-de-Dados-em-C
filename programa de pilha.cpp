/////////////////////////////////////
//programa que implementa uma pilha//
/////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

struct no {
	int numero;
	struct no *proximo;
};

//função que insere um no na pilha

struct no *push(struct no *cabeca, int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	
	//posicionamento do novoNo na entrada da pilha
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
	
	return cabeca;
}

//função que remove um no da pilha

struct no *pop(struct no *cabeca){
	//caso da pilha estar vazia 
	if (cabeca == NULL) {
		printf("-99\n"); 
		return cabeca;
	}
	//caso da pilha NÃO estar vazia 
	printf("%d\n", cabeca -> numero);
	struct no *ponteiro = cabeca;
	cabeca = cabeca -> proximo;
	free(ponteiro);
	return cabeca;
}
//função principal de execução do programa 
int main(){
	struct no *cabeca = NULL;
	int i = 0;
	
	cabeca = pop(cabeca);
	
	cabeca = push(cabeca, 1);
	cabeca = pop(cabeca);
	
	for (i=0; i<100; i++) {
		cabeca = push(cabeca, i);
	}
	for (i=0; i<100; i++) {
		cabeca = pop(cabeca);
	}
	cabeca = pop(cabeca);
}
