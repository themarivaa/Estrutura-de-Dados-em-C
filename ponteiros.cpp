#include <stdio.h>
#include <stdlib.h>

struct no {
	int n; struct no *proximo;
};

//função que insere um no na lista//

struct no *inserir(struct no *cabeca, int parametroNumero){
	
	//alocação de memória
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	
	//atribuição de valores
	novoNo -> n = parametroNumero;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL){
		//lista está vazia//
		cabeca = novoNo;
	} else {
		struct no *ponteiro = cabeca;
		
		while (ponteiro -> proximo != NULL){
			ponteiro = ponteiro -> proximo;
		}
		
		ponteiro -> proximo = novoNo;
	}
	return cabeca;
}

struct no *remover(struct no *cabeca, int parametroNumero){
	struct no *ponteiro = cabeca;
	
	while ((ponteiro != NULL) && (ponteiro -> n != parametroNumero)) {
		ponteiro = ponteiro -> proximo;
	}
	
	if (ponteiro != NULL) {
		if (ponteiro == cabeca) {
			//remover o primeiro no da lista
			cabeca = cabeca -> proximo;
		} else {
			//remover um no meio da lista 
			struct no *anterior = cabeca;
			
			while (anterior -> proximo != ponteiro) {
				anterior = anterior -> proximo;
			}
			anterior -> proximo = anterior -> proximo -> proximo;
		}
		free(ponteiro);
	}
	return cabeca;
}
int main(){
	struct no *cabeca = NULL;
	
	cabeca = inserir(cabeca,1);
	cabeca = inserir(cabeca,2);
	cabeca = inserir(cabeca,3);
	cabeca = inserir(cabeca,4);
	cabeca = inserir(cabeca,5);
	cabeca = inserir(cabeca,6);
	cabeca = inserir(cabeca,7);
	
	cabeca = remover(cabeca,1);
	cabeca = remover(cabeca,4);
	cabeca = remover(cabeca,7);
	
	struct no *ponteiro = cabeca;
	while (ponteiro != NULL){
		printf("%d\n", ponteiro -> n);
		ponteiro = ponteiro -> proximo;
	}

}
