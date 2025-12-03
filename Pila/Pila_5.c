/*Desarrolle un programa que cargue una pila de números enteros aleatorios.  Luego realice un menú de opciones:
- Agregar un nodo a la pila. (cuando agrega un valor, el mismo no tiene que estar repetido en la pila)
- Borrar el último nodo de la pila.
- Imprimir pila.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pila{
int val;
struct Pila* sig;
}Pila;

void menu();
void agregar(Pila**, int);
void borrar(Pila**);
void mostrar(Pila*);
int main(){
menu();
}

void menu(){
    int v = 0;
    char fin = ' ';
    int op = 0;
    int flag = 0;
    Pila* p = NULL;
    do{
        system("clear");
        printf("================MENU================"
            "\n1) Agregar numero aleatorio"
            "\n2) Borrar ultimo nodo"
            "\n3) Mostrar pila completa"
            "\n===================================="
            "\nOpcion:");
        scanf(" %d", &op);

        switch(op){
            case 1:
            v = rand()%99+1;
            agregar(&p, v);
            printf("\nSe agrego %d", v);
            break;
            case 2: break;
            case 3: break;
            default: break;
        }
        printf("\n¿Desea elegir otra opción? (s/n): ");
        scanf(" %c", &fin);
    }while(fin == 's' || fin == 'S');
}