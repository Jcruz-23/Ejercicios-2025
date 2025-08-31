#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct persona{
    char nombre[20];
    char apellido [20];
    int dni;
    char nacionalidad[20];
    int edad;
};
void menu();
int cargar(struct persona *p, int);
int agregar(struct persona *p, int);

int main(){

    return 0;
}

void menu(){
    struct persona *p;
    char fin = ' ';
    int op = 0;
    int n = 0;
    int flag = 0;
    do{
        if(flag == 0){ n = cargar(p, n); flag = 1;}
        else n = agregar(p, n); 
    }while(fin == 's'|| fin == 'S');


    free(p);
}
int cargar(struct persona *p, int n){
    FILE *a;
    a = fopen("datos_personales.txt", "w");
    p = malloc(1 * sizeof(p));
    if(p == NULL){
        printf("\nError al asignar memoria");
        return 0;
    };
    printf("\n---------------Persona [%d]---------------", n);
    printf("\nNombre: ");
    scanf(" %s", p[n].nombre);
    printf("\nApellido: ");
    scanf(" %s", p[n].apellido);
    printf("\nDNI: ");
    scanf(" %d", &p[n].dni);
    printf("\nNacionalidad: ");
    scanf(" %s", p[n].nacionalidad);
    printf("\nEdad: ");
    scanf(" %d", &p[n].edad);
    fprintf(a,"---------------Persona [%d]---------------", n);
    fprintf(a,"\nNombre: %s", p[n].nombre);
    fprintf(a,"\nApellido: %s", p[n].apellido);
    fprintf(a,"\nDNI: %d", p[n].dni);
    fprintf(a,"\nNacionalidad: %s", p[n].nacionalidad);
    fprintf(a,"\nEdad: %d", p[n].edad);

    fclose(a);
    n++;
    return n;
}

int agregar(struct persona *p, int n){
    FILE *a;
    a = fopen("datos_personales.txt", "w");
    p = malloc(1 * sizeof(p));
    if(p == NULL){
        printf("\nError al asignar memoria");
        return 0;
    };

    printf("\n---------------Datos Personales---------------");
    printf("\nNombre: ");
    scanf(" %s", p[n].nombre);
    printf("\nApellido: ");
    scanf(" %s", p[n].apellido);
    printf("\nDNI: ");
    scanf(" %d", &p[n].dni);
    printf("\nNacionalidad: ");
    scanf(" %s", p[n].nacionalidad);
    printf("\nEdad: ");
    scanf(" %d", &p[n].edad);
    fprintf(a,"---------------Datos Personales---------------");
    fprintf(a,"\nNombre: %s", p[n].nombre);
    fprintf(a,"\nApellido: %s", p[n].apellido);
    fprintf(a,"\nDNI: %d", p[n].dni);
    fprintf(a,"\nNacionalidad: %s", p[n].nacionalidad);
    fprintf(a,"\nEdad: %d", p[n].edad);

    fclose(a);
    n++;

    return n;
}


