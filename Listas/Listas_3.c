#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo{
int val; 
struct Nodo* ant;
struct Nodo* sig;
}Nodo;

void cargar(struct Nodo** p, int );
void mostrar(struct Nodo* p);
void limpiar(struct Nodo** p);
void divCingo(struct Nodo* p);


int main(){
char op = ' ';
char fin = ' ';
Nodo* p = NULL;
int v = 0;
int cant = 0;
int flag = 0;

srand(time(NULL));
do{
system("clear");

printf("==================MENU=================="
    "\na)Cargar Numeros"
    "\nb)Mostrar"
    "\nc)Calcular"
    "\n========================================"
    "\nOpcion: ");
    scanf(" %c", &op);

    switch(op){
        case 'a':
        case 'A':
        if(flag == 0){
            flag = 1;
            printf("\nCuantos numeros aleatorios desea cargar: ");
            scanf(" %d", &cant);
            for(int i = 0; i < cant; i++){
            v = rand()%100+1;
            cargar(&p, v);
            printf("\nNum[%d] cargado", i+1);
            }
        }else{
            printf("Numeros ya cargados");
        }
        break;
        case 'b':
        case 'B':
        if(flag == 1){
            mostrar(p);
        }else{
            printf("\nFaltan cargar numeros");
        }
        break;
        case 'c':
        case 'C':
        if(flag == 1){
            divCinco(p);
        }else{
            printf("\nFaltan cargar numeros");
        }
        break;
        default:
        printf("\nError!!1!!!!11!");
        break;
    }


    printf("\nDesea continuar?(s/n): ");
    scanf(" %c", &fin);

    
}while(fin == 's'||fin == 'S');
limpiar(&p);
return 0;
}

void cargar(struct Nodo** p, int v){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->val = v;
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


void mostrar(struct Nodo* p){
    Nodo* aux = p;
    while(aux != NULL){
        printf("%d->", aux->val);
        aux = aux->sig;
    }
    printf("NULL");
}

void limpiar(struct Nodo** p){
    while(*p != NULL){
        Nodo* prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
}

void divCinco(struct Nodo* p){
    Nodo* aux = p;
    while(aux != NULL){
        if(aux->val%5 == 0){
            printf("%d->", aux->val);
        }
    aux = aux->sig;
    }
    printf("NULL");
}
