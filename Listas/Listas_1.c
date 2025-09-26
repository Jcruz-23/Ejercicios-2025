#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo{
    int valor; 
    struct Nodo* ant;
    struct Nodo* sig;
}Nodo;

void ingresarValor(struct Nodo **p, int);
void mostrar(struct Nodo *p);
void liberar(struct Nodo **p);

int main(){
    int v = 0;
    Nodo *p = NULL;
    printf("\nIngresar 5 valores: \n");
    for(int i = 0;i < 5; i++){
        scanf(" %d", &v);
        ingresarValor(&p, v);
    }

    mostrar(p);
    liberar(&p);
}

void ingresarValor(struct Nodo **p, int v){
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->valor = v;
    nuevo->sig = NULL;

    if(*p == NULL){
        *p=nuevo;
    }else{
        Nodo *aux = *p;
        while (aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

}

void mostrar(struct Nodo *p){
    Nodo *aux = p;

    while(aux != NULL){
        printf("%d->", aux->valor);
        aux = aux->sig;
    }
    printf("NULL");
}

void liberar(struct Nodo **p){
    while(*p != NULL){
        Nodo *prox = (*p)->sig;

        free(*p);
        *p = prox;
    }
}