#include <stdio.h> 
#include <stdlib.h>


float sumaArreglo(float*, int);

int main(){
int tam = 5;
float res = 0;
float num[5] = {4.5, 8, 2.3, 1.1, 3};
float *punt = num;
res = sumaArreglo(punt, tam);
printf("El resultado es = %.2f\n\n", res);

return 0;
}
float sumaArreglo(float *suma, int tam){
    float res = 0;
    for(int i = 0; i < tam; i++){
        res += *(suma + i);
    }

    return res;
}