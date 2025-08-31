/*Escriba un programa que cree un archivo llamado "datos_personales.txt” que pregunte los siguientes datos personales: 
nombre, apellido, dni, edad, nacionalidad. Luego abrir el archivo y mostrarlo. Utilice fprintf y scanf.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *a;
    char nombre[20];
    char apellido [20];
    int dni = 0;
    char nacionalidad[20];
    int edad = 0;

    a = fopen("datos_personales.txt", "w");

    printf("\n---------------Datos Personales---------------");
    printf("\nNombre: ");
    scanf(" %s", nombre);
    printf("\nApellido: ");
    scanf(" %s", apellido);
    printf("\nDNI: ");
    scanf(" %d", &dni);
    printf("\nNacionalidad: ");
    scanf(" %s", nacionalidad);
    printf("\nEdad: ");
    scanf(" %d", &edad);
    fprintf(a,"---------------Datos Personales---------------");
    fprintf(a,"\nNombre: %s", nombre);
    fprintf(a,"\nApellido: %s", apellido);
    fprintf(a,"\nDNI: %d", dni);
    fprintf(a,"\nNacionalidad: %s", nacionalidad);
    fprintf(a,"\nEdad: %d", edad);
    fclose(a);
    return 0;
}
