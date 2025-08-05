#include <stdio.h>

int main() {
	/*Realice un programa que permita cargar el abecedario en un vector. Luego muestre el abecedario ingresado.*/
	char abc[26];
	char letraMayus = 65;
	char letraMinus = 97;
	for(int i = 0; i < 26; i++){
		printf(" %c", letraMayus);
		letraMayus++;
	}
	printf("\n\n");
	for(int i = 0; i <26; i++){
		printf(" %c", letraMinus);
		letraMinus++;
	}
	return 0;
}

