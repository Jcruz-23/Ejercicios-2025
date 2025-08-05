#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mostrarMotos(int [][3]);
void mostrarAlquiler(int [][4]);
void motosAguaFc(int [][3]);
void alquilerFc(int [][3], int [][4]);
void menu(int [][3], int [][4]);
void ordAlquiler(int [][4]);
void ordMotos(int [][3]);


int main() {
	srand(time(NULL));
	int alquiler[5][4] = {0};
	int motosAgua[4][3] = {0};
	menu(motosAgua,alquiler);
	return 0;
}

void mostrarMotos(int motosAgua[4][3]){
	for (int i = 0; i<4; i++){
		for (int j = 0; j<3; j++){
			printf("%d\t", motosAgua[i][j]);
		}
		printf("\n");
	}
}
void motosAguaFc(int motosAgua[4][3]){
	//potencia
	motosAgua[0][1] = 50;
	motosAgua[1][1] = 70;
	motosAgua[2][1] = 90;
	motosAgua[3][1] = 120;
	//precio
	motosAgua[0][2] = 1000;
	motosAgua[1][2] = 2000;
	motosAgua[2][2] = 3000;
	motosAgua[3][2] = 5000;
	for(int i = 0; i<4; i++){
		motosAgua[i][0] = rand()%99+10;
	}
}
	
	
void alquilerFc(int motosAgua[4][3], int alquiler [5][4]){
	int cont = 0;
	int dni = 0;
	int moto = 0;
	int min = 0;
	int precio = 0;
	int aux = 0;
	char salir = 's';
	for(int i = cont; i < 5; i++){
		if(salir == 's'||salir == 'S'){
			printf("Incerte dni:\n");
			scanf(" %d", &dni);
			alquiler[i][0] = dni;
			printf("\nElija una moto"
					"\nMoto | Potencia | precio*m"
					"\n%d   |   %d     |   $%d"
					"\n%d   |   %d     |   $%d"
					"\n%d   |   %d     |   $%d"
					"\n%d   |   %d     |   $%d"
					"\n",
					motosAgua[0][0],motosAgua[0][1],motosAgua[0][2],
						motosAgua[1][0],motosAgua[1][1],motosAgua[1][2],
							motosAgua[2][0],motosAgua[2][1],motosAgua[2][2],
								motosAgua[3][0],motosAgua[3][1],motosAgua[3][2]);
			scanf(" %d", &moto);
			alquiler[i][1] = moto;
			printf("\nIngrese cantidad de minutos que desea alquilar:");
			scanf(" %d", &min);
			alquiler[i][2] = min;
			for(int j = 0; j<4; j++){
				if(motosAgua[j][0] == moto){
					aux = j;
				}
			}
			precio = motosAgua[aux][2] * min;
			alquiler[aux][3] = precio;
			printf("El alquiler costara: %d\n", precio);
			printf("\nDesea alquilar de vuelta?\n");
			scanf(" %c", &salir);
			cont = i;
		}
	}

}
	

void mostrarAlquiler(int alquiler[5][4]){
	for (int i = 0; i<5; i++){
		for (int j = 0; j<4; j++){
			if(alquiler[i][j]){
				printf("%d\t", alquiler[i][j]);
			}else{
				printf("-\t");
			}
		}
		printf("\n");
	}
}
	
void menu(int motosAgua[4][3], int alquiler[5][4]){
	int flag = 0;
	int opcion = 0;
	char fin = ' ';
	do{
		system("cls");
		printf("///////////////////////MENU///////////////////////\n"
			   "//                                              //\n"
			   "//                1)Alquilar moto               //\n"
			   "//             2)Mostrar Alquileres             //\n"
			   "//                3)Mostrar motos               //\n"
			   "//                                              //\n"
			   "//////////////////////////////////////////////////\n");
		printf("Elija una opcion: ");
		scanf(" %d", &opcion);
		switch(opcion){
		case 1:
			if(flag == 1){
				alquilerFc(motosAgua,alquiler);	
				
			}else{
				motosAguaFc(motosAgua);
				ordMotos(motosAgua);
				alquilerFc(motosAgua,alquiler);
			}
			flag = 1;
			break;
		case 2:
			if(flag == 1){
				ordAlquiler(alquiler);
				mostrarAlquiler(alquiler);
			}else{
				printf("Aun no se alquilo ninguna moto");
			}
			break;
		case 3:
			if (flag == 1){
				ordMotos(motosAgua);
				mostrarMotos(motosAgua);
				
			}else{
				motosAguaFc(motosAgua);
				ordMotos(motosAgua);
				mostrarMotos(motosAgua);
			}
			flag = 1;
			break;
		default:
			printf("\aNumero invalido!!\nElija una opcion valida\n");
			break;
		}
		printf("\nDesea continuar? s/n");
		scanf(" %c", &fin);
    } while(fin == 's'||fin == 'S');
}
	
	
	
void ordAlquiler(int alquiler[5][4]){
	int aux = 0;
	for(int i = 0; i < 5-1; i++){
		for(int j = 0; j<5-1-i; j++){
			if(alquiler[j][2] < alquiler[j+1][2]){
				for(int k = 0; k < 4; k++){
					aux = alquiler[j][k];
					alquiler[j][k] = alquiler[j+1][k];
					alquiler[j+1][k] = aux;
				}
			}
		}
	}
}

	
void ordMotos(int motosAgua[4][3]){
	int aux = 0;
	for(int i = 0; i < 4-1; i++){
		for(int j = 0; j < 4-1-i; j++){
			if(motosAgua[j][0] < motosAgua[j+1][0]){
				for(int k = 0; k < 3; k++){
					aux = motosAgua[j][k];
					motosAgua[j][k] = motosAgua[j+1][k];
					motosAgua[j+1][k] = aux;
				}
			}
		}
	}
}
