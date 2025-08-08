#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarCronograma(int [][5]);
void mostrarEstadoOficina(int [][5]);
void actualizarEstado(int [][5]);
int calcularCantidadSinLimpiar(int [][5]);
void menu(int [][5]);
int main() {
	int oficina[5][5] = {0};
	menu(oficina);
	return 0;
}

void generarCronograma(int oficina[5][5]){
	for(int i = 0; i<5; i++){
		oficina[i][0] = i+1;
		oficina[i][1] = i+1;
		oficina[i][2] = rand()%9+8;
		oficina[i][3] = rand()%900+100;
		oficina[i][4] = 1;
	}
}

void mostrarEstadoOficina(int oficina[5][5]){
	for(int i = 0; i<5; i++){
		for(int j = 0; j<5; j++){
			printf("%d\t", oficina[i][j]);
		}
		printf("\n");
	}
}

void actualizarEstado(int oficina[5][5]){
	system("cls");
	int num = 0;
	int est = 0;
	printf("Incerte numero de oficina(del 1 al 5):\n");
	scanf(" %d", &num);
	if(num<=5){
		printf("cambiar estado\n 1.sucio\n 2.limpio\n");
		scanf(" %d", &est);
		oficina[num-1][4] = est;
	}else{
		printf("oficina inexistente");
	}
	
}
	
int calcularCantidadSinLimpiar(int oficina[5][5]){
	int cant = 0;
	for(int i = 0; i<5;i++){
		if(oficina[i][4] == 1){
			cant++;
		}
	}
	
	return cant;
}
	
	
void menu(int oficina [5][5]){
	int opcion;
	char fin = ' ';
	int flag = 0;
	int cant = 0;
	do{
		system("cls");
		printf("Seleccione una opcion\n1)Generar cronograma\n2)Mostrar estado de oficina\n3)Actualizar estado de oficina\n4)Cantidad de oficinas sin limpiar\n");
		scanf(" %d", &opcion);
		switch(opcion){
		case 1:
			if(flag == 1){
				printf("Cronograma ya generado\n\n");
			}else{
				flag = 1;
				generarCronograma(oficina);
				printf(". . .\n");
				printf(". . .\n");
				printf(". . .\n");
				printf(". . .\n");
				printf("\nOficina generada!\n");
			}  
			break;
		case 2: 
			if(flag == 1){
				mostrarEstadoOficina(oficina);
			}else{
				printf("\a¡Cronograma sin generar!\nSeleccione la opcion 1 para generar programa");
			}
			break;
		case 3:
			if(flag == 1){
				actualizarEstado(oficina);
			}else{
				printf("\a¡Cronograma sin generar!\nSeleccione la opcion 1 para generar programa");
			}
			break;
		case 4:
			if(flag == 1){
				calcularCantidadSinLimpiar(oficina);
				cant = calcularCantidadSinLimpiar(oficina);
				
				printf("Cantidad de oficinas sin limpiar: %d\n", cant);
			}else{
				printf("\a¡Cronograma sin generar!\nSeleccione la opcion 1 para generar programa");
			}
			break;
		default: 
			printf("¡ERROR!");
		}
	printf("Desea seleccionar otra opcion? s/n");
	scanf(" %c", &fin);
	} while(fin == 's'||fin == 'S');
}
