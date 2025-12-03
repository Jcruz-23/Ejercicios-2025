#include <stdint.h>
#include <stdio.h>

/*Ejercicio 2: Dado un byte con valor ob 11001010, calcular su complemento (~), luego aplicar una máscara Ob 00001111 Para quedarte con los 4 bits menos significativos del resultado.*/

int main(){
    uint8_t valor = 0b11001010;
    uint8_t complemento = ~valor;
    uint8_t mascara = valor & 0b00001111;
    
    printf("\nvalor: %x", valor);
    printf("\ncomplemento: %x", complemento);
    printf("\nmascara: %x", mascara);
    printf("\n");
}