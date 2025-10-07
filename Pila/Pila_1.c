/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la pila. (se deben agregar 5 valores)
- Borrar el último nodo de la pila.
- Imprimir pila.
- Suma de los valores de la pila.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
int val;
struct Nodo* sig;
}Nodo;

void menu();
void agregar(Nodo**, int);
void mostrar(Nodo*);
void sumar(Nodo*);
void borrar(Nodo**);
void liberar(Nodo**);

int main(){
    menu();
}

void menu(){
    Nodo *p = NULL;
    int v = 0;
    char fin = ' ';
    int op = 0;
    int flag = 0;
    do{
        system("clear");
        printf("================MENU================"
            "\n1)Agregar"
            "\n2)Mostrar"
            "\n3)Borrar ultima posicion"
            "\n4)Sumar valores"
            "\n===================================="
            "\nOpcion:");scanf(" %d", &op);
            switch(op){
                case 1:
                if(flag==0){
                    flag = 1;
                    for(int i = 0; i < 5; i++){
                        printf("\nIngrese valor[%d]: ", i+1);scanf(" %d", &v);
                        agregar(&p,v);
                    }
                }else{
                    printf("\nValores ya cargados");
                }
                break;
                case 2:
                if(flag == 1){
                    mostrar(p);
                }else{
                    printf("\nNo se cargaron los valores");
                }
                break;
                case 3:
                if(flag == 1){
                    borrar(&p);
                }else{
                    printf("\nNo se cargaron los valores");
                }
                break;
                break;
                case 4:
                if(flag == 1){
                    sumar(p);
                }else{
                    printf("\nNo se cargaron los valores");
                }
                break;
                
            }
            printf("\nDesea continuar?(s/n): ");scanf(" %c", &fin);
    }while(fin == 's'|| fin == 'S');
    liberar(&p);
}

void agregar(Nodo** p, int v){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->val = v;
    nuevo->sig = *p;
    *p = nuevo;
}

void mostrar(Nodo* p){
    Nodo* aux = p;
    while(aux != NULL){
        printf("%d->", aux->val);
        aux = aux->sig;
    }
    printf("NULL");
}

void sumar(Nodo* p){
    int suma = 0;
    Nodo* aux = p;
    while(aux != NULL){
        suma += aux->val;
        aux = aux->sig;
    }
    printf("\nLa suma total es: %d", suma);
}

void borrar(Nodo** p){
    Nodo* aux = *p;
    int v = aux->val;
    *p=aux->sig;
    free(aux);
    printf("\nNumero %d borrado", v);
}

void liberar(Nodo** p){
    while(*p != NULL){
        Nodo* prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
}