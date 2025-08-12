#include <stdio.h>
#include <stdlib.h>

/*Cree un programa que permita reservar memoria para n valores enteros. Luego cargar los n valores, 
imprimirlos y liberar la memoria.*/

void asignacion(int *, int);


int main(){
    int *p = NULL;
    int n = 0;
    printf("Asignar espacio de memoria: ");
    scanf(" %d", &n);
    p = (int *) malloc (n * sizeof(int));

    if (p == NULL){
        printf("\a\nError al asignar memoria");
    }else {
        asignacion(p, n);
        free(p);
        p = NULL;
    }
    return 0;
}

void asignacion (int *p, int n){
        printf("\nIngrese valores (max %d):", n);
        for (int i = 0; i<n; i++){
        scanf(" %d", &*(p + i));
        }
        printf("\n los valores son: ");
        for(int i = 0; i < n; i++){
        printf("%d\t", *(p + i));
        }
}