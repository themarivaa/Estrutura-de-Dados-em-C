#include <stdio.h>
#include <stdlib.h>

//declaraçao do no 
struct no {
	int numero;
	struct no *proximo;
};

struct deque {
	struct no *normal;
	struct no *preferencial;
};
//funçao que insere um no no deque
struct no *entrar(struct no *fila, int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = fila;
	fila = novoNo;
	return fila;
}
//funçao que remove um no da fila 

struct no *sair(struct no *fila) {
	//cenario que a fila esta vazia 
	if (fila == NULL) {
		return fila;
	}
	//cenario que a fila nao esta vazia 
	if (fila -> proximo == NULL) {
		printf("%d\n", fila -> numero);
		free(fila);
		fila = NULL;
		return fila; 
	}
	
	//cenario que a fila ter mais de um no
	struct no *ponteiro = fila;
	
	while (ponteiro -> proximo -> proximo != NULL) {
		ponteiro = ponteiro -> proximo;
	}
	printf("%d\n", ponteiro -> proximo -> numero);
	free(ponteiro -> proximo);
	ponteiro -> proximo = NULL;
	return fila;
}
//funçao que atende (retira um no de alguma fila)

int atender(struct deque *cabeca, int preferencia) {
	if (cabeca -> preferencial == NULL) {
		cabeca -> normal = sair(cabeca -> normal);
		preferencia = 3;
	} else if (preferencia > 0) {
		printf("p");
		cabeca -> preferencial = sair(cabeca -> preferencial);
		preferencia--;
		if (cabeca -> normal != NULL) {
			preferencia--;
		}
	} else {
		cabeca -> normal = sair(cabeca -> normal);
		preferencia = 3;
	}
	return preferencia;
}
//funçao principal
int main(){
	struct deque filas;
	
	int i = 0;
	int preferencia = 3;
	
	filas.normal = NULL;
	filas.preferencial = NULL;
	
	preferencia = atender(&filas, preferencia);
	
	for (i=0; i<10; i++) {
		filas.normal = entrar(filas.normal, i);
	}
	for (i=0; i<10; i++) {
		filas.preferencial = entrar(filas.preferencial, i);
	}
	for (i=0; i<20; i++) {
		preferencia = atender(&filas, preferencia);
	}
	preferencia = atender(&filas , preferencia);
}
