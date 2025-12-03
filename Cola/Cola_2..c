/*Crear un programa en el cual cargue una cola de 5 números aleatoriamente (entre 1 y 10), luego los muestre a todos y muestre solo los valores pares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo{
    int valor;
    struct Nodo* sig;
}Cola;

void aleatorio(Cola**, Cola**);
void agregarNodo(Cola**, Cola**, int);
void mostrar(Cola*);
void mostrarPares(Cola*);
void Liberar(Cola**);
void menu();

int main(){
    srand(time(NULL));
    menu();
}

void menu(){
    Cola* frente = NULL;
    Cola* final = NULL;
    char fin = 's';
    int op = 0;
    int flag = 0;
    do{
        system("clear");
        printf("================MENU================"
            "\n1) Ingresar numeros aleatorios"
            "\n2) Mostrar cola"
            "\n3) Mostrar valores pares"
            "\n4) Salir"
            "\n===================================="
            "\nOpcion:");scanf(" %d", &op);

            switch(op){
                case 1: 
                flag = 1;
                aleatorio(&frente, &final);
                break;
                case 2: 
                if(flag == 1){ 
                    mostrar(frente);
                }else{
                    printf("\nValores no ingresados");
                }    
                break;
                case 3: 
                if(flag == 1){ 
                    mostrarPares(frente);   
                }else{
                    printf("\nValores no ingresados");
                }  
                break;
                case 4: 
                fin = 'n';
                break;
                default: printf("\nError!!!"); break;
            }

            if(fin == 's'){
                getchar();getchar();
            }
    }while(fin == 's' || fin == 'S');

    Liberar(&frente);
}

void Liberar(Cola**frente){
    Cola *aux = *frente;
    while(aux != NULL){
        aux = (*frente)->sig;
        free(*frente);
        *frente = aux;
    }
}

void agregarNodo(Cola** frente, Cola** final, int v){
    Cola* nuevo = (Cola*) malloc(sizeof(Cola));
    nuevo->valor = v;
    nuevo->sig = NULL;

    if(*frente == NULL){
        *frente = nuevo;
        *final = nuevo;
    }else{
        (*final)->sig = nuevo;
        *final = nuevo;
    }
}

void aleatorio(Cola** frente, Cola** final){
    int v = 0;
    for(int i=0;i<5;i++){
        v = rand()%10+1;
        agregarNodo(frente, final, v);
        printf("\nNumero[%d]: %d", i+1, v);
    }
}

void mostrar(Cola* frente){
    Cola* aux = frente;
    while(aux != NULL){
        printf("%d->", aux->valor);
        aux = aux->sig;
    }
    printf("NULL");
}

void mostrarPares(Cola* frente){
     Cola* aux = frente;
    while(aux != NULL){
        if(aux->valor%2 == 0){
            printf("%d->", aux->valor);
        }
        aux = aux->sig;
    }
    printf("NULL");
}
