#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ingresarLista(char[][50]);
void mostrarLista(char[][50]);
void menu(char[][50]);
void busqueda(char[][50]);
int main(){

	char nombres[10][50];
	menu(nombres);
	int opcion = 0;
	char fin = ' ';
	return 0;
}

void ingresarLista(char lista[10][50]){
	for(int i = 0; i <10; i++){
		system("cls");
		gets(lista[i]);
	}
}
void mostrarLista(char lista[10][50]){
	for(int j = 0; j<10; j++){
		printf("%s\n",lista[j]);
	}
}
	
void menu(char lista[10][50]){
	int opcion = 0;
	char fin = ' ';
	
	do{
		system("cls");
		printf("elija una opcion\n1-Ingresar lista de alumnos\n2-Mostrar lista\n3-Buscar alumno\n");
		scanf(" %d",&opcion);
		while ((getchar()) != '\n');//evita error con el gets() de la funcion ingresarlista()
		switch (opcion){
		case 1:
			ingresarLista(lista);
			system("cls");
			break;
		case 2: 
			mostrarLista(lista);
	
			break;
		case 3:
			busqueda(lista);
			break;
		}
		printf("desea salir del programa? s/n\n");
		scanf(" %c", &fin);
	} while(fin == 'n'||fin == 'N');
}
	
void busqueda(char lista[10][50]){
	char nombre [50] = {' '};
	int comparacion = 0;
	printf("Intrese el nombre que quiera buscar: \n");
	gets(nombre);
	
	for(int i = 0; i < 10; i++){
		comparacion = strcmp(nombre,lista[i]);
		if(comparacion == 0){
			printf("Posicion %d: %s\n", i+1, lista[i]);
		}
	}
}
