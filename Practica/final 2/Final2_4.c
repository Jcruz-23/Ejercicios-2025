#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
/*Desarrolla un programa que permita la gestión de registro de ventas en una tienda de electronica de este año utilizando el TDA lista. Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre código de producto (entero), nombre de producto (cadena), cantidad vendida, precio unitario, día y mes. Desarrolla las siguientes funciones para: 

    Registrar una nueva venta.
    Mostrar un listado de todas las ventas por consola y generar un archivo .txt llamado "ventas.txt", ambos en formato tabla. 
    Borrar una venta 
    Mostrar un listado de ventas por mes en formato tabla. 
    Calcular la cantidad de ventas mayores a 1000. */

typedef struct{
    int cod;
    char nombre[15];
    int ventas;
    float precio;
    int dia;
    int mes;
}Venta;

typedef struct Nodo{
    Venta venta;
    struct Nodo* sig;
}Nodo;

void menu();
void enlistar(Nodo**, Venta venta);
void registrar(Nodo**);
void mostrar(Nodo*);
void borrar(Nodo**);
void liberar(Nodo**);
void ventasMayores(Nodo*);
void ventasPorMes(Nodo*);
void mayus(char*);

int main(){
    menu();
    return 0;
}

void menu(){
    Nodo* lista = NULL;
    int op = 0;
    do{
        system("clear");
        printf("================MENU================"
            "\n0) Salir"
            "\n1) Registrar venta"
            "\n2) Mostrar ventas/generar .txt"
            "\n3) Borrar venta"
            "\n4) Mostrar ventas por mes"
            "\n5) Calcular ventas mayores a $1000"
            "\n===================================="
            "\nOpcion:");
        scanf(" %d", &op);

        switch(op){
            case 0:
                printf("\ncerrando. . .");
                break;
            case 1:
                registrar(&lista);
                break;
            case 2:
                if(lista != NULL) mostrar(lista);
                else printf("\nLista vacia!");
                break;
            case 3:
                if(lista != NULL) borrar(&lista);
                else printf("\nLista vacia!");
                break;
            case 4:
                if(lista != NULL) ventasPorMes(lista);
                else printf("\nLista vacia!");
                break;
            case 5:
                if(lista != NULL) ventasMayores(lista);
                else printf("\nLista vacia!");
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
    liberar(&lista);
}

void registrar(Nodo** lista){
    Venta venta;
    printf("\nNombre: ");
    getchar();
    fgets(venta.nombre,sizeof(venta.nombre),stdin);
    venta.nombre[strcspn(venta.nombre,"\n")]='\0';
    mayus(venta.nombre);
    printf("\nCod: "); scanf(" %d", &venta.cod);
    printf("\nPrecio: "); scanf(" %f", &venta.precio);
    printf("\nVentas: "); scanf(" %d", &venta.ventas);
    printf("\nDia: "); scanf(" %d", &venta.dia);
    printf("\nMes: ");
    do{
        scanf(" %d", &venta.mes);
        if(venta.mes>12 || venta.mes<1) printf("\nError!!.. ingresar mes de vuelta:");
    }while(venta.mes>12 || venta.mes<1);
    enlistar(lista, venta);
}

void enlistar(Nodo** lista, Venta v){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->venta = v;
    nuevo->sig = NULL;

    if(*lista == NULL) *lista = nuevo;
    else{
        Nodo* aux = *lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void mostrar(Nodo* lista){
    FILE* a;
    Nodo* aux = lista;
    a = fopen("ventas.txt", "w");
    printf("\n|%-4s |%-15s |%-7s |%-7s |%-3s | %-3s |", "Cod", "Nombre", "Ventas", "Precio", "dia", "mes");
    fprintf(a, "|%-4s |%-15s |%-7s |%-7s |%-3s | %-3s |", "Cod", "Nombre", "Ventas", "Precio", "dia", "mes");
    while(aux != NULL){
    printf("\n|%-4d |%-15s |%-7d |%-7.2f |%-3d | %-3d |", aux->venta.cod, aux->venta.nombre, aux->venta.ventas, aux->venta.precio, aux->venta.dia, aux->venta.mes);
    fprintf(a, "\n|%-4d |%-15s |%-7d |%-7.2f |%-3d | %-3d |", aux->venta.cod, aux->venta.nombre, aux->venta.ventas, aux->venta.precio, aux->venta.dia, aux->venta.mes);
    aux = aux->sig;
    }
    fclose(a);
}

void borrar(Nodo** lista){
    int buscar = 0;
    Nodo* aux = *lista;
    Nodo* ant = NULL;

    printf("\nIngrese codigo de venta que desea borrar: "); scanf(" %d", &buscar);
    while((aux != NULL) && (buscar != aux->venta.cod)){
        ant = aux;
        aux = aux->sig;
    }
    
    if(aux != NULL){
        if(ant != NULL){
            ant->sig = aux->sig;
        }else{
            *lista = aux->sig;
        } 
        free(aux);
        printf("\nTarea borrada!");
    }else{
        printf("\nNo se encontro la tarea");
    }
}

void liberar(Nodo**lista){
    Nodo *aux = *lista;
    while(aux != NULL){
        aux = (*lista)->sig;
        free(*lista);
        *lista = aux;
    }
}

void ventasMayores(Nodo* lista){
    Nodo* aux = lista;
    int cont = 0;
    while(aux != NULL){
        if(aux->venta.precio>1000) cont++;
        aux = aux->sig;
    }
    printf("\nVentas mayores a mil: %d", cont);
}

void ventasPorMes(Nodo* lista){
    Nodo* aux = NULL;
    printf("\n|%-4s |%-15s |%-7s |%-7s |%-3s | %-3s |", "Cod", "Nombre", "Ventas", "Precio", "dia", "mes");
    for(int i = 1; i <= 12; i++){
        aux = lista;

        while(aux != NULL){
            if(aux->venta.mes == i){
                printf("\n|%-4d |%-15s |%-7d |%-7.2f |%-3d | %-3d |",
                       aux->venta.cod,
                       aux->venta.nombre,
                       aux->venta.ventas,
                       aux->venta.precio,
                       aux->venta.dia,
                       aux->venta.mes);
            }
            aux = aux->sig; 
        }
    }

}

void mayus(char *nombre){
    int cant = strlen(nombre);
    for(int i = 0; i < cant; i++){
        nombre[i] = toupper(nombre[i]);
    }
}