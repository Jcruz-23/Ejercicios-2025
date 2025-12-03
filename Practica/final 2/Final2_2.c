/*Crea un programa para gestionar un inventario de automóviles utilizando un TDA. El TDA debe contener información sobre cada automóvil, incluyendo modelo, stock (entero), y precio (decimal). Desarrollar las siguientes funciones para:

    Agregar un nuevo modelo de automóvil al inventario.
    Mostrar el inventario por consola y generar un archivo txt llamado "inventario.txt".
    Eliminar un modelo de automóvil del inventario.
    Calcular el valor total del inventario.

Diseña un menú de opciones para que el usuario pueda interactuar con el programa*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

typedef struct{
    char modelo[20];
    int stock;
    float precio;
}Info;

typedef struct Nodo{
    Info info;
    struct Nodo* sig;
}Nodo;


void menu();
void ingresar(Nodo**);
void apilar(Nodo**, Info);
void Desapilar(Nodo**);
void mostrar(Nodo*);
void calcular(Nodo*);
void mayus(char*);
void liberar(Nodo**);

int main(){
    menu();
    return 0;
}

void menu(){
    int op = 0;
    Nodo* inv = NULL;
    do{
        system("clear");
        printf("================MENU================"
            "\n0) Salir"
            "\n1) Ingresar automovil"
            "\n2) Mostrar / guardar .txt"
            "\n3) calcular valor del inventario"
            "\n4) Desapilar"
            "\n===================================="
            "\nOpcion:");
        scanf(" %d", &op);

        switch(op){
            case 0:
                printf("\ncerrando. . .");
                break;
            case 1:
                ingresar(&inv);
                break;
            case 2:
                if(inv != NULL) mostrar(inv);
                else printf("\nInventario vacio!");
                break;
            case 3:
                if(inv != NULL) calcular(inv);
                else printf("\nInventario vacio!");
                break;
            case 4:
                if(inv != NULL) Desapilar(&inv);
                else printf("\nInventario vacio!");
                break;
            default:
                printf("\nError!!");
                break;
        }

        if(op != 0){
            getchar();
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n');
        }

    }while(op != 0);
    liberar(inv);
}

void ingresar(Nodo** inv){
    Info info;
    getchar();
    printf("\nIngrese modelo: ");
    fgets(info.modelo,sizeof(info.modelo),stdin);
    info.modelo[strcspn(info.modelo,"\n")]='\0';
    mayus(info.modelo);
    printf("\nIngrese stock: "); scanf(" %d", &info.stock);
    printf("\nIngrese precio: "); scanf(" %f", &info.precio);
    
    apilar(inv, info);
}

void apilar(Nodo** inv, Info info){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->info = info;
    nuevo->sig = *inv;
    *inv = nuevo;
}

void mostrar(Nodo* inv){
    FILE *a = NULL;
    Nodo* aux = inv;
    int cont = 0;
    while(aux != NULL){
        cont++;
        printf("\n----------------[%d]----------------", cont);
        printf("\nModelo: %s", aux->info.modelo);
        printf("\nStock: %d", aux->info.stock);
        printf("\nPrecio: %.2f", aux->info.precio);
        aux = aux->sig;
    }

    aux = inv;
    
    a = fopen("Inventario.txt", "w");
    fprintf(a, "%-15s |%-10s |%-10s |", "Modelo", "Stock", "Precio");
    while(aux != NULL){
        fprintf(a, "\n%-15s |%-10d |%-10.2f |", aux->info.modelo, aux->info.stock, aux->info.precio);
        aux = aux->sig;
    }
    fclose(a);
}

void Desapilar(Nodo** p){
        Nodo* prox = (*p)->sig;
        free(*p);
        *p = prox;
}

void calcular(Nodo* inv){
    Nodo* aux = inv;
    float total;
    while(aux != NULL){
        total += (aux->info.stock*aux->info.precio);
        aux = aux->sig;
    }
    printf("\nPrecio total del inventario: %.2f", total);
}

void mayus(char *nombre){
    int cant = strlen(nombre);
    for(int i = 0; i < cant; i++){
        nombre[i] = toupper(nombre[i]);
    }
}

void Liberar(Nodo** inv){
    Nodo *aux = *inv;
    while(aux != NULL){
        aux = (*inv)->sig;
        free(*inv);
        *inv = aux;
    }
}