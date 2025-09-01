/*Escriba un programa que cree un archivo llamado "pares.txt” que contenga 
los valores pares del 1 al 100. Luego abrir el archivo y mostrarlo.*/

#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *a;
    a = fopen("Numeros_pares.txt", "w");
    printf("-------------------------------------------------------NUMEROS PARES--------------------------------------------------------\n");
    fprintf(a, "------------------------------------------------------------------NUMEROS PARES------------------------------------------------------------------\n");

    for(int i = 0; i < 100; i++){
        if(i%2 == 0){
            printf("%d-", i);
            fprintf(a, "%d-", i);

        }
    }

    fclose(a);
}