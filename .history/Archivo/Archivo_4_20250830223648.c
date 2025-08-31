#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct persona{
    char nombre[20];
    char apellido [20];
    int dni = 0;
    char nacionalidad[20];
    int edad = 0;
};
int main(){
    FILE *a;
    struct persona p;
    a = fopen("datos_personales.txt", "w");

    printf("\n---------------Datos Personales---------------");
    printf("\nNombre: ");
    scanf(" %s", p.nombre);
    printf("\nApellido: ");
    scanf(" %s", p.apellido);
    printf("\nDNI: ");
    scanf(" %d", &p.dni);
    printf("\nNacionalidad: ");
    scanf(" %s", p.nacionalidad);
    printf("\nEdad: ");
    scanf(" %d", &p.edad);
    fprintf(a,"---------------Datos Personales---------------");
    fprintf(a,"\nNombre: %s", p.nombre);
    fprintf(a,"\nApellido: %s", p.apellido);
    fprintf(a,"\nDNI: %d", p.dni);
    fprintf(a,"\nNacionalidad: %s", p.nacionalidad);
    fprintf(a,"\nEdad: %d", p.edad);
    fclose(a);
    return 0;
}
