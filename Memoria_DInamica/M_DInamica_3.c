/*Cree un programa que permita reservar memoria para n caracteres (char). Luego cargar los n caracteres e imprimirlos por pantalla.*/
#include <stdio.h>
#include <stdlib.h>


int main(){
    char *p = NULL;
    int n = 0;

    printf("Asignar espacio de memoria:");
    scanf(" %d", &n);
    p = (char *) malloc(n * sizeof(char));
    
    if (p == NULL){
        printf("\a\nERROR EN LA ASIGNACION DE MEMORIA");
        return 1;
    }else{
        printf("Ingrese texto: ");
        for(int i = 0; i < n; i++){
            scanf(" %c", &*(p + i));
        }

        printf("\nLos characteres agregados son: ");
        for(int i = 0; i < n; i++){
            printf("%c\t", *(p + i));
        }
    }
}