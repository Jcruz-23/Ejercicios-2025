#include <stdint.h>
#include <stdio.h>

/*Ejercicio 3: Dado un número de 8 bits, intercambiar (conmutar) los bits 1 y 6 sin afectar los demás bits. Usar solo el operador XOR (^)*/
int main(){
    uint8_t v = 0b10101100;
    uint8_t v2 = v ^ 0b00100010;
    
    printf("\ninicio: %x", v);
    printf("\nresultado: %x", v2);
}