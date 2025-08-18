#include <stdio.h>
#include <stdlib.h>

void memoria(char *, int);
void cargar(char *, int);
void mostrar(char *, int);
void agregar(char *, int);
void cargarAgregado(char *, int, int);
void mostrarAgregado(char *, int, int);
int main(){
char *p = NULL;
int n = 0;
memoria(p, n);

return 0;
}

void memoria(char *p, int n){
printf("Cuantos caracteres desea escribir?: ");
scanf(" %d", &n);

p = (char *) malloc(n * sizeof(char));
printf("\nAsignando memoria. . .");

if(p == NULL){
    printf("\nError al asignar memoria!");
}else{
    printf("\nMemoria asignada correctamente");

    cargar(p, n);
    mostrar(p, n);
}
agregar(p, n);
}


void cargar(char *p, int n){
    printf("\n\nIngrese texto (max %d caracteres): ", n);
    for(int i = 0; i < n; i++){
        scanf(" %c", &*(p+i));
    }
}
void mostrar(char *p, int n){
        printf("\n\nTexto ingresado: ");
    for(int i = 0; i < n; i++){
        printf("%c\t", *(p+i));
    }
}

void agregar(char *p, int n){
    char *p2 = NULL;
    int n2 = 0;

    printf("\n\nCuantos characteres desea agregar?: ");
    scanf(" %d", &n2);

    p2 = (char *) realloc(p, n2 * sizeof(char));

    if(p2 == NULL){
        printf("\n\aError agregando memoria!");
        free(p);
    }else{
        p = p2;

        cargarAgregado(p, n, n2);
        mostrarAgregado(p, n, n2);

    }
}

void cargarAgregado(char *p, int n, int n2){
    printf("\n\nTexto a agregar: ");
    for(int i = n; i < n2 + n; i++){
        scanf(" %c", &*(p + i));
    }
}

void mostrarAgregado(char *p, int n, int n2){
    printf("\nTexto completo: ");
    for(int i = 0; i < n + n2; i++){
        printf("%c\t", *(p + i));
    }
}