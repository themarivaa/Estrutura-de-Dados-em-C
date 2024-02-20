//////////////////////////////////////////////////
// programa de transposiçao de matrizes //////////
//////////////////////////////////////////////////

#include <stdio.h>

int matriz[2][3];
int transposta[3][2];
int i;
int j;

int main(){
	for (i=0; i<2; i++){
		for (j=0; j<3; j++){
			printf("matriz [%d, %d] = ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	//transposição 
	for (i=0; i<2; i++) {
		for (j=0; j<3; j++){
			transposta[j][i]=matriz[i][j]
		}
	}
	
	for (i=0; i<2; i++) {
		for (j=0; j<3; j++){
		printf("%d\t", matriz[i][j])
		}
		printf("\n)
	}
}
