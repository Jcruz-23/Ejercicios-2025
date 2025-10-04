#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*Crear un programa en el cual cargue una lista de 5 números aleatoriamente (entre 1 y 10), luego los muestre todos los valores. Finalmente borre un valor y vuelve a mostrar la lista resultante. Genere un menú de opciones para las funciones.*/

typedef struct Nodo{
int val;
struct Nodo* sig;
}Nodo;

void agregar(Nodo** p, int);
void mostrar(Nodo* p);
void borrar(Nodo** p, int);
void liberar(Nodo** p);
void menu();

int main(){
    srand(time(NULL));
menu();
return 0;
}

void menu(){
Nodo* p;
int v = 0;
int op = 0;
char fin = ' ';
int flag = 0;

do{
system("clear");
printf("===============MENU==============="
    "\n1)Agregar 10 valores aleatorios"
    "\n2)Mostrar"
    "\n3)Borrar" 
    "\n=================================="
    "\nOpcion: "); scanf(" %d", &op);

    switch(op){
        case 1:
        if (flag == 0){
            for(int i = 0; i < 10; i++){
                flag = 1;
                v = rand()%10+1;
                agregar(&p,v);
                printf("\nValor %d cargado",v);
            }
        }else{
                printf("\nValores ya cargados");
            }
        break;
        case 2:
        if(flag==1){
            mostrar(p);
        }else{
            printf("\nValores sin cargar");
        }
        break;
        case 3:
        if(flag==1){
            printf("\nQue numero desea borrar: "); scanf(" %d", &v);
            borrar(&p, v);
            printf("\n\n");
            mostrar(p);
        }else{
            printf("\nValores sin cargar");
        }
        break;
        default:
        printf("\nError!!!");
        break;
    }

    printf("\nDesea Continuar? (s/n): "); scanf(" %c", &fin);
}while(fin == 's'||fin == 'S');
liberar(&p);
}

void agregar(Nodo** p,int v){
Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
nuevo->val = v;

if(*p == NULL){
    *p = nuevo;
}else{
    Nodo* aux = *p;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = nuevo;
}
}

void mostrar(Nodo* p){
Nodo* aux = p;

while(aux->sig != NULL){
    printf("%d->", aux->val);
    aux = aux->sig;
}
printf("NULL");
}

void borrar(Nodo** p, int v){
Nodo* aux = *p;
Nodo* ant=NULL;
while((aux !=NULL)&&(aux->val!=v)){
    ant=aux;
    aux=aux->sig;
    }
    if(aux != NULL){
        if(aux != NULL){
        if(ant!=NULL){
            ant->sig = aux->sig;
        }else{
            *p=aux->sig;
        }
        free(aux);
        }
    }else{
        printf("\nNo se encontro el numero %d", v);
    }
}



void liberar(Nodo** p){
while(*p != NULL){
    Nodo* prox = (*p)->sig;
    free(*p);
    *p=prox;
}
}

