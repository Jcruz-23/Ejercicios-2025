/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la pila.
- Borrar el último nodo de la pila.
- Imprimir pila.
- Cantidad de nodos en la pila.
- Cantidades de letras mayúsculas y minúsculas en la pila.

El usuario cargará la pila con letras mayúsculas o minúsculas. 

Nota: Las letras en ASCII mayúsculas están entre el 65 a 90 y 
las minúsculas entre  97 a 122 inclusive.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pila{
    char val;
    struct Pila* sig; 
}Pila;

void menu();
void agregar(Pila**, char);
void borrar(Pila**);
void liberar(Pila**);
void mostrar(Pila*);
void cantidadPilas(Pila*);
void cantidadLetras(Pila*);

int main(){
menu();
}

void menu(){
    Pila* p = NULL;
    char v = 0;
    char op = ' ';
    char fin = ' ';
    int flag = 0;
    do
    {
        system("clear");
        printf( "Seleccione una opcion:\n"
            "a. Agregar Letra\n"
            "b. Borrar ultimo Nodo\n"
            "c. Imprimir Nodo\n"
            "d. Cantidad de nodos de la Nodo\n"
            "e. Cantidad de letras mayus y minus\n");scanf(" %c",&op);
            
        switch(op){
            case 'A':
            case 'a':
            flag = 1;
            printf("\nIngrese una Letra: ");scanf(" %c",&v);
            agregar(&p,v);
            break;
            case 'B':
            case 'b': 
            if (flag == 1){
            borrar(&p);
            }else{
                printf("\nDatos sin cargar!");
            }
            break;
            case 'C':
            case 'c': 
            if (flag == 1){
            mostrar(p);
            }else{
                printf("\nDatos sin cargar!");
            }
            break;
            case 'D':
            case 'd': 
            if (flag == 1){
            cantidadPilas(p);
            }else{
                printf("\nDatos sin cargar!");
            }break;
            case 'E':
            case 'e': 
            if (flag == 1){
            cantidadLetras(p);
            }else{
                printf("\nDatos sin cargar!");
            }break;
            default: break;
        }

        printf("\nDesea continuar? (s/n)");scanf(" %c", &fin);
    } while (fin == 's' || fin == 'S');

    liberar(&p);
}

void agregar(Pila** p,char v){
    Pila* nuevo = (Pila*)malloc(sizeof(Pila));
    nuevo->val = v;
    nuevo->sig = *p;
    *p = nuevo;
}

void mostrar(Pila* p){
    Pila* aux = p;
    while(aux != NULL){
        printf("%c->", aux->val);
        aux = aux->sig;
    }
    printf("NULL");
}

void cantidadPilas(Pila* p){
    Pila* aux = p;
    int cant = 0;
    while(aux != NULL){
        cant++;
        aux = aux->sig;
    }
    printf("\nCantidad de pilas: %d", cant);
}
void cantidadLetras(Pila* p){
    Pila* aux = p;
    int cantMayus = 0;
    int cantMinus = 0;
    while(aux != NULL){
        if(aux->val >= 65 && aux->val <= 90) cantMayus++;
        if(aux->val >= 97 && aux->val <= 122) cantMinus++;
        aux = aux->sig;
    }
    printf("\nCantidad de minusculas: %d", cantMinus);
    printf("\nCantidad de mayusculas: %d", cantMayus);

}

void liberar(Pila** p){
    Pila *aux = *p;
    while(aux!=NULL){
        aux = (*p)->sig;
        free(*p);
        *p = aux;
    }
}

void borrar(Pila** p){
        Pila* prox = (*p)->sig;
        free(*p);
        *p = prox;
}

