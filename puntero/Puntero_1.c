#include <stdio.h>
#include <stdlib.h>

int main(){
  int a = 5, *i = &a;
  float b = 6.5, *f = &b;
  char c= 'c', *character = &c;

  //entero
  printf("Direccion de memoria de a: %p", &a);
  printf("\nValor que almacena a: %d", a);
  printf("\nValor del puntero i: %p", i);
  printf("\nValor al que apunta el puntero i: %d", *i);
  //flotante
  printf("\n///////////////////////////////////////////////////////////");
  printf("\nDireccion de memoria de b: %p", &b);
  printf("\nValor que almacena b: %.1f", b);
  printf("\nValor del puntero f: %p", f);
  printf("\nValor al que apunta el puntero f: %.1f", *f);
  //character
  printf("\n///////////////////////////////////////////////////////////");
  printf("\nDireccion de memoria de c: %p", &c);
  printf("\nValor que almacena b: %c", c);
  printf("\nValor del puntero f: %p", character);
  printf("\nValor al que apunta el puntero f: %d", *character);

}