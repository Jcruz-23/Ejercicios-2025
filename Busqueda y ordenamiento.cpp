#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenamiento(int*);
void busquedaMaxMin(int*);
void mostrar (int*);
int promedio (int*);

int main() {
	srand(time(NULL));
	int v[10] = {0};
	int max = 0;
	int min = 0;
	int dif = 0;
	
	for (int i = 0; i<10; i++){
		v[i] = (rand() %10) + 1; 		
	}
	
	mostrar(v);
	busquedaMaxMin(v);
	return 0;
}
	
void mostrar (int v[10]){
	printf("||||||||||||||||||||||||||||||||VECTOR|||||||||||||||||||||||||||||||||||||\n");
	for (int i = 0; i<10; i++){
		printf("%d\t", v[i]);
	}
	printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
}
	
void busquedaMaxMin (int v[10]){
	int max;
	int min;
	int dif;
	max = v[1];
	min = v[1];
	for(int i = 0; i<10-1; i++){
		for (int j = 0; j<10; j++){
			if (max<v[i]){
				max = v[i];
			}
		}
			
		for(int k = 0; k<10-1; k++){
			for (int h = 0; h<10; h++){
				if (min>v[h]){
					min = v[h];
				}
			}
		}
	}
	printf("\nValor máximo: %d", max);
	printf("\nValor minimo: %d", min);
		
	dif = max-min;
		
	printf("\nLa diferencia entre maximo y minimo es: %d",dif);
	
	int prom = promedio(v);
	
	printf ("\nEl promedio es:%d",prom);
	
	if((max-prom)>(prom-min)){
		printf("\nEl promedio es mas cercano al valor minimo");
	}else{
		printf("\nEl promedio es mas cercano al valor maximo");
	}
}
	

int promedio (int v [10]){
	int total = 0, prom = 0;
	for (int i = 0; i<10; i++){
		total += v[i];
	}
	prom = total/10;
	
	return prom;
}
	
void ordenamiento(int v [10]){
	
}
