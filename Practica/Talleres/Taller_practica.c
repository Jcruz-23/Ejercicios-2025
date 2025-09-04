/*Desarrolle un programa que permita gestionar los datos de clientes en un banco. Para ello, defina una estructura llamada
ClienteBanco que almacene la siguiente información: número de cliente (entero), nombre (cadena de caracteres),
saldo en cuenta (flotante) y tipo de cuenta (cadena de caracteres). El tipo de cuenta puede ser Cuenta Corriente y Caja de Ahorros.

Implemente las siguientes funciones:

Que permita registrar un nuevo cliente del banco.
Que permita guardar sus datos en un archivo "clientes.txt". Cada línea del archivo debe contener la información de un cliente.
Que permita mostrar los clientes que tienen saldos negativos.
Genere un menú de opciones con las distintas opciones que puede realizar el usuario, que se repita hasta que el usuario desea salir. Recuerde presentar la información de manera ordenada y entendible.

Utilice punteros, memoria dinamica,estructura y archivo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct clienteBanco
{
    int numero;
    char nombre[20];
    float saldo;
    char cuenta[20];
};
int registrar(struct clienteBanco *c, int);
void mostrar(struct clienteBanco *c, int);
void mostrarNegativo(struct clienteBanco *c, int);
void menu();
void archivoBanco(struct clienteBanco *c, int);

int main()
{
    menu();
}

void menu()
{
    int op = 0;
    char fin = ' ';
    int n = 0;
    struct clienteBanco *c = NULL;
    struct clienteBanco *aux = NULL;
    int flag = 0;
    do
    {
        system("clear");

        printf("-----------------------Menu-----------------------"
               "\n1)Registrar nuevo cliente"
               "\n2)Guardar datos en archivo"
               "\n3)Mostrar clientes"
               "\n4)Mostrar clientes en negativo"
               "\n--------------------------------------------------"
               "\nOpcion: ");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            if (flag == 0)
            {
                c = malloc(1 * sizeof(struct clienteBanco));
                if (c == NULL)
                {
                    printf("\nError al asignar memoria");
                }else{
                    n = registrar(c, n);
                }
                flag = 1;
            }
            else
            {
                aux = realloc(c, (n + 1) * sizeof(struct clienteBanco));
                if (aux == NULL)
                {
                    printf("\nError al aumentar memoria");
                    free(c);
                }
                else
                {
                    c = aux;
                    n = registrar(c, n);
                }
            }
            break;
        case 2:
        if(flag == 0){
            printf("\nNo hay clientes");
        }else{
            archivoBanco(c, n);
        }
            break;

        case 3:
        if(flag == 0){
            printf("\nNo hay clientes");
        }else{
            mostrar(c, n);
        }
            break;
        case 4:
        if(flag == 0){
            printf("\nNo hay clientes");
        }else{
            mostrarNegativo(c, n);
        }
            break;
        default:
            printf("\nERROR!!");
            break;
        }

        printf("\nDesea continuar?(s/n)");
        scanf(" %c", &fin);
    } while (fin == 's' || fin == 'S');
    free(c);
}

int registrar(struct clienteBanco *c, int n)
{
    printf("\n----------------------------cliente[%d]----------------------------", n + 1);
    printf("\nNombre: ");
    getchar();
    fgets((c + n)->nombre, sizeof((c + n)->nombre), stdin);
    printf("Saldo: ");
    scanf(" %f", &(c + n)->saldo);
    printf("Cuenta(corriente o de ahorro): ");
    getchar();
    fgets((c + n)->cuenta, sizeof((c + n)->cuenta), stdin);

    (c + n)->numero = n + 1;

    n++;
    return n;
}

void mostrar(struct clienteBanco *c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n-----------------------Cliente[%d]-----------------------", (c + i)->numero);
        printf("\nNombre: %s", (c + i)->nombre);
        printf("Saldo: %f", (c + i)->saldo);
        printf("\nCuenta: %s", (c + i)->cuenta);
    }
}

void mostrarNegativo(struct clienteBanco *c, int n)
{
    int negativos = 0;
    for (int i = 0; i < n; i++)
    {
        if ((c + i)->saldo < 0)
        {
            negativos++;
            printf("\n-----------------------Cliente[%d]-----------------------", (c + i)->numero);
            printf("\nNombre: %s", (c + i)->nombre);
            printf("Saldo: %f", (c + i)->saldo);
            printf("\nCuenta: %s", (c + i)->cuenta);
        }
    }
    if(negativos == 0) printf("\nNo hay clientes en negativos");
}

void archivoBanco(struct clienteBanco *c, int n)
{
    FILE *f;
    f = fopen("clientes.txt", "w");

    printf("\nAñadiento al archivo. . .");
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "\n-----------------------Cliente[%d]-----------------------", (c + i)->numero);
        fprintf(f, "\nNombre: %s", (c + i)->nombre);
        fprintf(f, "Saldo: %f", (c + i)->saldo);
        fprintf(f, "\nCuenta: %s", (c + i)->cuenta);
    }

    printf("\nArchivo completado!");
    fclose(f);
}