/*Crear un programa que pida los siguientes datos de una canción: Artista, Título, Duración (en segundos),Tamaño del archivo (en KB). 
Crear una estructura que almacene datos de la canción y luego los muestre por pantalla.

Nota: para leer una cadena de caracteres usar fgets(vector_char, sizeof(vector_char), stdin);
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
struct cancion{
        char nombre[20];
        float duracion;
        int peso;
    };

int main(){
    struct cancion c;
    srand(time(NULL));
    int kb = rand()%(3000-100+1)+1000;
    printf("Ingrese nombre de la canción: ");
    fgets(c.nombre, sizeof(c.nombre), stdin);
    c.nombre[strcspn(c.nombre, "\n")] = '\0';

    printf("\nIngrese duracion (min.seg): ");
    scanf(" %f", &c.duracion);
    c.peso = kb;
  

    printf("\n-------------------------------------");
    printf("\nCancion: %s", c.nombre);
    printf("\nDuracion: %.2f", c.duracion);
    printf("\nPeso de la cancion: %d kbytes", c.peso);
    printf("\n-------------------------------------");
    printf("\n");
}