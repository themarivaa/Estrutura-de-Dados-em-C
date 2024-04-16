//programa que implementa uma arvore de ordem 5 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct no {
	int numero;
	struct no *filho1;
	struct no *filho2;
	struct no *filho3;
	struct no *filho4;
	struct no *filho5;
};

//função que insere um no na arvore

struct no *inserir(struct no *raiz, int numero) {
	if (raiz == NULL){
	//caso fácil: árvore vazia (inserir novo no na raiz)
	raiz = (struct no *) malloc(sizeof(struct no));
	raiz -> numero = numero;
	raiz -> filho1 = NULL;
	raiz -> filho2 = NULL;
	raiz -> filho3 = NULL;
	raiz -> filho4 = NULL;
	raiz -> filho5 = NULL;
	
	} else {
		//caso difícil: árvore não vazia (sortear filho)
		int sorteioFilho = (rand() % 5); 
		
		switch (sorteioFilho) {
			case 0:
				raiz -> filho1 = inserir(raiz -> filho1, numero);
				break;
			case 1: 
				raiz -> filho2 = inserir(raiz -> filho2, numero);
				break;
			case 2: 
				raiz -> filho3 = inserir(raiz -> filho3, numero);
				break;
			case 3: 
				raiz -> filho4 = inserir(raiz -> filho4, numero);
				break;
			case 4: 
				raiz -> filho5 = inserir(raiz -> filho5, numero);
				break;
		}
	}
	//caso fácil com a árvore vazia (inserir na raiz)
	return raiz;
}

//função que imprime a árvore

void imprimir(struct no *raiz, char *indentacao, char *filho){
	if (raiz != NULL){
		//imprimir o número da raiz 
		printf("%s(%s)%d\n", indentacao, filho, raiz -> numero);
		
		//ajustar a indentação
		char * novaIndentacao = (char *) malloc(sizeof(1048576));
		strcpy(novaIndentacao, "---");
		strcat(novaIndentacao, indentacao);
		
		//imprimir os filhos 
		imprimir(raiz -> filho1, novaIndentacao, "f1");
		imprimir(raiz -> filho2, novaIndentacao, "f2");
		imprimir(raiz -> filho3, novaIndentacao, "f3");
		imprimir(raiz -> filho4, novaIndentacao, "f4");
		imprimir(raiz -> filho5, novaIndentacao, "f5");
	}
}
int main(){
	//declaração de variáveis
	struct no *raiz = NULL;
	int i = 0;
	
	//inicialização  da aleatoriedade
	time_t t;
	srand(time(&t));
	
	//inserçao de nos 
	for (i = 0; i < 10; i++) {
		raiz = inserir(raiz, i);
	}
	
	//impressao da arvore 
	imprimir(raiz, "", "raiz");
}
