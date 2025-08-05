#include <stdio.h>

int main() {
	int i;
	int mult = 0;
	int r = 0;
	
	printf("Ingrese un numero el cual quiere saber su tabla completa: ");
	scanf(" %d", &mult);

	for(i = 0;i<=10;i++){
		r =  mult* i;
		printf("\n %d", r);
	}
	
	
	return 0;
}

