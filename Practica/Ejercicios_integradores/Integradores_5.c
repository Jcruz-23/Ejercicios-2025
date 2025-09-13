/*Desarrolle un programa que permita gestionar los datos de productos en el inventario de una tienda. 
Para ello, defina una estructura llamada Producto que almacene la siguiente información: 
-código de producto (entero).
-nombre del producto (cadena de caracteres).
-cantidad en stock (entero).
-precio unitario (flotante). 
Luego, implemente las siguientes funciones: 
-Que permita registrar un nuevo producto (debe agregar un producto nuevo a la lista).
-Que permita leer un archivo "productos.txt".
-Que permita buscar todos los productos que tienen una cantidad de stock menor a 10. 
-Genere un menú de opciones con las distintas opciones que puede realizar el usuario.
Recuerde presentar la información de manera ordenada y entendible.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct producto{
int codigo;
char nombre[20];
int stock;
float precio;
};

void registrarProducto(struct producto *, int);
void leerArchivo(struct producto *, int);
void productosMenor(struct producto *, int);

int main(){
    int op = 0;
    char fin = ' ';
    int n = 0;//cantidad de productos añadidos
    struct producto *p=NULL;
    //struct producto *aux = NULL;

    p = malloc(100 * sizeof(struct producto));
    if (p == NULL){
                printf("\nError agregando memoria");
                free(p);
                return 1;
            }
    do{
        system("clear");
        printf("===================MENU==================="
            "\n1)Ingresar producto"
            "\n2)Leer archivo"
            "\n3)Buscar productos con stock menor a 10"
            "\n=========================================="
            "\nOpcion: ");
        scanf(" %d", &op);

        switch(op){
            case 1:
            
            registrarProducto(p,n);
            n++;
            break;

            case 2:
            leerArchivo(p,n);
            break;

            case 3: productosMenor(p,n);
            break;

            default: printf("\nError!!"); break;
        }

        printf("\nDesea continuar? (s/n): ");
        scanf(" %c", &fin);
    }while(fin == 's'||fin == 'S');
}

void registrarProducto(struct producto *p, int n){
    (p+n)->codigo = n+1;
    getchar();
    printf("\nNombre: ");
    fgets((p+n)->nombre, sizeof((p+n)->nombre), stdin);
    (p+n)->nombre[strcspn((p+n)->nombre, "\n")] = '\0';
    printf("\nStock: ");
    scanf(" %d", &(p+n)->stock);
    printf("\nPrecio: ");
    scanf(" %f", &(p+n)->precio);

    FILE *f;
    f = fopen("productos.txt", "a");
    fprintf(f,"%d %s %d %f \n", (p+n)->codigo, (p+n)->nombre, (p+n)->stock, (p+n)->precio);
    fclose(f);  
}

void leerArchivo(struct producto *p, int n){
    FILE *f;
    printf("\nAbriendo archivo. . .");
    char linea[200];
    f = fopen("productos.txt", "r");
    n = 0;
    if (f == NULL){
        printf("\nError al leer el archivo!");
        fclose(f);
    }
    printf("\nLeyendo archivo. . .");

    while(fgets(linea, sizeof(linea), f) != NULL){
        if(fscanf(f, "%d %s %d %f", &(p+n)->codigo, (p+n)->nombre, &(p+n)->stock, &(p+n)->precio) == 4){
            n++;  
        }

        for(int i = 0; i < n; i++){
            printf("\n--------------------------------------");
            printf("\nCodigo: %d",(p+i)->codigo);
            printf("\nNombre: %s", (p+i)->nombre);
            printf("\nStock: %d",(p+i)->stock);
            printf("\nPrecio: %.2f",(p+i)->precio);
            printf("\n--------------------------------------");

        }
}
    fclose(f);
}

void productosMenor(struct producto *p, int n){
    int flag = 0;
    printf("\nProductos con stock menor a 10: ");
    for(int i = 0; i < n; i ++){
        if((p+i)->stock<10){
            printf("\n%s", (p+i)->nombre);
            flag = 1;
        }
    }

    if(flag == 0) printf("\nNo se encontraron productos con stock menor a 10");
}

