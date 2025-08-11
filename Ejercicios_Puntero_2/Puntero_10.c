#include <time.h>
#include <stdio.h>
#include <stdlib.h>


float prom (int *);
int main(){
    srand(time(NULL));
    int *num;
    float res = prom(num);
    printf("Numeros cargados: ");
    for(int i = 0; i < 10; i++){
        printf("%d\t", *(num+i));
    }
    printf("\nEl promedio de los numeros cargados es = %.2f", res); 

}

float prom(int *num){
    float aux = 0;
    for(int i = 0; i < 10; i++){
        *(num+i) = rand()%(100+1);
        aux += *(num+i);
    }
    float prom = aux/10;
    return prom;
}

