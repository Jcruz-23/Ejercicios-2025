/*Desarrolle un programa que cargue una cola de números enteros aleatorios y muestre. Luego arme una función que muestre el tamaño de la cola y otra función que muestre el valor del frente de la cola.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Nodo{
    int v;
    struct Nodo* sig;
}Cola;

void menu();
void encolar(Cola**, Cola**, int);
void aleatorio(Cola**, Cola**);
void tamanio(Cola*);
void mostrarFrente(Cola*);
void mostrar(Cola*);
void Liberar(Cola**);

int main(){
    srand(time(NULL));
    menu();
}

void menu(){
    Cola* frente = NULL;
    Cola* final = NULL;
    char fin = 's';
    int op = 0;
    int flag = 0;
    do{
        system("clear");
        printf("================MENU================"
            "\n1) Encolar numero aleatorio"
            "\n2) Mostrar cola"
            "\n3) Mostrar frente"
            "\n4) Mostrar tamanio de cola"
            "\n5) Salir"
            "\n===================================="
            "\nOpcion: ");
        scanf(" %d", &op);

        switch(op){
            case 1:
            flag = 1;
            aleatorio(&frente, &final);
            break;
            case 2:
            if(flag == 1){
                mostrar(frente);
            }else{
                printf("\nNo se cargo ningun numero");
            }
            break;
            case 3: 
              if(flag == 1){
                mostrarFrente(frente);
            }else{
                printf("\nNo se cargo ningun numero");
            }
            break;
            case 4:
              if(flag == 1){
                tamanio(frente);
            }else{
                printf("\nNo se cargo ningun numero");
            } 
            break;
            case 5: 
            fin = 'n'; 
            break;
            default: printf("\nERROR!!"); break;
        }
        
        if(fin == 's'){
            getchar();
            getchar();
        }
    }while(fin == 's');
}

void Liberar(Cola**frente){
    Cola *aux = *frente;
    while(aux != NULL){
        aux = (*frente)->sig;
        free(*frente);
        *frente = aux;
    }
}

void encolar(Cola** frente, Cola** final, int v){
    Cola* nuevo = (Cola*) malloc(sizeof(Cola));
    nuevo->v = v;
    nuevo->sig = NULL;

    if(*final == NULL){
        *frente = nuevo;
        *final = nuevo;
    }else{
        (*final)->sig = nuevo;
        *final = nuevo;
    }
}

void aleatorio(Cola** frente, Cola** final){
    int v = rand()%10+1;
    printf("%d encolado", v);
    encolar(frente, final, v);
}

void mostrar(Cola* frente){
    Cola* aux = frente;
    while(aux!=NULL){
        printf("%d->", aux->v);
        aux = aux->sig;
    }
    printf("NULL");
}

void mostrarFrente(Cola* frente){
    Cola* aux = frente;
    printf("\nNumero en el frente: %d", frente->v);
}

void tamanio(Cola* frente){
    Cola* aux = frente;
    int tamanio = 0;
    while(aux !=NULL){
        tamanio+=sizeof(aux);
        aux = aux->sig;
    }
    printf("\nTamanio de la cola: %d bytes", tamanio);
}