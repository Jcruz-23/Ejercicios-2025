#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo{
char letras;
struct Nodo* sig;
struct Nodo* ant;
}Nodo;
void generar(struct Nodo** p);
void guardar(struct Nodo** p, int);
void mostrar(struct Nodo* p);
void liberar(struct Nodo** p);
int main(){
Nodo* p;
int op = 0;
char fin = ' ';
int flag = 0;

do{
printf("=====================MENU====================="
    "\n1)Generar letras"
    "\n2)Mostrar letras"
    "\n3)Calcular vocales y consonantes"
    "\n=============================================="
    "\nOpcion: ");
    scanf(" %d", &op);

    switch(op){
        case 1: 
    }

    printf("\nDesea continuar? (s/n): ");
    scanf(" %c", &fin);
}while(fin == 'S'|| fin == 's');
}

void guardar(struct Nodo** p, int v){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->letras = v;
    nuevo->sig = NULL;

    if(*p == NULL){
        *p = nuevo;
    }else{
        Nodo *aux = *p;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void generar(struct Nodo** p){

}

void mostrar(struct Nodo* p){

}

void liberar(struct Nodo** p){

}
