#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
int valor;
struct Nodo *sig;
struct Nodo *ant;
}Nodo;

void ingresar(struct Nodo **p, int);
void mostrar(struct Nodo *p);
void liberar(struct Nodo **p);
float promedio(struct Nodo *p);

int main(){
    Nodo *p = NULL;
    int v = 0;
    char flag = 's';
    char op = ' ';
    char fin = ' ';
    float prom = 0;

    do{
        printf("===========Menu===========\n"
            "a-Ingresar valor\n"
            "b-Mostrar lista\n"
            "c-Mostrar promedio\n"
            "Opcion: ");
            scanf(" %c", &op);

        switch(op){
            case 'a':
            case 'A':
            flag = 's';
            while(flag == 's'){
                printf("\nIngresar valor: ");
                scanf(" %d", &v);
                ingresar(&p, v);
                printf("\ndesea ingresar otro valor? (s/n): ");
                scanf(" %c", &flag);
            }
            break;
            case 'b':
            case 'B': 
            mostrar(p);
            break;
            case 'c': 
            

            case 'C': 
            prom = promedio(p);
            printf("\nPromedio: %.2f", prom);
            break;
            default:
        }

        printf("\nDesea usar otra opcion?(s/n): ");
        scanf(" %c", &fin);

        if(fin != 's'){
            liberar(&p);
        }
    }while(fin == 'S'||fin == 's');
}

void ingresar(struct Nodo **p, int v){
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->valor = v;
    nuevo->sig = NULL;
    if(*p == NULL){
        *p = nuevo;
    }else{
        Nodo *aux = *p;

        while(aux->sig !=NULL){
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
        Nodo* prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
}

float promedio(struct Nodo *p){
        Nodo *aux = p;
        float total = 0;
        int n = 0;
        float prom = 0;

    while(aux != NULL){
        total += aux->valor;
        n++;
        aux = aux->sig;
    }

    printf("%.2f-", total);
    printf("%d", n);
    prom = (float)total/n;
    return prom;
}