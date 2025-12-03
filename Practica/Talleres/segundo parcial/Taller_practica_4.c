/*Desarrolle un programa en C que permita gestionar una colección de alumnos utilizando un TDA (Lista, Cola o Cola) implementado mediante estructuras, punteros y memoria dinámica.

Cada nodo del TDA deberá contener una estructura Alumno con los siguientes campos:

    nombre (cadena de caracteres)
    carrera (cadena de caracteres)
    promedio (número decimal)

El programa debe llamar a las siguientes funciones:

    Permitir insertar un nuevo alumno en el TDA.
    Permitir eliminar un alumno del TDA según corresponda al tipo de estructura implementada.
    Mostrar todos los alumnos almacenados, indicando nombre, carrera y promedio.
    Calcular y mostrar el promedio general de los alumnos con promedio mayor o igual a 8 (función con retorno de valor).
    Determinar y mostrar el alumno con el promedio más alto y el alumno con el promedio más bajo.

Crear un menu de opciones que se repita hasta que el usuario indique lo contrario.

Crear funciones auxiliares para si el TDA está vacía, liberar memoria y las que sean necesarias para lograr un algoritmo modular.

Asegúrese de que la presentación de la información sea clara y organizada, y que el programa gestione correctamente la memoria dinámica utilizada por el TDA.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


typedef struct{
    char nombre[20];
    char carrera[30];
    float promedio;
}Datos;
typedef struct Cola{
    Datos datos;
    struct Cola* sig;
}Cola;

void menu();
void Liberar(Cola**);
void insertar(Cola**, Cola**);
void agregar(Cola**, Cola**, char[20], char[30], float);
void mostrar(Cola*);
void promedioMasAltoBajo(Cola*);
void promedioMayorOcho(Cola*);
void borrar(Cola**);
void mayus (char*);

int main(){
    menu();
}


void menu(){
char fin = 's';
Cola* frente = NULL;
Cola* final = NULL;
int op = 0;
int flag = 0;
    
do{
    system("clear");
    printf("==================MENU=================="
        "\n1) Instertar nuevo alumno"
        "\n2) Eliminar alumno"
        "\n3) Mostrar alumnos"
        "\n4) Promedios igual o mas alto de 8"
        "\n5) Mostrar alumno con promedio mas alto"
        "\n6) Salir"
        "\n========================================"
        "\nOpcion:");scanf(" %d", &op);
        
    switch(op){
        case 1:
            flag = 1;
            insertar(&frente, &final);
            break;          
        case 2:   
            if(flag == 1){
                borrar(&frente);
            }else{
                printf("\nNo se ingresaron alumnos");
            }
            break;      
        case 3:
            if(flag == 1){
                mostrar(frente);
            }else if(flag == 0 || frente == NULL){
                printf("\nNo se ingresaron alumnos");
            }     
            break;      
        case 4:
            if(flag == 1){
                promedioMayorOcho(frente);
            }else{
                printf("\nNo se ingresaron alumnos");
            }     
            break;      
        case 5:
            if(flag == 1){
            promedioMasAltoBajo(frente);
            }else{
                printf("\nNo se ingresaron alumnos");
            } 
            break;
            case 6: fin = 'n'; break;
            default:
            printf("\nError!!");          
            break;  
        }
    if(fin == 's'){
        getchar();
        getchar();
    }
}while(fin == 's');
Liberar(&frente);
}
    


void insertar(Cola** frente, Cola** final){
    float promedio = 0;
    char nombre[20];
    char carrera[30];
    getchar();
    printf("\nNombre: ");
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strcspn(nombre,"\n")]='\0';
    mayus(nombre);
    printf("\nCarrera: ");
    fgets(carrera,sizeof(carrera),stdin);
    carrera[strcspn(carrera,"\n")]='\0';
    mayus(carrera);
    printf("\nPromedio: ");scanf(" %f", &promedio);
    agregar(frente, final, nombre, carrera, promedio);
}

void agregar(Cola** frente, Cola** final, char nombre[20], char carrera[30], float promedio){
    Cola* nuevo = (Cola*) malloc(sizeof(Cola));
    nuevo->sig = NULL;
    strcpy(nuevo->datos.carrera, carrera);
    strcpy(nuevo->datos.nombre, nombre);
    nuevo->datos.promedio = promedio;
    
    if(*final == NULL){
        *frente = nuevo;
        *final = nuevo;
    }else{
        (*final)->sig = nuevo;
        *final = nuevo;
    }
}

void mostrar(Cola* p){
    int cont = 0;
    Cola* aux = p;
    printf( "\n%-2s | %-10s | %-30s | %-5s",
            "N°", "nombre", "carrera", "prom");
    while(aux != NULL){
        cont ++;
        printf( "\n%-2d | %-10s | %-30s | %.2f",
                cont, aux->datos.nombre, aux->datos.carrera, aux->datos.promedio);
        aux = aux->sig;
    }
}

void borrar(Cola** p){
    Cola* aux = *p;
    char buscar[20];
    Cola* ant = NULL;
    printf("\nInsertar nombre que desea buscar: ");
    getchar();
    fgets(buscar,sizeof(buscar),stdin);
    buscar[strcspn(buscar,"\n")]='\0';
    mayus(buscar);

    while(aux != NULL && strcmp(aux->datos.nombre, buscar) != 0){
    ant=aux;
    aux=aux->sig;
    }   

    if(aux != NULL){
        if(ant!=NULL){
            ant->sig = aux->sig;
        }else{
            *p=aux->sig;
        }
        printf("\nBorrando: %s", aux->datos.nombre);
        free(aux);
        }else{
        printf("\nNo se encontro el nombre %s", buscar);
    }
}

void Liberar(Cola** p){
    Cola *aux = *p;
    while(aux != NULL){
        aux = (*p)->sig;
        free(*p);
        *p = aux;
    }
}

void promedioMasAltoBajo(Cola* p){
    Cola* aux = p;
    float promAlto = 0;
    float promBajo = 11;
    while(aux != NULL){
        if(aux->datos.promedio > promAlto){
            promAlto = aux->datos.promedio;
        }
        if(aux->datos.promedio < promBajo){
            promBajo = aux->datos.promedio;
        }
        aux = aux->sig;
    }
    printf("\nEl promedio mas alto es: %.2f", promAlto);
    printf("\nEl promedio mas bajo es: %.2f", promBajo);
}

void promedioMayorOcho(Cola* p){
    Cola* aux = p;
    while(aux != NULL){
        if(aux->datos.promedio >= 8){
            printf("| %.2f ", aux->datos.promedio);
        }
        aux = aux->sig;
    }
}

void mayus(char *nombre){
    int cant = strlen(nombre);
    for(int i = 0; i <cant; i++){
        nombre[i] = toupper(nombre[i]);
    }
}

