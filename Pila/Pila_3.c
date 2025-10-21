/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la pila. (se deben agregar 5 valores)
- Borrar el último nodo de la pila.
- Imprimir pila.
- Tamaño de la pila
- Mostrar el último valor de la pila
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int val;
    struct Nodo* sig;
}Pila;

void menu();
void agregar(Pila**, int);
void borrar(Pila**);
void mostrar(Pila*);
void liberar(Pila**);
int tamanio(Pila*);
int ultimo(Pila*);

int main(){
    menu();
    return 0;
}

void menu(){
    char op = ' ';
    char fin = ' ';
    int v = 0;
    int flag = 0;
    Pila* p = NULL;
    int ult = 0;
    int res = 0;

    do{
        printf( "================MENU================\n"
            "Seleccione una opcion:\n"
            "a. Agregar valor\n"
            "b. Borrar ultimo Nodo\n"
            "c. Imprimir Pila\n"
            "d. Calcular tamanio de la pila\n"
            "e. Imprimir ultimo valor\n"
            "====================================\n"
            "opcion: " );scanf(" %c",&op);
            printf("\n");

            switch(op){
                case 'A':
                case 'a':
                if(flag == 0){
                    for(int i = 0; i<5; i++){
                        printf("Agregar valor[%d]: ", i+1); scanf(" %d", &v);
                        agregar(&p, v);
                        printf("\n");
                    }
                    flag = 1;
                }else{
                    printf("Valores ya cargados\n");
                }
                break;
                case 'B':
                case 'b':
                if(flag == 1){
                    borrar(&p);
                }else{
                    printf("\nLos valores NO fueron cargados");
                }
                break;
                case 'C':
                case 'c': 
                if(flag == 1){
                    mostrar(p);
                }else{
                    printf("\nLos valores NO fueron cargados");
                }
                break;
                case 'D': 
                case 'd':
                if(flag == 1){
                    printf("\nTamanio de la pila: %d\n", res = tamanio(p));
                }else{
                    printf("\nLos valores NO fueron cargados");
                }
                break;
                case 'e':
                case 'E':
                if(flag == 1){
                    printf("\nUltimo valor: %d", ult = ultimo(p));
                }else{
                    printf("\nLos valores NO fueron cargados");
                }
                break;
                default: printf("\nError!!"); break;
            }
            
        printf("\n\nDesea continuar? (s/n)\n");
        scanf(" %c", &fin);
    } while (fin == 's'|| fin == 'S');
    liberar(&p);
}

void agregar(Pila** p, int v){
    Pila* nuevo = (Pila*) malloc(sizeof(Pila));
    nuevo->val = v;
    nuevo->sig = *p;
    *p = nuevo;
}

void mostrar(Pila* p){
    Pila* aux = p;
    while(aux != NULL){
        printf("%d->", aux->val);
        aux = aux->sig;
    }
    printf("NULL");
}

void borrar(Pila** p){
    Pila* aux = *p;
    int v = aux->val;
    *p = aux->sig;
    free(aux);
    printf("\nNumero %d borrado", v);
}


void liberar(Pila**p){
    Pila *aux = *p;
    while(aux!=NULL){
        aux = (*p)->sig;
        free(*p);
        *p = aux;
    }
}

int tamanio(Pila* p){
    Pila* aux = p;
    int res = 0;
    while(aux != NULL){
        res+=sizeof(aux->val);
        aux = aux->sig;
    }
    return res;
}

int ultimo(Pila* p){
    Pila* aux = p;
    int ult = 0;
    while(aux!=NULL){
        ult = aux->val;
        aux = aux->sig;
    }
    return ult;
}
