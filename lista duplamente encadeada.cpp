//////////////////////////////////////////////////////////
//programa que implementa uma lista duplamente encadeada//
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};
//função que insere um no na lista

struct no *inserir(struct no *cabeca, int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		//cenário moleza: a lista está vazia
		cabeca = novoNo;
	} else {
		//cenário fudido: a lista não está vazia
		novoNo -> proximo = cabeca;
		cabeca -> anterior = novoNo;
		cabeca = novoNo;
	}
	return cabeca;
}
//função que imprime os nos da lista 

void imprimir(struct no *cabeca) {
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

//função que exclui um no na lista 

struct no *excluir(struct no *cabeca, int numero) {
	struct no *ponteiro = cabeca;
	
	while ((ponteiro != NULL) && (ponteiro -> numero != numero)) {
		ponteiro = ponteiro -> proximo;
	}
	
	if (ponteiro != NULL) {
		if (ponteiro == cabeca) {
			//caso facil: excluir o primeiro no da lista
			cabeca = cabeca -> proximo;
			cabeca -> anterior = NULL;
		}else if (ponteiro -> proximo == NULL) {
			//caso medio: excluir o ultimo no da lista
			ponteiro -> anterior -> proximo = NULL;
		} else {
			//caso dificil: excluir um no no meio da lista 
			ponteiro -> proximo -> anterior = ponteiro -> anterior;
			ponteiro -> anterior -> proximo = ponteiro -> proximo;
		}
	}
	return cabeca;
}
int main() {
	struct no *cabeca = NULL;
	
	cabeca = inserir(cabeca, 1);
	cabeca = inserir(cabeca, 2);
	cabeca = inserir(cabeca, 3);
	cabeca = inserir(cabeca, 4);
	cabeca = inserir(cabeca, 5);
	
	imprimir(cabeca);
	
	cabeca = excluir(cabeca, 1);
	cabeca = excluir(cabeca, 3);
	cabeca = excluir(cabeca, 5);
	cabeca = excluir(cabeca, 100);
	
	imprimir(cabeca);
}
