#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*Crear un programa que cree una lista de productos, para ello utilice una estructura llamada producto con los atributos código, nombre, cantidad y precio. Luego genere un menú de opciones en la cual llame a las siguientes funciones:
Agregar producto.
Mostrar lista de productos
Borre un producto por código de producto.
Mostrar una lista de los productos sin stock.*/\

typedef struct{
    int cod;
    char nombre[20];
    int cant;
    int precio;
}producto;

typedef struct Nodo{
producto producto;
struct Nodo* sig;
}Nodo;

void menu();
void agregar(Nodo** p, producto prod);
void mostrar(Nodo* p);
void borrar(Nodo** p, int);
void liberar(Nodo** p);

int main(){
menu();
}

void menu(){
    Nodo* p = NULL;
    producto nuevoProducto;
    int codBorrar = 0;
    int cont = 0;
    char fin = ' ';
    int op = 0;
    do{
        printf("===============MENU==============="
            "\n1)Agregar"
            "\n2)Mostrar"
            "\n3)Borrar"
            "\n=================================="
            "\nOpcion: "); scanf(" %d", &op);
        switch(op){
            case 1:
                cont++;
                printf("\n-----Producto %d-----", cont);
                printf("\nCodigo: "); scanf(" %d", &nuevoProducto.cod);
                printf("\nNombre: "); 
                getchar();
                fgets(nuevoProducto.nombre, sizeof(nuevoProducto.nombre), stdin);
                nuevoProducto.nombre[strcspn(nuevoProducto.nombre, "\n")] = '\0';
                printf("\nPrecio: $"); scanf(" %d", &nuevoProducto.precio);
                printf("\nCantidad: "); scanf(" %d", &nuevoProducto.cant);
                agregar(&p, nuevoProducto);
                break;
            case 2: 
                    mostrar(p);
                break;
            case 3:
            if(p == NULL){
                printf("\nLista Vacia");
            }else{
                    printf("\nCodigo del producto que desee borrar: "); scanf(" %d", &codBorrar);
                    borrar(&p, codBorrar);
            }
                break;
            default:
            printf("\n\aError!!!");
            break;
        }

        printf("\nDesea continuar?(s/n): "); scanf(" %c", &fin);
    }while(fin == 's'||fin == 'S');
    
    liberar(&p);
}


void agregar(Nodo** p, producto prod){
Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
nuevo->producto = prod;
nuevo->sig = NULL;

if(*p==NULL){
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
    int cont = 0;
    Nodo *aux = p;
    if(aux == NULL){
        printf("\nLista vacia");
    }else{
        while(aux != NULL){
        cont++;
        printf("\n------------producto[%d]------------",cont);
        printf("\nCodigo: %d", aux->producto.cod);
        printf("\nNombre: %s", aux->producto.nombre);
        printf("\nCantidad: %d", aux->producto.cant);
        printf("\nPrecio: $%d", aux->producto.precio);
        aux = aux->sig;
    }
    }
    
}

void borrar(Nodo** p, int cod){
Nodo* aux = *p;
Nodo* ant = NULL;
    while(aux != NULL && aux->producto.cod != cod){
    ant = aux;
    aux = aux->sig;
}
if(aux != NULL){
    if (ant != NULL){
        ant->sig = aux->sig;
    }else{
        *p = aux->sig;
    }
    free(aux);
}

}

void liberar(Nodo** p){
while(*p != NULL){
    Nodo* prox = (*p)->sig;
    free(*p);
    *p = prox;
}
printf("\nLista liberada");
}