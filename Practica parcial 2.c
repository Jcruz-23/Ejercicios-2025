#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int regular(int [5][7]);
void recursar(int [5][7]);
int promedio(int [5][7]);
void lista(int [5][7]);


int main() {
	int arreglo [5][7] = {0};
	int materias = 0;
	int contReg = 0;
	int i = 0;
	int j = 0;
	int op = 0;//opcion 
	char fin = ' ';//final del while
	int prom = 0; //promedio del caso 4
	
	srand(time(NULL));
	
	
	for(i=0;i<5;i++){
		materias++;
		arreglo [i][0] = materias;
		for (j=1; j<7; j++){
			arreglo [i][j] = rand()%10+1;
			if(arreglo [i][1] >=4){
				arreglo [i][3] = 0; 
			}
			
			if(arreglo [i][2] >=4){
				arreglo [i][4] = 0; 
			}
			
			if((arreglo [i][1]>=4 && arreglo [i][2]>=4) || (arreglo [i][1]>=4 && arreglo [i][4]>=4) || (arreglo [i][2]>=4 && arreglo [i][3]>=4) || (arreglo [i][3]>=4 && arreglo [i][4]>=4)){
				arreglo [i][5] = 1; 
			}else{
				arreglo [i][5] = 2; 
				arreglo [i][6] = 0; 
			}
		}
	}
	
	
	do{
		printf("Elija una opción\n1-Asignaturas regularizadas\n2-Asignaturas a recursar\n3-Promedio de notas finales\n4-Listado de asignaturas\n");
		scanf(" %d",&op);
		printf("\n\n");
		
		switch(op){
		case 1:
			contReg = regular(arreglo);
			printf("la cantidad de materias regulares son: %d",contReg);
			printf("\n\n");
			break;
		case 2: 
			recursar(arreglo);
			printf("\n\n");
			break;
		case 3:
			prom = promedio(arreglo);
			printf("El promedio de los finales es = %d\n", prom);
			break;
		case 4: 
			lista(arreglo);
		}
		
		
		
		printf("Quiere salir del programa? s/n");
		scanf(" %c", &fin);
		printf("\n\n");
	} while(fin == 'n' || fin == 'N');
	
	return 0;
}

int regular(int matriz[5][7]){
	int contRegFunc = 0;
	for(int i = 0; i < 5; i++){
		if(matriz[i][5] == 1){
			contRegFunc++;
		}
	}
	return contRegFunc;
}
void recursar(int rec[5][7]){
	int cont = 0;
	for(int i = 0;i < 5; i++){
		if(rec[i][5] == 2 && rec[i][6] < 4){
			printf("recursar %d\n", rec[i][0]);
			cont++;
		}
	}
	if(cont == 0){
		printf("Aprobo todas las materias!\n");
	}
}
int promedio(int prom [5][7]){
	int suma = 0;
	int promedio = 0;
	for(int i = 0;i < 5; i++){
		suma += prom[i][6];
	}
	promedio = suma/5;
	
	return promedio;
}
void lista (int lista [5][7]){
	for(int i=0;i<5;i++){
		for (int j=0; j<7; j++){
			printf(" %d\t", lista[i][j]);
		}
		printf("\n");
	}
}
