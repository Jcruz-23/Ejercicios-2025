/*Desarrolle un programa que permita gestionar los datos de clientes en un banco. Para ello, defina una estructura 
llamada Movimientos que almacene la siguiente información: número de cliente (entero), movimiento (flotante), 
saldo en cuenta (flotante) y tipo de cuenta (cadena de caracteres). 
El tipo de cuenta puede ser Cuenta Corriente y Caja de Ahorros. 
Cuando el cliente realiza un gasto el movimiento es negativo y cuando el cliente recibe dinero es positivo. 
Implemente las siguientes funciones: 
-Que permita registrar un nuevo movimiento de un cliente y actualizar el saldo de la cuenta.
-Que permita guardar sus datos en un archivo "movimientos.txt". 
Cada línea del archivo debe contener la información de un movimiento de un cliente.
-Que permita mostrar los movimientos de un cliente en particular.
Genere un menú de opciones con las distintas opciones que puede realizar el usuario. 
Recuerde presentar la información de manera ordenada y entendible.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct movimiento{
    int numero;
    float movimiento;
    float saldo;
    char cuenta[15];
};


int registrar(struct movimiento *, int );
void mostrar(struct movimiento *, int );
void guardar(struct movimiento *, int );
void movimiento(struct movimiento *, int);


int main(){
int op = 0;
char fin = ' ';
int n = 0;
//int n2 = 0;
struct movimiento *p = NULL;
struct movimiento *p2 = NULL;

do{
        printf("\n===================MENU==================="
            "\n1)Registrar cuenta"
            "\n2)Realizar movimiento"
            "\n3)Guardar en archivo"
            "\n4)Mostrar movimientos"
            "\n=========================================="
            "\nOpcion: ");
        scanf(" %d", &op);

        switch(op){
            case 1: p2 = realloc(p, (n+1) * sizeof(struct movimiento));
            if(p2 == NULL){
                printf("\nError añadiendo memoria");
                free(p);
                return 0;
            }
            p = p2;
            n = registrar(p, n);
            break;

            case 2: movimiento(p,n); break;

            case 3: guardar(p, n); break;

            case 4: mostrar(p, n); break;

            default: printf("\nOpcion incorrecta!");
        }
        printf("\nDesea continuar? (s/n)");
        scanf(" %c", &fin);
    }while(fin == 's'||fin == 'S');

    free(p);
    p = NULL;
}

int registrar(struct movimiento *p, int n){
    printf("\nCuenta N°%d", n+1);
    (p+n)->numero = n+1;
    printf("\nSaldo:" );
    scanf(" %f", &(p+n)->saldo);
    getchar();
    printf("\nCuenta(ahorro o corriente): ");
    fgets((p+n)->cuenta,sizeof((p+n)->cuenta), stdin);
    n++;
    return n;
}

void movimiento(struct movimiento *p, int n){
    int num;
    int op;
    printf("\nIngrese numero de cuenta: ");
    scanf(" %d", &num);

    for(int i = 0; i < n; i++){
        if(num == (p+i)->numero){
            printf("\nQue desea hacer?"
            "\n1)Ingresar dinero"
            "\n2)Sacar dinero"
            "\nOpcion: ");
            scanf(" %d", &op);

            switch(op){
                case 1: 
                printf("\nCantidad a ingresar: ");
                scanf(" %f", &(p+i)->movimiento);
                (p+i)->saldo += (p+i)->movimiento;
                break;
                case 2: 
                printf("\nCantidad a sacar: ");
                scanf(" %f", &(p+i)->movimiento);
                (p+i)->movimiento = (p+i)->movimiento * (-1);
                (p+i)->saldo += (p+i)->movimiento;
                break;
                default: printf("\nOpcion incorrecta"); break;
            }
        }else{
            printf("\nCuenta no encontrada!");
        }
    }
}

void guardar(struct movimiento *p, int n){
    FILE *f;
    printf("\nCargando archivo. . .");
    f = fopen("movimiento.txt", "w");
    if(f == NULL){
        printf("\nError al abrir archivo!");
    }
    for(int i = 0; i < n; i++){
        fprintf(f,"%d|%.3f", (p+i)->numero, (p+i)->movimiento);
    }
    fclose(f);

    printf("\nArchivo cargado!");

}

void mostrar(struct movimiento *p, int n){
    for(int i = 0; i < n; i++){
        printf("\nCuenta n°%d", (p+i)->numero);
        printf("\nSaldo: %.3f", (p+i)->saldo);
        printf("\nTipo de cuenta: %s", (p+i)->cuenta);
        printf("Movimiento: %.3f", (p+i)->movimiento);
    }
}

