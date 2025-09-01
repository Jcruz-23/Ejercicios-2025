/*Escribir un programa que solicite los datos de un producto (nombre del producto, marca, precio unitario, fecha de elaboración, 
tamaño) y crear una estructura producto. Luego la guarde en un archivo de texto con el nombre "Datos_Producto.txt". */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct producto{
char nombre[20];
char marca[20];
int precio;
float fecha;
int tamaño;
};
int main(){
    struct producto p;
    FILE *a;
    a = fopen("producto.txt", "w");
    printf("------------PRODUCTO------------");
    printf("\nNombre: ");
    scanf(" %s", p.nombre);
    printf("\nMarca: ");
    scanf(" %s", p.marca);
    printf("\nPrecio: ");
    scanf(" %d", &p.precio);
    printf("Fecha(dia.mes): ");
    scanf(" %f", &p.fecha);
    printf("\nTamaño: ");
    scanf(" %d", &p.tamaño);
    fprintf(a,"------------PRODUCTO------------");
    fprintf(a,"\nNombre: %s", p.nombre);
    fprintf(a,"\nMarca: %s", p.marca);
    fprintf(a,"\nPrecio: %d", p.precio);
    fprintf(a,"Fecha(dia.mes): %.4f", p.fecha);
    fprintf(a,"\nTamaño: %d", p.tamaño);
    

    fclose(a);
}