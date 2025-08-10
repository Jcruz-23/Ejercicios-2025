#include <stdio.h>
void flotante();
void entero();
void character ();


int main(){
flotante();
printf("\n//////////////////////////////////////////////////////////////\n");
entero();
printf("\n//////////////////////////////////////////////////////////////\n");
character();
}

void flotante(){
    float n = 2.5, *p = &n;
    printf("Flotante: %.1f\n", n);
    *p = 3.5;
    printf("Flotante (despues de puntero): %.1f\n", n);
}

void entero(){
    int n = 2, *p = &n;
  printf("Entero: %d\n", n);
    *p = 3;
    printf("Entero (despues de puntero): %d\n", n);
}

void character(){
    char n = 'a', *p = &n;
  printf("Character: %c\n", n);
    *p = 'b';
    printf("Character (despues de puntero): %c\n", n);
}