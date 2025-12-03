#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int cod;
    float m2;
    float m2_cubiertos;
    float precio;
    char operacion[15];
    char ubicacion[30];
    char estado[10];
} propiedad;

typedef struct nodo {
    propiedad datos;
    struct nodo* sig;
} Nodo;

void registrarPropiedad(Nodo**, Nodo**);
void encolar(Nodo**, Nodo**, propiedad);
void mostrar(Nodo*);
void borrar(Nodo**);
void mostrarTipo(Nodo*);
void cantOcupadasDesocupadas(Nodo*);
void menu();
void Liberar(Nodo**);

int main() {
    srand(time(NULL));
    menu();
    return 0;
}

void menu() {
    Nodo* frente = NULL;
    Nodo* final = NULL;
    char fin = 's';
    int op = 0;

    do {
        system("clear");
        printf("====================MENU===================="
               "\n1) Registrar propiedad"
               "\n2) Mostrar y archivar propiedades"
               "\n3) Borrar propiedad (por codigo)"
               "\n4) Mostrar por tipo de operacion"
               "\n5) Cant. propiedades ocupadas/desocupadas"
               "\n6) Salir"
               "\n============================================"
               "\nOpcion:");
        scanf(" %d", &op);

        switch (op) {
            case 1:
                registrarPropiedad(&frente, &final);
                break;
            case 2:
                if (frente)
                    mostrar(frente);
                else
                    printf("\nNo se registraron propiedades");
                break;
            case 3:
                if (frente)
                    borrar(&frente);
                else
                    printf("\nNo se registraron propiedades");
                break;
            case 4:
                if (frente)
                    mostrarTipo(frente);
                else
                    printf("\nNo se registraron propiedades");
                break;
            case 5:
                if (frente)
                    cantOcupadasDesocupadas(frente);
                else
                    printf("\nNo se registraron propiedades");
                break;
            case 6:
                fin = 'n';
                break;
            default:
                printf("\nError!!");
                break;
        }

        if (fin == 's') {
            getchar();
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n');
        }

    } while (fin == 's');
    Liberar(&frente);
}

void registrarPropiedad(Nodo** frente, Nodo** final) {
    int estado = 0;
    int operacion = 0;
    propiedad prop;
    printf("\n---------Ingresar datos---------");
    printf("\nCod: %d", prop.cod = rand()%100+1); 
    printf("\nm2: "); scanf(" %f", &prop.m2);
    printf("\nm2 cubiertos: "); scanf(" %f", &prop.m2_cubiertos);
    printf("\nprecio: "); scanf(" %f", prop.precio);
    printf("Estado(1-Ocupado||2-desocupado): "); scanf(" %d", &estado);
    switch(estado){
        case 1: strcpy(prop.estado, "ocupado");  break;
        case 2: strcpy(prop.estado, "desocupado" ); break;
        default: printf("\nOpcion no valida!"); return;
    }
    printf("\nOperacion(1-venta||2-alquiler): ");  scanf(" %d", &operacion);
    switch(operacion){
       case 1: strcpy(prop.operacion, "venta");  break;
       case 2: strcpy(prop.operacion, "alquiler" ); break;
       default: printf("\nOpcion no valida!"); return;
    }
    printf("\nUbicacion: ");
    fgets(prop.ubicacion,sizeof(prop.ubicacion),stdin);
    prop.ubicacion[strcspn(prop.ubicacion,"\n")]='\0';
    encolar(frente,final,prop);
    getchar();
}

void encolar(Nodo** frente, Nodo** final, propiedad datos) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->datos = datos;
    nuevo->sig = NULL;

    if(*frente == NULL){
        *frente = nuevo;
        *final = nuevo;
    }else{
        (*final)->sig = nuevo;
        *final = nuevo;
    }
}

void mostrar(Nodo* frente){
    FILE* a = NULL;
    Nodo* aux = frente;

    a = fopen("propiedad.txt", "w");
    printf("\n%-3s | %-15s | %-15s | %-15s | %-15s | %-30s | %-10s", "cod", "m2", "m2 cubiertos", "precio", "operacion", "ubicacion", "estado");
    fprintf(a,"\n%-3s | %-15s | %-15s | %-15s | %-15s | %-30s | %-10s", "cod", "m2", "m2 cubiertos", "precio", "operacion", "ubicacion", "estado");
    while(aux != NULL){
        printf( "\n%-3d | %-15.2f | %-15.2f | %-15.2f | %-15s | %-30s | %-10s", 
                aux->datos.cod, aux->datos.m2, aux->datos.m2_cubiertos, aux->datos.precio, aux->datos.operacion, aux->datos.ubicacion, aux->datos.estado);
        fprintf(a, "\n%-3d | %-15.2f | %-15.2f | %-15.2f | %-15s | %-30s | %-10s", 
                aux->datos.cod, aux->datos.m2, aux->datos.m2_cubiertos, aux->datos.precio, aux->datos.operacion, aux->datos.ubicacion, aux->datos.estado);
        aux = aux->sig;
    }
    fclose(a);
}

void cantOcupadasDesocupadas(Nodo* frente) {
    Nodo* aux = frente;
    int cont_ocupadas = 0;
    int cont_desocupadas = 0;
    while(aux != NULL){
        if(strcmp(aux->datos.estado, "ocupado") != 0) cont_ocupadas++;
        else cont_desocupadas++;
        aux = aux->sig;
    }
    printf("\nOcupadas: %d", cont_ocupadas);
    printf("\nDesocupadas: %d", cont_desocupadas);
}
void mostrarTipo(Nodo* frente) {
    Nodo* aux = frente;
    while(aux != NULL && strcmp(aux->datos.operacion, "alquiler") != 0){
        printf( "\n%-3d | %-15.2f | %-15.2f | %-15.2f | %-15s| %-30s | %-10s", 
                aux->datos.cod, aux->datos.m2, aux->datos.m2_cubiertos, aux->datos.precio, aux->datos.operacion, aux->datos.ubicacion, aux->datos.estado);
        aux = aux->sig;
    }

    aux = frente;

    while(aux != NULL && strcmp(aux->datos.operacion, "venta") != 0){
        printf( "\n%-3d | %-15.2f | %-15.2f | %-15.2f | %-15s | %-30s | %-10s", 
                aux->datos.cod, aux->datos.m2, aux->datos.m2_cubiertos, aux->datos.precio, aux->datos.operacion, aux->datos.ubicacion, aux->datos.estado);
        aux = aux->sig;
    }
}
void borrar(Nodo** frente) {}
void Liberar(Nodo** Lista) {
    Nodo *aux = *Lista;
    while (aux != NULL) {
        aux = (*Lista)->sig;
        free(*Lista);
        *Lista = aux;
    }
}
