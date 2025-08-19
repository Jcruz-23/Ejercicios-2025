#include <stdio.h>
#include <stdlib.h>

void texto(int *, int);
void mostrarTexto(int *, int);
void invertirTexto(int *, int);
int main(){
    char *p = NULL;
    int memoria = 0;
    
    printf("Cuantos charactes quiere escribir?: ");
    scanf(" %d", &memoria);
    p = (char *) malloc(memoria * sizeof(char));

    if(p == NULL){
        printf("\nError al asignar memoria!");
        return 1;
    }else{
        cargarTexto(p, memoria);
        mostrarTexto(p, memoria);
        invertirTexto(p, memoria);
        free(p);
        p = NULL;
    }
    return 0;
}

void cargarTexto(int *p, int memoria){
    printf("\nAgregue el texto (max %d characteres): ", memoria);
    for(int i = 0; i < memoria; i++){
        scanf(" %c", &*(p + i));
    }
}

void mostrarTexto(int *p, int memoria){
    printf("\nTexto ingresado: ");
    for(int i = 0; i < memoria; i++){
        printf("%c", *(p + i));
    }
}
void invertirTexto(int *p, int memoria){
     printf("\nTexto invertido: ");
    for(int i = memoria - 1; i>=0; i--){
        printf("%c", *(p + i));
    }
}