#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {

	float pesoManzanas = 0;
	int compraEnProceso = 0;
	int opcion = 0;
	float importe = 0;
	char fin = 's';
	
	do{
	printf("Seleccione una de las opciones: \n1)Comprar manzanas.\n2)Mostrar Ticket (Importe a abonar).\n3)Salir.");
	scanf(" %d",&opcion);

	 switch(opcion){
	 case 1: 
		 if(compraEnProceso == 1){
			 printf("Hay una compra en proceso!");
		 }else {
			 compraEnProceso = 1;
			 printf("\nIngrese peso de la cantidad de manzanas en kg: ");
			 scanf(" %f", &pesoManzanas);
		 }
		
		break;
	 case 2:
		if(pesoManzanas <=2){
			importe = pesoManzanas * 459;
		}else if(pesoManzanas >=2 && pesoManzanas <= 5){
			importe = (pesoManzanas * 459)*10/100;
		}else if (pesoManzanas >=5 && pesoManzanas <= 10){
			importe = (pesoManzanas * 459)*20/100;
		}else if(pesoManzanas >=30){
			importe = (pesoManzanas * 459)*30/100;
		}
		
		printf("\nEl importe a pagar es: %.2f", importe);
		compraEnProceso = 0;
		break;
	 case 3: 
		return 0;
		break;
	}
	 printf("\nQuiere realizar otra opcion? s/n");
	 scanf(" %c",&fin);
	 	} while(fin == 's');
}

