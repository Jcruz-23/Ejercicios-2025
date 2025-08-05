#include <stdio.h>

int main() {
	
    /*Realice un programa que calcule la cantidad de días de cada mes 
	(teniendo en cuenta si el año es bisiesto), que solicite Año y mes, 
	y permita la carga de 4 temperaturas por cada día. 
	
	El programa debe mostrar 
	
	*****Mes y año*****
	
	Día y temperatura max
	Día y temperatura min
	Promedio de temperatura del Mes.
	*/
	
	int contTemp = 0;
	int promTemp = 0;
	int temp = 0;
	int mes = 0;
	int dia = 0;
	
	
	for(mes = 1; mes <= 12; mes++){
		switch(mes) {
		case 1:
			promTemp = 0;
			for(dia = 1; dia <= 31; dia++){
				printf("Ingrese cuatro temperaturas para el dia %d: \n4", dia);
				for(contTemp = 1;contTemp <= 4; contTemp++){
					scanf(" %d", &temp);
					promTemp += temp;
				}
				
			}
			printf("%d",promTemp);
			break;
			
		};
	}
	return 0;
}

