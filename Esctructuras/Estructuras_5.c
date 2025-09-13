/*Crear una estructura llamada persona con sus atributos nombre, apellido, fecha de nacimiento, dirección y teléfono. 
Tanto la dirección como la fecha de nacimiento son otras estructuras (estructura anidada). Cargue con datos y luego muéstrelos.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct fecha{
    int dia;
    int mes; 
};
struct direccion{
    char localidad[20];
    char barrio[20];
    int numeroCasa;
};
struct contacto{
    char nombre[20];
    char apellido[20];
    struct fecha fecha;
    struct direccion direccion; 
    int numero;
};


void menu();
int ingresar(struct contacto *c, int);
void mostrar(struct contacto *c, int);
int main(){
    menu();
}

void menu(){
    int op = 0;
    char fin = ' ';
    int n = 0;
    int flag = 0;
    struct contacto *c = NULL;
    struct contacto *aux = NULL;

    do{
        printf("===================MENU==================="
               "\n1)Ingresar contacto"
               "\n2)Mostrar contactos"
               "\n=========================================="
               "\nOpcion: ");
        scanf(" %d", &op);

        switch(op){
            case 1: 
            if(flag == 0){
                c = malloc(1*sizeof(struct contacto));
                if(c == NULL){
                    printf("\nError al asignar memoria");
                }else{
                    n = ingresar(c, n);
                    flag = 1;
                }
            }else{
                aux = realloc(c, (n+1) * sizeof(struct contacto));
                if(aux == NULL){
                    printf("\nError al agregar memoria");
                    free(c);
                }else{
                    c = aux; 
                    n = ingresar(c, n);
                }
            }
            break;

            case 2:
            if(flag == 1){
                mostrar(c, n);
            }else{
                printf("\nNo tiene contactos");
            }
            break;

            default: printf("\nERROR");
        }
        printf("\nDesea continuar?(s/n): ");
        scanf(" %c", &fin);
    }while(fin == 's'||fin == 'S');

    free(c);

    return 0;
}


int ingresar(struct contacto *c, int n){
    printf("\nNumero: ");
    scanf(" %d", &(c+n)->numero);
    getchar();
    printf("\nNombre: ");
    fgets((c+n)->nombre, sizeof((c+n)->nombre), stdin);
    printf("\nApellido: ");
    fgets((c+n)->apellido, sizeof((c+n)->apellido), stdin);
    printf("\n-Fecha de nacimiento-");
    printf("\nMes: ");
    scanf(" %d", &(c+n)->fecha.mes);
    printf("\nDia: ");
    scanf(" %d", &(c+n)->fecha.dia);
    printf("\n");
    printf("\n------Domicilio------");
    printf("\nLocalidad: ");
    getchar();
    fgets((c+n)->direccion.localidad, sizeof((c+n)->direccion.localidad), stdin);
    printf("\nBarrio: ");
    fgets((c+n)->direccion.barrio, sizeof((c+n)->direccion.barrio), stdin);
    printf("\nNumero de casa: ");
    scanf(" %d", &(c+n)->direccion.numeroCasa);
    printf("\n---------------------");

    n++;
    return n;

}

void mostrar(struct contacto *c, int n){
    for(int i = 0; i < n; i++){
    printf("\n--------------------------------------------------------");
    printf("\nNumero: %d", (c+i)->numero);
    printf("\nNombre completo: %s %s", (c+i)->nombre, (c+i)->apellido);
    printf("\nCumpleaños: %d/%d", (c+i)->fecha.dia, (c+i)->fecha.mes);
    printf("\nLocalidad: %s", (c+i)->direccion.localidad);
    printf("\nBrrio: %s",(c+i)->direccion.barrio);
    printf("\nNumero de casa: %d", (c+i)->direccion.numeroCasa);
    }
}