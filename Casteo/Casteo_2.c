//Cargar las 3 notas de un alumno como valores enteros. 
//Luego mostrar el promedio teniendo en cuenta si tiene parte decimal.

#include <stdio.h>

int main(){
    int nota;
    int total = 0;
    float prom = 0;
    printf("Cargar notas: ");
    for(int i = 0; i<3; i++){
        scanf(" %d", &nota);
        total += nota;
    }
    prom = (float)total/3;
    printf("Promedio total: %.2f", prom);
}
