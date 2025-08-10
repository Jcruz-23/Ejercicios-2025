#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void posPares(int *);
void posImpares(int *);

int main(){
    int *pos;
    printf("Ingrese 10 valores del vector: ");
    for(int i = 0; i < 10; i++){
        scanf(" %d", &*(pos + i));
    }
    posPares(pos);
    printf("\n///////////////////////////////////////////\n");
    posImpares(pos);
    return 0;
}


void posPares(int *pos){
    for (int i = 0; i < 10; i++){
        printf("pos %d: %d\t", i, *(pos+i));
        i+=1;
    }
}
void posImpares(int *pos){
    for (int i = 1; i < 10; i++){
        printf("pos %d: %d\t",i, *(pos+i));
        i+=1;
    }
}
