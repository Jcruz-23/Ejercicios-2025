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

struct cancion{
    char nombre[20];
    int duración;
    int peso;
};

int main(){
    struct cancion *canciones;
    canciones = malloc(3*sizeof(struct cancion));

    if(canciones == NULL){
        printf("Error al asignar memoria");
        return 1;
    }

    for(int i = 0; i < 3; i++){
        printf("Ingrese datos de la cancion[%d]: ", i+1);
        printf("\nNombre: ");
        fgets(canciones[i].nombre,sizeof(canciones[i].nombre),stdin);
        canciones[i].nombre[strcspn(canciones[i].nombre, "\n")] = '\0';
    }

    free(canciones);
}