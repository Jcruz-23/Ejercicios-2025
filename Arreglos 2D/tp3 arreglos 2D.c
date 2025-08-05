#include <stdio.h>

int main() {
	int columnas = 0;
	float lista [5][4] = {0};
	
	float num = 0;
	
	
	printf("ingrese: \n1-El codigo del producto\n2-El precio unitario\n3-cantidad del producto\n");
	
	
	for(int i = 0; i<5; i++){
		for(int j = 0; j<4; j++){
			scanf(" %.1f", &num);
			lista[i][j] = num;
		}
	}
	
	for(int i = 0; i<5; i++){
		for(int j = 0; j<4; j++){
			printf(" %.1f\n", lista[i][j]);
		}
		printf("\n");
	}
return 0;
}
	
	
