/*Escriba un programa en C que lea un archivo de texto con datos de personas. 
Cada línea del archivo contiene los siguientes datos: Nombre, Apellido, Edad. 
El programa debe utilizar una estructura para almacenar los datos de cada persona. 
La estructura debe tener los siguientes campos: nombre: char[25], apellido: char[25], edad: int. 
El programa debe utilizar punteros con funciones para realizar las siguientes tareas:
1)Leer el archivo de texto y almacenar los datos en una estructura.
2)Imprimir los datos de cada persona.
3)Liberar la memoria reservada para las estructuras
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct persona{
int edad;
char nombre[25];
char apellido[25];
};


int buscar(struct persona *p, int);
void mostrar(struct persona *p, int);

int main(){
    int n = 0;
    int op = 0;
    int flagSalir = 0;
    struct persona *p = NULL;
    char fin = 's';
    p = malloc(100 * sizeof(struct persona)); //lee hasta 100 personas
    
    do{
        if(p == NULL){
        printf("\nError asignando memoria");
        return 1;
        }
        printf("------------------MENU------------------"
               "\n1)Leer archivo"
               "\n2)Mostrar personas"
               "\n3)Liberar memoria y salir"
               "\n----------------------------------------"
               "\nOpcion: ");
        scanf(" %d", &op);

        switch(op){
            case 1: 
            n = buscar(p, n);
            break;
            case 2: 
            mostrar(p, n);
            break;
            case 3:
            printf("\nLiberando memoria. . .");
            free(p);
            return 0;
            break;
            default:
            printf("\nError!");
            flagSalir = 1;
            break;
        }

        printf("\nDesea continuar? (s/n): ");
        scanf(" %c", &fin);
    }while(fin == 's'|| fin == 's');

    if(flagSalir = 0){
        free(p);
    }
}


int buscar(struct persona *p, int n){
    FILE *f;
    printf("\nAbriendo archivo ''persona.txt''. . .");
    f = fopen("persona.txt","r");

    if (f == NULL){
        printf("\nError al leer el archivo!");
        return;
    }
    printf("\nLeyendo. . .");

    while(fscanf(f, "%s %s %d", (p+n)->nombre, (p+n)->apellido, &(p+n)->edad) == 3){
        n++;
    }
    printf("\nArchivo leido!");

    fclose(f);
    return n; 
}

void mostrar(struct persona *p, int n){
    for(int i = 0; i < n; i++){
        printf("\n-------------Persona[%d]-------------", i+1);
        printf("\nNombre: %s", (p+i)->nombre);
        printf("\nApellido: %s", (p+i)->apellido);
        printf("\nEdad: %d", (p+i)->edad);
    }
}2