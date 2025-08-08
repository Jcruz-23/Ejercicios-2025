#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 6 
#define COLUMNAS 9
#define pFILAS 3
#define pCOLUMNAS 5

void preciosFc(int [][pCOLUMNAS]);
void mostrarPrecios(int [][pCOLUMNAS]);
void reservasFc(int [][pCOLUMNAS], int [][COLUMNAS]);
void mostrarReservas(int [][pCOLUMNAS], int [][COLUMNAS]);
int main() {
	srand(time(NULL));
	int reservas[FILAS][COLUMNAS];
	int precios[pFILAS][pCOLUMNAS] = {0};
	
	
	reservasFc(precios, reservas);
	return 0;
}

void preciosFc(int precios[pFILAS][pCOLUMNAS]){
	//N° de cabaña
	for(int i = 0; i < pFILAS; i++){
		precios[i][0] = i+1;
	}
	//cant. personas
	precios[0][1] = 2;
	precios[1][1] = 4;
	precios[2][1] = 6;
	//costo diario
	precios[0][2] = 40000;
	precios[1][2] = 55000;
	precios[2][2] = 70000;
	//descuento 10 a 14 dias
	precios[0][3] = 5;
	precios[1][3] = 10;
	precios[2][3] = 10;
	//descuento 15 a 30 dias
	precios[0][4] = 10;
    precios[1][4] = 20;
	precios[2][4] = 20;
}
void mostrarPrecios(int precios[pFILAS][pCOLUMNAS]){
	printf("N° De Cabaña    Cant Personas    Costo Diario    Dto. 10 a 14 dias   Dto. 15 a 30 dias\n");
	for(int i = 0; i < pFILAS; i++){
		for(int j = 0; j<2; j++){
			printf("     %d\t         ", precios[i][j]);
		}
		//costo diario
		printf("$%d\t", precios[i][2]);
		//descuentos
		printf("               %d%%", precios[i][3]);
		printf("                  %d%%", precios[i][4]);
		printf("\n");
	}
}

void reservasFc(int precios[pFILAS][pCOLUMNAS], int reservas[FILAS][COLUMNAS]){
	int cabana = 0;
	int dias = 0;
	int salir = 0;
	int salir2 = 0;
	char fin = ' ';
	for (int i = 0; i < FILAS; i++){
		reservas[i][0] = rand()%(300-100-1) + 100;
		do{
			system("cls");
			printf("Ingrese cabaña que desee reservar (1 a 3): \n");
			scanf(" %d", &cabana);
			if((cabana>1) && (cabana<4)){
				reservas[i][1] = cabana;
				salir = 1;
			}else{
				printf("numero de cabaña invalido!!\n");
				printf("desea intentar de vuelta? s/n");
				scanf(" %c", &fin);
				if(fin != 's'||fin != 'S'){
					salir = 1;
					salir2 = 1;
					i = 10;
				}else{
					salir = 0;
				}
			}
		} while(salir == 0);
		
		//guardado de dias
		while(salir2 == 0){
			printf("¿Cuantos dias quiere reservar?\nNo pueden ser menores a 10 ni superar los 30 dias");
			scanf(" %d", &dias);
			if(dias >= 10 && dias <= 30){
				reservas[i][2] = dias;
				salir2 = 1;
			}else{
				printf("cantidad de dias invalido!!\n");
				printf("desea intentar de vuelta? s/n");
				scanf(" %c", &fin);
				if(fin != 's'||fin != 'S'){
					salir2 = 1;
					i = 10;
				}else{
					salir2 = 0;
				}
			}
		}
	}
}
