/*Crear un programa con el siguiente menu de opciones: 
- Agregar un nodo a la cola. (se deben agregar 5 valores)
- Borrar el primer nodo de la cola.
- Imprimir cola.
- Suma de los valores de la cola.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo* sig;
}Cola;

void menu();
void encolar(Cola**,Cola**, int);
void desencolar(Cola**,Cola**);
int colaVacia(Cola*);
void mostrar(Cola*);
void liberar(Cola**);
void sumarValores(Cola*);
void ingresar(Cola**, Cola**);

int main(){
    menu();
}

void menu(){
    Cola* frente = NULL;
    Cola* final = NULL;
    char fin = 's';
    int op = 0;
    int flag = 0;
    int flagError = 0;
    do{
        system("clear");
        printf("================MENU================"
            "\n1) Agregar 5 valores"
            "\n2) Borrar primer nodo"
            "\n3) Imprimir cola"
            "\n4) Sumar valores"
            "\n5) Salir"
            "\n===================================="
            "\nOpcion:");
        scanf(" %d", &op);
        
        switch(op){
            case 1: 
            flag = 1;
            ingresar(&frente, &final);
            break;
            case 2: 
            if(flag == 1){
                desencolar(&frente, &final);
            }
            break;
            case 3: 
            if(flag == 1) mostrar(frente);
            break;
            case 4: 
            if(flag == 1) sumarValores(frente);
            break;
            case 5: fin = 'n'; break;
            default: flagError = 1; printf("\nERROR!!"); break;
        }

        if(flag == 0 && fin == 's' && flagError == 0) printf("\nValores no ingresados");
        flagError = 0; 
        if(fin == 's'){
            getchar();
            getchar();
        }
        
    }while(fin == 's');
}


void encolar(Cola** frente, Cola** fin, int v){
    Cola* nuevo = (Cola*) malloc(sizeof(Cola));
    nuevo->valor = v;
    nuevo->sig = NULL;

    if(*fin == NULL){
        *frente = nuevo;
        *fin = nuevo;
    }else{
        (*fin)->sig = nuevo;
        *fin = nuevo;
    }
}

void ingresar(Cola** frente, Cola** fin){
    int v = 0;
    printf("\nIngrese 5 valores: ");
    for(int i=0;i<5;i++){
        printf("\nvalor [%d]: ", i+1);
        scanf(" %d", &v);
        encolar(frente, fin, v);
    }
}

void desencolar(Cola** frente, Cola** fin){
    if(colaVacia(*frente)){
        printf("\nCola vacia");
    } 
    Cola* aux = *frente;
    int valorDevolver = aux->valor;
    *frente = aux->sig;
    if(*frente == NULL) *fin = NULL;
    free(aux);
    printf("\nValor desencolado: %d", valorDevolver);
}

int colaVacia(Cola* frente){
    return frente == NULL;
}

void mostrar(Cola* frente){
    Cola* aux = frente;
    while(aux != NULL){
        printf("%d->", aux->valor);
        aux = aux->sig;
    }
    printf("NULL");
}

void sumarValores(Cola* frente){
    Cola* aux = frente;
    int suma = 0;
    while(aux != NULL){
        suma += aux->valor;
        aux = aux->sig;
    }
    printf("\nSuma total: %d", suma);
}

void Liberar(Cola** frente){
    Cola *aux = *frente;
    while(aux != NULL){
        aux = (*frente)->sig;
        free(*frente);
        *frente = aux;
    }
}