#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

/*Implementa un programa que gestione los datos de un proyecto de construcción utilizando un TDA. El TDA debe almacenar información sobre las diferentes tareas del proyecto, incluyendo nombre de la tarea, duración estimada (entero) y estado de la tarea (pendiente/terminada/retrasada). Desarrolla las siguientes funciones para:

    Agregar una nueva tarea al proyecto.
    Mostrar la lista de tareas por consola y generar un archivo txt llamado "proyecto.txt".
    Eliminar una tarea del proyecto.
    Calcular el porcentaje de avance del proyecto.

Crea un menú de opciones para que el usuario pueda realizar diferentes acciones*/

typedef struct{
    char nombre[15];
    int duracion;
    char estado[9];
}Info;

typedef struct Nodo{
    Info info;
    struct Nodo* sig;
}Nodo;

void menu();
void ingresar(Nodo**);
void enlistar(Nodo**, Info);
void mostrar(Nodo*);
void mayus(char*);
void liberar(Nodo**);
void borrar(Nodo**);
void progreso(Nodo*);


int main(){  
    menu();  
    return 0;
}

void menu(){
    Nodo* tarea = NULL;
    int op = 0;
    do{
        system("clear");
        printf("================MENU================"
            "\n0) Salir"
            "\n1) Agregar tarea"
            "\n2) Mostrar tareas/generar .txt"
            "\n3) Eliminar tarea"
            "\n4) Calcular avance"
            "\n===================================="
            "\nOpcion:");
        scanf(" %d", &op);

        switch(op){
            case 0:
                printf("\ncerrando. . .");
                break;
            case 1:
                ingresar(&tarea);
                break;
            case 2:
                if(tarea != NULL) mostrar(tarea);
                else printf("\nLista vacia!");
                break;
            case 3:
                if(tarea != NULL) borrar(&tarea);
                else printf("\nLista vacia!");
                break;
            case 4:
                if(tarea != NULL) progreso(tarea);
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

    liberar(&tarea);
}

void ingresar(Nodo** tarea){
    Info info;
    int op = 0;
    printf("\nNombre de la tarea: ");
    getchar();
    fgets(info.nombre,sizeof(info.nombre),stdin);
    info.nombre[strcspn(info.nombre,"\n")]='\0';
    mayus(info.nombre);
    printf("\nDuracion (dias): "); scanf(" %d", &info.duracion);
    printf("\nEstado:\n1)pendiente\n2)terminado\n3)retrasado\nopcion: "); 
    do{
        scanf(" %d", &op);
        switch(op){
        case 1: strcpy(info.estado, "pendiente"); break;
        case 2: strcpy(info.estado, "terminada"); break;
        case 3: strcpy(info.estado, "retrasada"); break;
        default: printf("\nerror!!\nElija una de las opciones dadas: ");
        }
    }while(op<1 || op>3);
    

    enlistar(tarea, info);
}

void enlistar(Nodo** tarea, Info info){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->info = info;
    nuevo->sig = NULL;

    if(*tarea == NULL) *tarea = nuevo;
    else{
        Nodo* aux = *tarea;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void mostrar(Nodo* tarea){
    FILE* a;
    Nodo* aux = tarea;
    int cont = 0;
    printf("\n|%-4s |%-15s |%-10s |%-15s |", "cont", "tarea", "duracion", "estado");
    while(aux != NULL){
        cont++;
        printf("\n|%-4d |%-15s |%-10d |%-15s |", cont, aux->info.nombre, aux->info.duracion, aux->info.estado);
        aux = aux->sig;
    }
    
    cont = 0;
    aux = tarea;
    a = fopen("tareas.txt", "w");
    
    fprintf(a, "|%-4s |%-15s |%-10s |%-10s |", "cont", "tarea", "duracion", "estado");
    while(aux != NULL){
        cont++;
        fprintf(a, "\n|%-4d |%-15s |%-10d |%-10s |", cont, aux->info.nombre, aux->info.duracion, aux->info.estado);
        aux = aux->sig;
    }
    fclose(a);
}

void borrar(Nodo** tarea){
    char buscar[15];
    printf("\nIngrese tarea que desee borrar: ");
    getchar();
    fgets(buscar,sizeof(buscar),stdin);
    buscar[strcspn(buscar,"\n")]='\0';
    mayus(buscar);


    Nodo* aux = *tarea;
    Nodo* ant = NULL;

    while((aux != NULL) && (strcmp(buscar, aux->info.nombre )!=0)){
        ant = aux;
        aux = aux->sig;
    }
    
    if(aux != NULL){
        if(ant != NULL){
            ant->sig = aux->sig;
        }else{
            *tarea = aux->sig;
        } 
        free(aux);
        printf("\nTarea borrada!");
    }else{
        printf("\nNo se encontro la tarea");
    }
}

void progreso(Nodo* tarea){
    Nodo* aux = tarea;
    int contTerminadas = 0;
    int contTotal = 0;
    float avance = 0;
    while(aux != NULL){
        if(strcmp(aux->info.estado, "terminada") == 0) contTerminadas++;
        else contTotal++;
        aux = aux->sig;
    }
    contTotal+=contTerminadas;
    avance = (float) 100*contTerminadas/contTotal;
    printf("\nProgreso de la construccion: %.2f%%", avance);
}

void mayus(char *nombre){
    int cant = strlen(nombre);
    for(int i = 0; i < cant; i++){
        nombre[i] = toupper(nombre[i]);
    }
}

void liberar(Nodo**tarea){
    Nodo *aux = *tarea;
    while(aux != NULL){
        aux = (*tarea)->sig;
        free(*tarea);
        *tarea = aux;
    }
}