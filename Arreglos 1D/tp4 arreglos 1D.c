#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Crear un arreglo de 10 números enteros y aleatorios. Luego mostrar los valores pares*/
int main() {
	int valores[10] = {0};
	int random = 0;
	srand(time(NULL));
	for(int i = 0; i<=(10-1); i++){
		random = rand()%90+10;
		valores [i] = random;
		if(valores[i]%2 == 0){
			printf(" %d", valores[i]);
		}
	}
	
	return 0;
}

