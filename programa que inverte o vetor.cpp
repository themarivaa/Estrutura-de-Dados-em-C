// inversão de vetores //
# include  <stdio.h>

int vet[5];
int vetinv[5];
int i;

int main(){
	for (i = 0; i < 5; i++) {
		printf("digite o valor da posição %d do vetor: ", i);
		scanf("%d", &vet[i]);
	}
	//inverter o vetor
	for (i = 0; i < 5; i++) {
		vetinv[4-i] = vet[i];
	}
	//imprimir o vetor na tela
	for (i = 0; i < 5; i++) {
		printf("vet[%d]=%d\n", i, vet[i]);
	}
	for (i = 0; i < 5; i++) {
		printf("vetinv[%d]=%d\n", i, vetinv[i]);
}
}
