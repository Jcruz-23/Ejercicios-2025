#include <stdint.h>
#include <stdlib.h>

/*Dado un registro de 8 bits que controla las salidas digitales de un puerto (PORTA), escribir instrucciones en C para:
a)	Activar el bit 2.
b)	Desactivar el bit 5.
c)	 Verificar si el bit 7 está activado.*/

int main(){
    uint8_t i = 0b10000000;
    uint8_t activar = 0b00100100;

    if(i && (1<<7))printf("\n7 activado");
    else printf("\n7 desactivado");

    printf("\nEstado: %x", i ^ activar);
}