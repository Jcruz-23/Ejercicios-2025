#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int rouds = 0;
	int colums = 0;
	
	printf("Ingrese tamaño de la matriz");
	printf("\nX: ");
	scanf(" %d", &rouds);
	printf("\nY: ");
	scanf(" %d", &colums);
	
	
	for(i = 0; i<rouds; i++){
		for(j=0;j<colums; j++){
		printf("fila: %d\n columna: %d\n",i,j);
	}
}
	return 0;
}

