/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la cola.
- Borrar el primer nodo de la cola.
- Imprimir cola.
- Cantidad de nodos en la cola.
- Cantidades de letras mayúsculas y minúsculas en la cola.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    char letra;
    struct Nodo* sig;
}Cola;


void menu();
void encolar(Cola**, Cola**, char);
void desencolar(Cola**, Cola**);
void agregarLetra(Cola**, Cola**);
void mostrar(Cola*);
void Liberar(Cola**);
void cantNodos(Cola*);
void cantMayusMinus(Cola*);


int main(){
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
            "\n1) Agregar letra"
            "\n2) Borrar frente"
            "\n3) Mostrar cola"
            "\n4) Cantidad de nodos en cola"
            "\n5) Cantidad de mayusculas y minusculas"
            "\n6) Salir"
            "\n===================================="
            "\nOpcion: ");
        scanf(" %d", &op);
        
        switch(op){
            case 1: 
            flag = 1;
            agregarLetra(&frente, &final);
            break;
            case 2: 
            if(flag == 1){
                desencolar(&frente, &final);
            }else{
                printf("\nNo se agregaron letras");
            }
            break;
            case 3: 
            if(flag == 1){
                mostrar(frente);
            }else{
                printf("\nNo se agregaron letras");
            }
            break;
            case 4: if(flag == 1){
                cantNodos(frente);
            }else{
                printf("\nNo se agregaron letras");
            }
            break;
            case 5: 
            if(flag == 1){
                cantMayusMinus(frente);
            }else{
                printf("\nNo se agregaron letras");
            }break;
            case 6: fin = 'n'; break;
            default: printf("\nError!!"); break;
        }

        if(fin == 's'){
            getchar();
            getchar();
        }

    }while(fin == 's');
    Liberar(&frente);
}

void encolar(Cola** frente, Cola** final, char letra){
    Cola* nuevo = (Cola*)malloc(sizeof(Cola));
    nuevo->letra = letra;
    nuevo->sig = NULL;

    if(*final == NULL){
        *frente = nuevo;
        *final = nuevo;
    }else{
        (*final)->sig = nuevo;
        *final = nuevo;
    }
}

void desencolar(Cola** frente, Cola** final){
    if(*frente == NULL){
        printf("\nCola vacia!");
    }
    Cola* aux = *frente;
    char letraDevolver = aux->letra;
    *frente = aux->sig;
    if(*frente == NULL) *final = NULL;
    free(aux);
    printf("\nLetra borrada: %c", letraDevolver);
}

void agregarLetra(Cola** frente, Cola** final){
    char letra = ' ';
    printf("\nIngrese una letra: ");
    scanf(" %c", &letra);
    encolar(frente, final, letra);
    printf("\nletra encolada!");
}

void mostrar(Cola* frente){
    Cola* aux = frente;

    while(aux != NULL){
        printf("%c->", aux->letra);
        aux = aux->sig;
    }
    printf("NULL");
}

void Liberar(Cola**frente){
    Cola *aux = *frente;
    while(aux != NULL){
        aux = (*frente)->sig;
        free(*frente);
        *frente = aux;
    }
}

void cantNodos(Cola* frente){
    Cola* aux = frente;
    int cont = 0;
    while(aux != NULL){
        cont ++;
        aux = aux->sig;
    }
    printf("\nCantidad de nodos: %d", cont);
}

void cantMayusMinus(Cola* frente){
    Cola* aux = frente;
    int contMayus = 0;
    int contMinus = 0;
    while(aux != NULL){
        if(aux->letra >= 65 && aux->letra<+95){
            contMayus++;
        }else{
            contMinus++;
        }
        aux = aux->sig;
    }
    printf("\nCantidad de Mayusculas: %d", contMayus);
    printf("\nCantidad de Minusculas: %d", contMinus);

}