#include <stdio.h>
/*Realice un programa que permita cargar 5 números enteros en un vector. Luego 
calcule el promedio de ellos. Finalmente mostrar todos los valores y su promedio*/

int main() {
	int vector[5];
	int sumaVector = 0;
	int promedio = 0;
	printf("Ingrese 5 enteros\n");
	for(int i = 0; i<5; i++){
		scanf(" %d", &vector[i]);
		sumaVector += vector[i];
	}
	promedio = sumaVector/5;
	printf("El promedio de los enteros ingresados es: %d\n", promedio);
	return 0;
}

