#include <stdio.h>
#include <stdlib.h>

//declaração de estrutura do no 

struct no {
	int numero;
	struct no *proximo;
};

//função que insere um no na lista

struct no *inserir(struct no *cabeca, int numero) {
	//criação do novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		// Caso facil : lista esta vazia 
		cabeca = novoNo;
		novoNo -> proximo = cabeca;
	} else {
		//Caso dificil: lista NAO esta vazia
		struct no *ponteiro = cabeca;
		
		while(ponteiro -> proximo != cabeca){
			ponteiro = ponteiro -> proximo;
		}
		ponteiro -> proximo = novoNo;
		novoNo -> proximo = cabeca;
	}
	return cabeca;
}

void imprimir(struct no *cabeca) {
	struct no *ponteiro = cabeca;
	int flag = (cabeca != NULL);
	
	while (flag) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
		flag = (ponteiro != cabeca);
	}
}
struct no *excluir(struct no *cabeca, int numero) {
	struct no *ponteiro = cabeca;
	
	if (cabeca != NULL) {
		if (cabeca -> numero == numero) {
			//caso dificil: excluir o primeiro no 
			while (ponteiro -> proximo != cabeca) {
				ponteiro = ponteiro -> proximo;
			}
			ponteiro -> proximo = cabeca -> proximo;
			ponteiro = cabeca;
			cabeca = cabeca -> proximo;
			if (cabeca == cabeca -> proximo) {
				cabeca == NULL;
			}
			free(ponteiro);
		} else {
			//caso dificil 2: excluir qualquer outro no da lista
			while ((ponteiro -> proximo != cabeca) && (ponteiro -> proximo -> numero != numero)) {
				ponteiro = ponteiro -> proximo;
			}
			if (ponteiro -> proximo != cabeca) {
				struct no *limpar = ponteiro -> proximo;
				ponteiro -> proximo = ponteiro -> proximo -> proximo;
				free(limpar);
			}
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
	
	printf("Apos inserir: \n");
	imprimir(cabeca);
	
	cabeca = excluir(cabeca, 1);
	cabeca = excluir(cabeca, 3);
	cabeca = excluir(cabeca, 5);
	cabeca = excluir(cabeca, 100);
	
	printf("\n\nApos excluir: \n");
	imprimir(cabeca);
}
