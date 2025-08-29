/*Ampliar el programa del ejercicio anterior, para que almacene datos de hasta 3 canciones en un vector de estructura. 
Luego crear un menú que permita las opciones: 
agregar una nueva canción
mostrar todas las canciones
buscar una canción por título

Nota: Para comparar dos string utilizar la función cadena1.compare(cadena2) de la librería string. Por ejemplo: if(cadena1.compare(cadena2)==0) 
si es 0 (cero) significa que son iguales los string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

struct cancion{
    char nombre[20];
    float duración;
    int peso;
};
int agregar(struct cancion *c, int);
void menu();
void mostrar(struct cancion *c, int);
void buscar(struct cancion *c, int);
void mayus(char *);

int main(){
    struct cancion *c = NULL;
    srand(time(NULL));
    c = malloc(3*sizeof(struct cancion));

    if(c == NULL){
        printf("\aError asignando memoria");
    }
   menu(c);
   free(c);

}


void menu(struct cancion *c){
 int n = 0;
 int op;
 char fin = ' ';

    do{
        system("clear");
        printf("\n1-Agregar cancion\n2-mostrar canciones\n3-Buscar cancion\nOpcion: ");
        scanf(" %d", &op);

        switch(op){
            case 1: n = agregar(c, n); break;
            case 2: mostrar(c, n); break;
            case 3: buscar(c, n); break;
            default: printf("\n\aERROR!!"); break;
        }

        printf("\nDesea continuar? (s/n): ");
        scanf(" %c", &fin);
    }while(fin == 's'|| fin == 'S');
}
int agregar(struct cancion *c, int n){
    if(n < 3){
        printf("\n------------Cancion[%d]------------", n+1);
        printf("\nNombre: ");
        getchar();
        fgets(c[n].nombre, sizeof(c[n].nombre), stdin);
        c[n].nombre[strcspn(c[n].nombre, "\n")] = '\0';
        mayus(c[n].nombre);
        printf("\nDuracion(min.seg): ");
        scanf(" %f", &c[n].duración);
        printf("\nAgregando. . .");
        c[n].peso = rand()%(3000-1000+1)+1000;
        n++;
    }else{
        printf("\n\aMemoria llena!");
    }
    return n;
}

void mostrar(struct cancion *c, int n){
    printf("\na");
    for(int i = 0; i < n; i++){
        printf("\n------------Cancion[%d]------------", i+1);
        printf("\nNombre: %s", c[i].nombre);
        printf("\nDuracion: %.2f", c[i].duración);
        printf("\nPeso: %d kb", c[i].peso);
    }
}

void buscar(struct cancion *c, int n){
char aux[20];
printf("\nBuscar cancion: ");
getchar();
fgets(aux, sizeof(aux), stdin);
aux[strcspn(aux, "\n")] = '\0';
mayus(aux);

for(int i = 0; i < n; i++){
    if(strcmp(aux, c[i].nombre) == 0){
            printf("\n------------Cancion[%d]------------", i+1);
            printf("\nNombre: %s", c[i].nombre);
            printf("\nDuracion: %.2f", c[i].duración);
            printf("\nPeso: %d kb", c[i].peso);
        }else{
            printf("\nCancion no encontrada");
       }
    }
}

void mayus(char *nombre){
    int cant = sizeof(nombre);
    for(int i = 0; i < cant; i++){
        *(nombre + i) = toupper(*(nombre + i));
    }
}