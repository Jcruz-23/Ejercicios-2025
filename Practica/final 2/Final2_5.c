#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*Desarrolla un programa que permita la gestión de reservas en una empresa de cruceros utilizando el TDA pila. Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre número de reserva (entero), nombre del pasajero (cadena), número de cabina (entero), costo por noche (decimal), cantidad de noches (entero), día (entero) y mes (entero) de la reserva. 

Crea un menú de opciones que se repetirá hasta que el usuario decida finalizar el programa. Este menú debe permitir la elección de opciones en letras mayúsculas o minúsculas y, para cada caso, llamará a las siguientes funciones:

    Registrar una nueva reserva. 
    Mostrar un listado de todas las reservas por consola y generar un archivo .txt llamado "reserva_crucero.txt", ambos en formato tabla. 
    Borrar una reserva 
    Mostrar un listado de reservas por mes en formato tabla. El mes es ingresado por el usuario
    Calcular la cantidad de reservas cuyo costo total sea mayor a 2000. 

Nota: Los datos pueden ser cargados o bien utilizar números aleatorios.*/

typedef struct{
    int num;
    char pasajero[15];
    int cabina;
    float precio;
    int Noches;
    int dia;
    int mes;
}Info;

typedef struct Nodo{
    Info info;
    struct Nodo* sig;
}Nodo;

void menu();
void reserva(Nodo**);
void enlistar(Nodo**, Info);
void borrar(Nodo**);
void mostrar(Nodo*);
void costoMayor(Nodo*);
void liberar(Nodo**);
void mostrarPorMes(Nodo*);

int main(){
    srand(time(NULL));
    menu();
    return 0;
}

void menu(){
    Nodo* lista;
    int op = 0;
    Nodo* lista;
    do{
        system("clear");
        printf("================MENU================"
            "\n0) Salir"
            "\n1) Reservar"
            "\n2) Borrar Reserva"
            "\n3) Mostrar/Crear .txt"
            "\n4) Mostrar por mes"
            "\n5) Reservas mayores a 2000"
            "\n===================================="
            "\nOpcion:");
        scanf(" %d", &op);

        switch(op){
            case 0:
                printf("\ncerrando. . .");
                break;
            case 1: 
                reserva(&lista);
                break;
            case 2:     
                if(lista != NULL) borrar(&lista);
                else printf("\nLista vacia!"); 
                break;
            case 3: 
                if(lista != NULL) mostrar(lista);
                else printf("\nLista vacia!");
                break;
            case 4:
                if(lista != NULL) costoMayor(lista);
                else printf("\nLista vacia!");
                break;
            case 5:
                 if(lista != NULL) mostrarPorMes(lista);
                else printf("\nLista vacia!");
                break;
            case 6:
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

void reserva(Nodo** lista){
    Info info;
    int precio = 1200;
    printf("\nIgrese nombre: ");
    getchar();
    fgets(info.pasajero,sizeof(info.pasajero),stdin);
    info.pasajero[strcspn(info.pasajero,"\n")]='\0';
    info.num = rand()%500+1;
    printf("\nMes: "); scanf(" %d", &info.dia);
    printf("\nDia: "); scanf(" %d", &info.mes);
    printf("\nCant. Noches: "); scanf(" %d", &info.Noches);
    info.precio = (float) info.Noches * precio;
    info.cabina = rand()%500+1;

    enlistar(lista, info);
}

void enlistar(Nodo** lista, Info info){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->info = info;
    nuevo->sig = NULL;

    if(*lista == NULL){
        *lista = nuevo;
    }else{
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
    a = fopen("reserva_crucero.txt", "w");
    printf( "\n|%-3s |%-15s |%-6s |%-3s |%-3s |%-5s | %-6s", 
        "Num", "Nombre", "Cabina", "Mes", "Dia", "Noches", "Precio");
    fprintf(a, "\n|%-3s |%-15s |%-6s |%-3s |%-3s |%-5s | %-6s", 
        "Num", "Nombre", "Cabina", "Mes", "Dia", "Noches", "Precio");
    while(aux != NULL){
        printf( "\n|%-3d |%-15s |%-6d |%-3d |%-3d |%-5d | %-6.2f", 
        aux->info.num, aux->info.pasajero, aux->info.cabina, aux->info.mes, aux->info.dia, aux->info.Noches, aux->info.precio);
        fprintf(a, "\n|%-3d |%-15s |%-6d |%-3d |%-3d |%-5d | %-6.2f", 
        aux->info.num, aux->info.pasajero, aux->info.cabina, aux->info.mes, aux->info.dia, aux->info.Noches, aux->info.precio);
        aux = aux->sig;
    }
    fclose(a);
}

void borrar(Nodo** lista){
    Nodo* aux = *lista;
    Nodo* ant = NULL;
    int v = 0;

    printf("\nIngrese num de pasajero que desee borrar: "); scanf(" %d", &v);
    while ((aux != NULL) && (aux->info.num != v)) {
        ant = aux;
        aux = aux->sig;
    }
    if (aux != NULL) {
        if (ant != NULL) {
            ant->sig = aux->sig;
        } else {
            *lista = aux->sig;
        }
        free(aux);
    } else {
        printf("\nNo se encontro el numero %d", v);
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

