#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaração de quantidade de vértices do grafo

#define VERTICES 600

//função que cria o grafo

void criar(int grafo[VERTICES][VERTICES]) {
	int i = 0;
	int j = 0;
	int adjacencia = 0;
	
	for (i = 0; i < VERTICES; i++){
		for (j = 0; j < VERTICES; j++){
			grafo[i][j] = 0;
		}
	}
	
	for (i = 0 ; i < (VERTICES - 1) ; i++) { //primeiro ao penúltimo
		for (j = (i + 1) ; j < VERTICES ; j++) { //próximo ao último
			//printf("Digite <l> se %d for adjacente a %d: ", i, j);
			
			//scanf("%d", &adjacencia);
			adjacencia =(rand() % 2); 
			grafo[i][j] = adjacencia;
			grafo[j][i] = adjacencia;
		}
	}
}

//função que imprime o grafo

void imprimir (int grafo[VERTICES][VERTICES]) {
	int i = 0;
	int j = 0;
	
	printf("V: adjacencias \n");
	
	for (i = 0; i < VERTICES; i++) {
		printf("%d: ", i);
		for (j = 0; j< VERTICES; j++){
			if (grafo [i][j]){
				printf("%d", j);
			}
		}
		printf("\n");
	}
	printf("\n");
}

//função que descobre o vértice de maior grau

int descobrirMaiorGrau(int grafo[VERTICES][VERTICES]){
	int i = 0;
	int j = 0;
	int grau = 0;
	int maiorGrau = 0;
	int vertice = 0;
	
	for (i = 0; i < VERTICES; i++){
		grau  = 0;
		for (j = 0; j< VERTICES; j++){
			if (grafo[i][j]){
				grau++;
			}
		}
		if (grau > maiorGrau){
			maiorGrau = grau;
			vertice = i;
		}
	}
	return vertice;
}

int main(){
	
	int grafo[VERTICES][VERTICES];
	
	time_t t;
	srand(time(&t));
	
	criar(grafo);
	imprimir(grafo);
	
	printf("vértice de maior grau: %d\n", descobrirMaiorGrau(grafo));
}
