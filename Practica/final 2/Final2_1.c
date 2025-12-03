/*Restaurante

Desarrolla un programa para gestionar los datos de un restaurante mediante un TDA. El TDA debe contener la información de los platos disponibles, incluyendo nombre del plato, cantidad de platos disponibles (entero), cantidad de platos vendidos (entero) y precio (decimal). Implementa las siguientes funciones para:

    Insertar un nuevo plato en el menú.
    Mostrar el menú por consola y generar un archivo txt llamado "menu.txt".
    Eliminar un plato del menú.
    Calcular la recaudación total de los platos vendidos.

Además, crea un menú de opciones para que el usuario pueda interactuar con el programa. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

typedef struct{
    char nombre[20];
    int cant;
    int vendidos;
    float precio;
}Info;

typedef struct Nodo{
    Info info;
    struct Nodo* sig;
}Nodo;

void menu();
void ingresar(Nodo**);
void apilar(Nodo**, Info);
void mostrar (Nodo*);
void desapilar (Nodo**);
void mayus(char* nombre);
void recaudacion(Nodo*);
void liberar(Nodo**);

int main(){
    menu();
    return 0;
}

void menu(){
    Nodo* p = NULL;
    char fin = 's';
    int op = 0;
    do{
        system("clear");
        printf("================MENU================"
            "\n1) Agregar plato"
            "\n2) Mostrar menu/genererar txt"
            "\n3) eliminar plato"
            "\n4) calcular recaudacion total"
            "\n5) salir"
            "\n===================================="
            "\nOpcion:");
        scanf(" %d", &op);

        switch(op){
            case 1:
                ingresar(&p);
                break;
            case 2:
                if(p != NULL) mostrar(p);
                else printf("\nNo hay platos ingresados");
                break;
            case 3:
                if(p != NULL) desapilar(&p);
                else printf("\nNo hay platos ingresados");
                break;
            case 4:
                if(p != NULL) recaudacion(p);
                else printf("\nNo hay platos ingresados");
                break;
            case 5:
                break;
            default:
                printf("\nError!!");
                break;
        }

        if(op != 5){
            getchar();
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n');
        }

    }while(op != 5);
    liberar(p);
}

void ingresar(Nodo** p){
    Info info;
    getchar();
    printf("\n----Ingresar plato----");
    printf("\nNombre: ");
    fgets(info.nombre,sizeof(info.nombre),stdin);
    info.nombre[strcspn(info.nombre,"\n")]='\0';
    mayus(info.nombre);
    printf("\nCantidad: "); scanf(" %d", &info.cant);
    do{
        printf("\nVendidos: ");
        scanf(" %d", &info.vendidos);
        if(info.vendidos > info.cant){
        printf("\nERROR! (la cantidad de vendidos no puede ser mayor a la de los platos)");
    }
    }while(info.vendidos>info.cant);
    printf("\nPrecio: "); scanf(" %f", &info.precio);
    
    apilar(p, info);
}

void apilar(Nodo** p, Info info){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->info = info;
    nuevo->sig = *p;
    *p = nuevo;
}

void mostrar(Nodo* p){
    FILE* a = NULL;
    Nodo* aux = p;
    int cont = 0;
    while(aux != NULL){
        cont++;
        printf("\n-------------[%d]-------------", cont);
        printf("\nNombre: %s", aux->info.nombre);
        printf("\nCantidad: %d", aux->info.cant);
        printf("\nVendidos: %d", aux->info.vendidos);
        printf("\nPrecio: %.2f", aux->info.precio);
        aux = aux->sig;
    }

    aux = p;

    a = fopen("platos.txt", "w");
    fprintf(a, "|%-15s |%-10s |%-10s |%-10s |", "nombre", "cantidad", "vendidos", "precio");
    while(aux != NULL){
        fprintf(a, "\n|%-15s |%-10d |%-10d |%-10.2f |", aux->info.nombre, aux->info.cant, aux->info.vendidos, aux->info.precio);
        aux = aux->sig;
    }
    fclose(a);
}

 
void desapilar(Nodo** p){
    char borrar[20];
    fgets(borrar,sizeof(borrar),stdin);
    borrar[strcspn(borrar,"\n")]='\0';
    mayus(borrar);
    Nodo* aux = *p;
    while(aux != NULL){
        if(strcmp(borrar, aux->info.nombre) == 0){
            *p=aux->sig;
            free(aux);
        }
        aux = aux->sig;   
    }
}


void recaudacion(Nodo* p){
    Nodo* aux = p;
    float total = 0;
    while(aux != NULL){
        total += (aux->info.precio * aux->info.vendidos);
        aux = aux->sig;
    }
    printf("\nTotal recaudado: %.2f", total);
}

void Liberar(Nodo** p){
    Nodo *aux = *p;
    while(aux != NULL){
        aux = (*p)->sig;
        free(*p);
        *p = aux;
    }
}

void mayus(char *nombre){
    int cant = strlen(nombre);
    for(int i = 0; i < cant; i++){
        nombre[i] = toupper(nombre[i]);
    }
}