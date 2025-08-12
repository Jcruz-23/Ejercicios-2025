#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float suma(float*, float*);
float resta(float*, float*);
float mult(float*, float*);
float divi(float*, float*);
float pot (float*, float*);
float raiz(float*, float*);

void menu();

int main(){
 menu();
}

float suma(float *y, float *x){
    return (*y+*x);
}
float resta(float *y, float *x){ return(*y-*x);}
float mult(float *y, float *x){ return(*y * *x);}
float divi(float *y, float *x){ return(*y / *x);}
float pot(float *y, float *x){ float res = (float)pow(*y,*x); return res;}
float raiz(float *y, float *x){ float res = (float)pow (*y, 1.0/ *x); return res;}

void menu(){
int op = 0;
char fin = ' ';
float a, b, res;
do{
system("clear");
printf("Seleccione una opción\n"
"1. Suma\n"
"2. Resta\n"
"3. Multiplicacion\n"
"4. Division\n"
"5. Potencia\n"
"6. Raiz\n");
scanf(" %d", &op);
system("clear");

if(op<=6 && op>=1){
printf("Ingrese primer numero:");
scanf(" %f", &a);
printf("\nIngrese segundo numero: ");
scanf(" %f", &b);
}

switch (op){
case 1: res = suma(&a, &b); break;
case 2: res = resta(&a, &b); break;
case 3: res = mult(&a, &b); break;
case 4: res = divi(&a, &b); break;
case 5: res = pot(&a, &b); break;
case 6: res = raiz(&a, &b); break;
default: printf("\aERROR!\nCerrando programa..."); break;
}
if(op<=6 && op>=1){printf("\nEl resultado es: %.2f\n", res);}


printf("\nDesea continuar? S(si)/N(no)");
scanf(" %c", &fin);
}while(fin == 's'|| fin == 'S');
}