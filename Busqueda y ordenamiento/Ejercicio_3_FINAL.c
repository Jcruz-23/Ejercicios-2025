#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Cargar(int [6][9]);
void Ordenar(int [6][9]);
void Disponibles();
void Menu();
int PrecioDia(int);
int MontoDescuento(int, int);
int MontoTotal(int, int, int);

int main() {
	int reserva[6][9] = {0};
	
	return 0;
}

void Cargar(int reserva[6][9]){	
	srand(time(NULL));
	int cod;
	
	for(int i = 0; i < 6; i++){
		cod = rand()%(300-100+1)+100;
		reserva[i][0] = cod;
		printf("\nIngrese el numero de cabaña:\n");
		scanf(" %d", &reserva[i][1]);
		printf("\nIngrese la cantida de dias que se alquilara la cabaña\n");
		scanf(" %d", &reserva[i][2]);
		reserva[i][3] = PrecioDia(reserva[i][1]);
		reserva[i][4] = MontoDescuento(reserva[i][1], reserva[i][2]);
		reserva[i][5] = MontoTotal(reserva[i][2], reserva[i][3], reserva[i][4]);
	}
	
}
	
int MontoTotal(int cantdias, int preciodia, int montodescuento){
	int montototal = 0;
	
	if(montodescuento == 5){
		montototal = preciodia*cantdias - ((preciodia*cantdias*5)/100);
	}if(montodescuento == 10){
		montototal = preciodia*cantdias - ((preciodia*cantdias*10)/100);
	}if(montodescuento == 15){
		montototal = preciodia*cantdias - ((preciodia*cantdias*15)/100);
	}if(montodescuento == 20){
		montototal = preciodia*cantdias - ((preciodia*cantdias*20)/100);
	}
	
	return montototal;
}
	
int MontoDescuento(int nrocabañas, int cantdias){
	int montodescuento = 0;
	
	if(cantdias >= 10 && cantdias <= 14 && nrocabañas == 1){
		montodescuento = 5;
	}if(cantdias >= 10 && cantdias <= 14 && nrocabañas == 2 || nrocabañas == 3){
		montodescuento = 10;
	}if(cantdias >= 15 && cantdias <= 30 && nrocabañas == 1){
		montodescuento = 15;
	}if(cantdias >= 15 && cantdias <= 30 && nrocabañas == 2 || nrocabañas == 3){
		montodescuento = 20;
	}
	
	return montodescuento;
}

int PrecioDia(int nrocabaña){
	int preciodia = 0;

	if(nrocabaña == 1){
		preciodia = 40000;
	}if(nrocabaña == 2){
		preciodia = 55000;
	}if(nrocabaña == 3){
		preciodia = 70000;
	}
		
	return preciodia;
}


void Ordenar(int reservas[6][9]){
	int pos;
	int aux;
	
	for(int i = 0; i < 6 - 1; i++){
		pos = i;
		for(int j = i+1; j < 6; j++){
			if(reservas[pos][0] > reservas[j][0]){
				pos = j;
			}
		}
		aux = reservas[pos][0];
		reservas[pos][0] = reservas[i][0];
		reservas[i][0] = aux;
	}
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 9; j++){
			printf("");
		}
	}
}
