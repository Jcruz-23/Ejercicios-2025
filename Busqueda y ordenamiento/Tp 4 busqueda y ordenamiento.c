#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <time.h>
void menu(int*, char [][50] );
void ordenamiento (int*, char [][50]);
void mostrar (int*, char[][50]);
void calificacion (int*);
void grupos (int*, char [][50]);

int main() {
char nombres[10][50] = {
	"Sanchez",
	"Garzon",
	"Segarra",
	"Suarez",
	"Juarez",
	"Bravo",
	"Darrul",
	"Coyla",
	"Riganti",
	"Llabre"
};
int notas [10] = {0};

calificacion(notas);

menu(notas,nombres);
return 0;
}

void calificacion(int notas[10]){
	srand(time(NULL));
	for(int i = 0; i<10; i++){
		notas[i] = rand() %10 + 1;
	}
}

void mostrar (int notas[10], char nombres[10][50]){
	for(int i = 0; i < 10; i++){
		printf("%s: %d\n", nombres[i], notas[i]);
	}
}
	
void ordenamiento(int notas[10], char nombre[10][50]){
	int aux;
	char auxNombre[50] = {" "};
	for(int i = 0; i<10 - 1; i++){
		for(int j = 0; j<10 - 1; j++){
			if(notas[j] < notas [j + 1]){
			aux = notas [j];
			notas [j] = notas [j + 1];
			notas [j + 1] = aux;
			
			strcpy(auxNombre,nombre[j]);
			strcpy(nombre[j],nombre [j + 1]);
			strcpy(nombre [j + 1],auxNombre);
			}
		}
	}
}


	

	

	

void menu(int notas[10], char nombres[10][50]){
	int opcion = 0;
	char fin = ' ';
	do{
	system("cls");
	printf("Elija una opcion\n");
	printf("1-Mostrar notas\n2-ordenar notas\n");
	scanf("  %d", &opcion);
	switch (opcion){
	    case 1:
		printf("\n");
		 mostrar(notas, nombres);
		 printf("\n");
		 break;
	    case 2:
		printf("\n");
		 ordenamiento(notas, nombres);
		 mostrar(notas, nombres);
		 printf("\n");
		 break;
		default: 
		 printf("error!!\t ingrese una opcion correcta\n\n");
		 break;
    }
	
	printf("desea salir? s/n");
	scanf(" %c", &fin);
	
	} while(fin == 'n' || fin == 'n');
}
