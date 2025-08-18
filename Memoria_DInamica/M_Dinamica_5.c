/*Modificar el código (ejercicio 4) para crear una función mostrar los valores. */


#include <stdio.h>
#include <stdlib.h>

void mostrar(char *, int);
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
      mostrar(p, n);

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
        for (int i = n; i < n + n_final; i++){
        scanf(" %c", &*(p + i));
        }
        n+=n_final;
        mostrar(p, n);
    }
}

void mostrar(char *p, int n){
    printf("Characteres ingresados: ");
        for(int i = 0; i < n; i++){
        printf("%c\t",*(p + i));
        }
     printf("\n");
}


