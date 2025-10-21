#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Nodo{
int v;
struct Nodo* sig;
}Nodo;

void agregar(Nodo**, int);
void mostrar(Nodo*);
void mostrarPares(Nodo*);
void liberar(Nodo**);

int main(){
    Nodo* p = NULL;
    int v = 0;
    srand(time(NULL));
    for(int i=0;i<10;i++){
        v = rand()%10+1;
        agregar(&p,v);
        printf("%d agregado\n",v);
    }

    printf("\nPila: ");
    mostrar(p);
    printf("\nPila con num pares: ");
    mostrarPares(p);

    liberar(&p);
    return 0;
}

void agregar(Nodo** p, int v){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->v = v;
    nuevo->sig = *p;
    *p = nuevo;
}

void mostrar(Nodo* p){
    Nodo* aux = p;
    while(aux != NULL){
        printf("%d->", aux->v);
        aux = aux->sig;
    }
    printf("NULL");
}

void mostrarPares(Nodo* p){
    Nodo* aux = p;
    while(aux != NULL){
        if(aux->v%2 == 0){
        printf("%d->", aux->v);
        }
        aux = aux->sig;
    }
    printf("NULL");
}

void liberar(Nodo** p){
    while(*p != NULL){
        Nodo* prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
}