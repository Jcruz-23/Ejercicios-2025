#include <stdio.h>
#include <stdlib.h>

struct producto{
char nombre[20];
char marca[20];
int precio;
float fecha;
int tamaño;
};
int cargar(struct producto *p, int);
int agregar(struct producto *p, int);

int main(){
    struct producto *p;
    struct producto *p2;
    int n = 1;
    int flag = 0;
    char fin = ' ';

    do{
        if(flag == 0){
            p = malloc(1 * sizeof(struct producto));
            if(p == NULL){
                printf("\nError asignando memoria");
                free(p);
                return 1;
            }
            n = cargar(p, n);
        }else{
            p2 = realloc(p, (n+1) * sizeof(struct producto));
            p = p2;
            if(p2 == NULL){
                printf("\nError asignando memoria");
                free(p);
                return 1;
            }
            n = agregar(p, n);
            
            printf("\nDesea agregar otro producto? (s/n)");
            scanf(" %c", &fin);
        }
    }while(fin == 's'|| fin == 'S');

    free(p);
    return 0;
}
int cargar(struct producto *p, int n){
    FILE *a;
    a = fopen("producto.txt", "w");
    printf("------------PRODUCTO[%d]------------", n);
    printf("\nNombre: ");
    scanf(" %s", p[n].nombre);
    printf("\nMarca: ");
    scanf(" %s", p[n].marca);
    printf("\nPrecio: ");
    scanf(" %d", &p[n].precio);
    printf("Fecha(dia.mes): ");
    scanf(" %f", &p[n].fecha);
    printf("\nTamaño: ");
    scanf(" %d", &p[n].tamaño);
    fprintf(a,"------------PRODUCTO[%d]------------", n);
    fprintf(a,"\nNombre: %s", p[n].nombre);
    fprintf(a,"\nMarca: %s", p[n].marca);
    fprintf(a,"\nPrecio: %d", p[n].precio);
    fprintf(a,"Fecha(dia.mes): %.4f", p[n].fecha);
    fprintf(a,"\nTamaño: %d", p[n].tamaño);
    n++;
    fclose(a);
}

agregar(struct producto *p, int n){
    FILE *a;
    a = fopen("producto.txt", "a");
    printf("------------PRODUCTO[%d]------------", n);
    printf("\nNombre: ");
    scanf(" %s", p[n].nombre);
    printf("\nMarca: ");
    scanf(" %s", p[n].marca);
    printf("\nPrecio: ");
    scanf(" %d", &p[n].precio);
    printf("Fecha(dia.mes): ");
    scanf(" %f", &p[n].fecha);
    printf("\nTamaño: ");
    scanf(" %d", &p[n].tamaño);
    fprintf(a,"------------PRODUCTO[%d]------------", n);
    fprintf(a,"\nNombre: %s", p[n].nombre);
    fprintf(a,"\nMarca: %s", p[n].marca);
    fprintf(a,"\nPrecio: %d", p[n].precio);
    fprintf(a,"Fecha(dia.mes): %.4f", p[n].fecha);
    fprintf(a,"\nTamaño: %d", p[n].tamaño);
    n++;
    fclose(a);
}