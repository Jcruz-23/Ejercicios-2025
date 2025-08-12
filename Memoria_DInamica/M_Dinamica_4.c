/*Cree un programa que permita reservar memoria para n caracteres (char). Luego cargar los n caracteres e imprimirlos por pantalla. 
El usuario desea agregar mas caracteres, por lo que ingresa la n cantidad de caracteres a agregar. Luego cargar los n caracteres, 
imprimirlos y finalmente liberar la memoria.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char *p = NULL;
    int n = 0;
    printf("Espacio de memoria deseado: ");
    scanf(" %d", &n);
    p = (char *) malloc(n * sizeof(char));
    if(p == NULL){
        printf("\a\nERROR ASIGNANDO EL ESPACIO");
        return 1;
    }else{
        printf("\nIngresar characteres(Max %d): ", n);
        for(int i = 0; i < n; i++){
        scanf(" %c", &*(p +i));
        }
        printf("\nLos valores son: ");
        for(int i = 0; i < n; i++){
        printf("%c\t",*(p + i));
        }

    char *temp_p;
    int n_final;
    printf("\nCuantos espacios desea agregar?: ");
    scanf(" %d", &n_final);
    temp_p = (char *) realloc(p, n_final * sizeof(char));
    if(temp_p == NULL){
        printf("\n\aERROR AL AUMENTAR LA MEMORIA");
        free(p);
        return 1;
    }
        system("clear");
        p = temp_p;
        printf("\nInsertar characteres que desee agregar: ");
        for (int i = n; i < n+n_final; i++){
        scanf(" %c", &*(p + i));
        }
        printf("Characteres ingresados: ");
        for(int i = 0; i < n + n_final; i++){
        printf("%c\t",*(p + i));
        }
        prinf("\n");
    }
}
   


