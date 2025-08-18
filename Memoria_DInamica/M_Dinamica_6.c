#include <stdio.h>
#include <stdlib.h>

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
        free(p);
        p = NULL;
    }
    return 0;
}
