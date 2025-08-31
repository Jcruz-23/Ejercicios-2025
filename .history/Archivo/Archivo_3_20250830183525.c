/*Escriba un programa que cree un archivo llamado "datos_personales.txt” que pregunte los siguientes datos personales: 
nombre, apellido, dni, edad, nacionalidad. Luego abrir el archivo y mostrarlo. Utilice fprintf y scanf.
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *a;
    char nombre[20];
    char apellido [20];
    int dni = 0;
    char nacionalidad[20];
    int edad = 0;
    char ch;

    a = fopen("datos_personales.txt", "w");

    printf("\n---------------Datos Personales---------------");
    printf("\nNombre: ");
    while((ch = fgetc(stdin)) != EOF){
        if(ch != "$"){
            fputc(ch, a);
        }else break;
        
    }
}
