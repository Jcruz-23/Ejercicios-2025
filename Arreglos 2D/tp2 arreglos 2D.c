#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	int matriz [10][10] = {0};
	int suma = 0;
	int prom = 0;
	int i = 0, j = 0;
	int num = 0;
	int contNum = 0;
	printf("Ingrese un numero del 10 al 99\n");
	scanf(" %d", &num);
	
	srand(time(NULL));
	
	for(i = 0; i<10; i++){
		for (j = 0; j<10; j++){ 
		matriz[i][j] = 	rand() % 90 + 10;
		suma += matriz[i][j];
		}
	}
		
	for(i = 0; i<10; i++){
		for (j = 0; j<10; j++){ 
			if(matriz[i][j] == num){
				contNum++;
			}
		}	
	}
	
	printf("El numero ingresado se encuentra %d veces en la matriz\n\n", contNum);
	
	printf("Matriz:\n");
	for(i = 0; i<10; i++){
		for (j = 0; j<10; j++){
			printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}
	prom = suma/100;
	printf("el promedio de los valores es: %d\n\n",prom);
	
	
	printf("los valores pares de la función son:\n");
	for(i = 0; i<10; i++){
		for (j = 0; j<10; j++){ 
			if(matriz[i][j]%2 == 0){
				printf("%d ; ",matriz[i][j]);
			}
		}
	}
	return 0;
	}

