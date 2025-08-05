#include <stdio.h>

int main() {
	float i = 0;
	float suma = 0;
	float num = 0;
	float prom = 0;
	
	printf("Ingrese 5 valores\n");
	for(i=1;i<=5;i++){
		scanf(" %f", &num);
		suma += num;
	}
	prom = suma/i;
	printf("\nLa suma de los valores es: %.2f", suma);
	printf("\nEl promedio de estos valores es: %.2f", prom);
	
	return 0;
}

