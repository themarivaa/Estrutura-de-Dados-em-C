///////////////////////////////////////////////////
//programa que implementa busca binária////////////
///////////////////////////////////////////////////

#include <stdio.h>

int main(){
	//declaração de variáveis
	int vetor[100000];
	int i;
	int procura;
	int achei;
	int minimo;
	int maximo;
	int medio;
	
	//preenchimento do vetor 
	for (i=0; i<100000;i++){
		vetor[i]=i;
	}
	//definir o parâmetro da pesqusia
	printf("digite o valor a ser buscado: ");
	scanf("%d", &procura);
	
	//busca binária propriamente dita 
	minimo=0;
	maximo=99999;
	while(maximo>minimo){
		medio=((minimo+maximo)/2);
		if (vetor[medio]==procura){
			achei=medio;
			break;
		} else if (vetor[medio]>procura){
			maximo=medio-1;
		} else {
			minimo=medio+1;
		}
	}
	
}
