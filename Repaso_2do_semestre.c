#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarVuelos(int[][6]);
int parapente(int, int);
int precio (int);
	
int main() {
	int vuelos [10][6];
	srand(time(NULL));
	return 0;
}



void inicializarVuelos(int vuelos[10][6]){
	int pasajero = 1000;
	for(int i = 0; i < 10; i++){
		
		vuelos[i][0] = 	pasajero + 1;
		pasajero = vuelos[1][i];
		vuelos[i][1] = rand()%(110 - 50 + 1) + 50;
		vuelos[i][2] = rand()%(3 - 1 + 1) + 50;
		vuelos[i][3] = parapente(vuelos[i][2], vuelos[i][1]);
		vuelos[i][4] = precio(vuelos [i][3]);
	}
}
int parapente(int instructor, int pesoPasajero){
	int idParapente = 0;
	int pesoTotal = pesoPasajero;
	
	switch(instructor){
	case 1: pesoTotal+= 80; break;
	case 2: pesoTotal+= 65; break;
	case 3: pesoTotal+= 85; break;
	}
	
	if(pesoTotal >= 120 && pesoTotal <= 160){
		idParapente = 50;
	}else if(pesoTotal > 160 && pesoTotal <=200){
		idParapente = 51;
	}else{
		idParapente = 52;
	}
	return idParapente;
}
	
int precio(int parapente){
	int precio = 0;
	switch (parapente){
	case 50: precio = 45000; break;
	case 51: precio = 50000; break;
	case 52: precio = 55000; break;
	}
	return precio;
}