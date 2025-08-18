#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void mostrar(int*);

int main(){
    int p[26] = {0};
    int *abc = &p;
    int minus = 0;
    int letra = 65;
    for(int i = 0; i<26; i++){
        *(abc + i) = letra;
        letra++;
    }
    printf("Letras mayusculas: ");
    mostrar(abc);

    printf("\n\n");

    for(int i = 0; i<26; i++){
        minus = tolower(*(abc + i));
        *(abc + i) = minus;
    }
    
    printf("\nLetras minusculas: ");
    mostrar(abc);
}

void mostrar(int *abc){
    for (int i = 0; i<26; i++){
        printf("%c\t", *(abc +i));
    }
}