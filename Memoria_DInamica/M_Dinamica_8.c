#include <stdio.h>
#include <stdlib.h>


void menu();
void cargar(int*, int);
void agregar(int*, int, int *, int);
void mostrar(int *, int, int);


int main(){
    menu();
    return 0;
}

void menu(){
    char op = ' ';
    char fin = ' ';
    int *p = NULL;
    int *p2 = NULL;
    int n = 0;
    int n2 = 0;

    do{
        printf("----------------------MENU----------------------"
           "\n|a)Reservar memoria e intruducir datos         |"
           "\n|b)Agregar memoria e introducir nuevos datos   |"
           "\n|c)Mostrar datos en orden y orden invertido    |"
           "\n------------------------------------------------\n");
        scanf(" %c", &op);

        switch(op){
            case 'a': 
            printf("\nCuantos valores desea cargar?: ");
            scanf(" %d", &n);
            p = (int*) malloc(n * sizeof(int));
            cargar( p,n); 
            break;
            case 'b': 
            printf("\nCuanta memoria desea agregar?: ");
            scanf(" %d", &n2);
            p2 = (int*) realloc(p, n2 * sizeof(int));
            agregar(p, n, p2, n2); 
            break;
            case 'c': mostrar(p, n, n2); break;
            default: printf("\n\aERROR!!"); break;
           }
        printf("\n¿Desea continuar? (s/n): ");
        scanf(" %c", &fin);

    }while(fin == 's'||fin == 'S');
    

}

void cargar(int *p, int n){
    
    printf("\nAsignando memoria. . .");

    if(p == NULL){
        printf("\n\aERROR ASIGNANDO MEMORIA!");
        free(p);
    }else{
        printf("\nAsignacion de memoria exitosa");
        printf("\n\nIntroduzca datos (max %d): ", n);
        for(int i = 0; i < n; i++){
            scanf(" %d", &*(p + i));
        }
    }
}

void agregar(int *p, int n, int *p2, int n2){
    printf("\nAgregando memoria. . .");

    if(p2 == NULL){
        printf("\nERROR AGREGANDO MEMORIA!");
        free(p2);
    }else{
        p = p2;
        printf("\nAgregacion de memoria exitosa");
        printf("\n\nIntroduzca a agregar (max %d): ", n2);
        for(int i = n; i < n + n2; i++){
            scanf(" %d", &*(p + i));
        }
    }
}

void mostrar(int *p, int n, int n2){
    printf("\nDatos: ");
    for(int i = 0; i < n + n2; i++){
        printf("%d\t", *(p+i));
    }
    printf("\nDatos invertidos: ");
    for(int i = n+n2-1; i >= 0; i--){
        printf("%d\t", *(p+i));
    }
}