#include <stdint.h>
#include <stdlib.h>

/*Una trama de 16 bits codifica la siguiente informacion: 
bits 15-12: Tipo de mensaje
bits 11-8: prioridad
bit 7-0: datos

a) usar mascaras y corrimientos para extraer cada campo (4 bits)
b) mostrar en binario como se obtiene cada uno (4 bits)
c) implementar un ejemplo en pseudocodigo o c (6 bits)
*/

int main(){
    uint16_t valor = 0b1110010001001100;

    uint16_t mascaraTipo = 0b1111000000000000;
    uint16_t mascaraPrioridad = 0b0000111100000000;
    uint16_t mascaraDatos = 0b0000000011111111;
    
    uint16_t tipo = valor & mascaraTipo;
    uint16_t prioridad = valor & mascaraPrioridad;
    uint16_t datos = valor & mascaraDatos;

    printf("\nTipo: %x", tipo);
    printf("\nPrioridad: %x", prioridad);
    printf("\nDatos: %x", datos);
    printf("\n");
    return 0;
}