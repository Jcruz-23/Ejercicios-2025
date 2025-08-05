/*Crear un programa que arme un arreglo de 5x5 de números 
aleatorios pares. Luego muestre el arreglo resultante.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 5
int main(int argc, char *argv[]) {
	int random = 0;
	int arreglo[FILAS][COLUMNAS];
	int i,j;
	printf("Matriz:\n");
	for( i = 0; i < FILAS; i++){
		for (j = 0; j < COLUMNAS; j++){
			random = rand() % 90 + 10;
			if(random%2 == 0){
				arreglo[i][j] = random;
			}else{
				j--;
			}
		}
	}
	
	
	for(i = 0; i < FILAS; i++){
		for (j = 0; j < COLUMNAS ; j++){
			printf(" %d", arreglo[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}
