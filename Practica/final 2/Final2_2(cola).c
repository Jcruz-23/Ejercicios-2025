#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Construcción

Implementa un programa que gestione los datos de un proyecto de construcción utilizando un TDA. El TDA debe almacenar información sobre las diferentes tareas del proyecto, incluyendo nombre de la tarea, duración estimada (entero) y estado de la tarea (pendiente/terminada/retrasada). Desarrolla las siguientes funciones para:

    Agregar una nueva tarea al proyecto.
    Mostrar la lista de tareas por consola y generar un archivo txt llamado "proyecto.txt".
    Eliminar una tarea del proyecto.
    Calcular el porcentaje de avance del proyecto.

Crea un menú de opciones para que el usuario pueda realizar diferentes acciones.*/

typedef struct{
    char nombre[15];
    int dur;
    char estado[9];
}Info;

typedef struct Nodo{
    Info info;
    struct Nodo* sig;
}Nodo;


void menu();
void agregar(Nodo**, Nodo**);
void encolar(Nodo**, Nodo**, Info);
void desencolar(Nodo**, Nodo**);
void mostrar(Nodo*);
void porcentaje(Nodo*);
void liberar(Nodo**);

int main(){
    menu();
    return 0;
}

void menu(){
    int op = 0;
    do{
        system("clear");
        printf("================MENU================"
            "\n0) Salir"
            "\n1)"
            "\n2)"
            "\n3)"
            "\n4)"
            "\n5)"
            "\n6)"
            "\n===================================="
            "\nOpcion:");
        scanf(" %d", &op);

        switch(op){
            case 0:
                printf("\ncerrando. . .");
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
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
}


void agregar(Nodo** frente, Nodo** final){
    int op = 0;
    Info info;
    getchar();
    printf("\nNombre de la tarea: ");
    fgets(info.nombre,sizeof(info.nombre),stdin);
    info.nombre[strcspn(info.nombre,"\n")]='\0';
    printf("\nDuracion: "); scanf(" %d", &info.dur);

    do{
        printf( "\nEstado: "
                "\n1)Pendiente"
                "\n2)Retrasada"
                "\n3)Terminada"
                "\nopcion: "); scanf(" %d", &op);
    
        switch(op){
            case 1: 
            strcpy(info.estado, "Pendiente");
            break;
            case 2: 
            strcpy(info.estado, "Retrasada");
            break;
            case 3:
            strcpy(info.estado, "Terminada"); 
            break;
            default: 
            printf("\nOpcion invalida!");
            break;
        }
    }while(op>0 || op<4);
}

void encolar(Nodo** frente, Nodo** fin, Info info){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->info = info;
    nuevo->sig = NULL;

    if(*fin == NULL){
        *frente = nuevo;
        *fin = nuevo;
    }else{
        (*fin)->sig = nuevo;
        *fin = nuevo; 
    }
}

void Liberar(Nodo**lista){
    Nodo *aux = *lista;
    while(aux != NULL){
        aux = (*lista)->sig;
        free(*lista);
        *lista = aux;
    }
}

