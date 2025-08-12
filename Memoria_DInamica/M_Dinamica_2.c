/*Cree un programa que permita reservar memoria para n valores decimales (float). Luego cargar los n valores, imprimirlos y liberar la memoria.*/

#include <stdio.h>
#include <stdlib.h>

void valores(float *, int);
int main(){
    float *p = NULL;
    int n = 0;
    printf("Asignar espacio de memoria: ");
    scanf(" %d", &n);
    p = (float *) malloc(n * sizeof(float));
    if(p == NULL){
        printf("\n\aERROR AL ASIGNAR MEMORIA!!");
        return 1;
    }else{
        valores(p, n);
    
        free(p);
        p = NULL;
       }
    return 0;
}

void valores (float *p, int n){
    printf("Ingrese valores (max %d): ", n);
    for(int i = 0; i < n; i++){
        scanf(" %f", &*(p + i));
    }
   printf("Los valores agregados son: ");
       for(int i = 0; i < n; i++){
        printf("%.2f\t", *(p + i));
       }
    }

