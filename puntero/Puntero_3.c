#include <stdio.h>

int resta();
int restaPunteros();
int main(){
    int restaUno = resta();
    printf("\n//////////////////////////////////////////\n");
    int restaDos = restaPunteros();
    printf("\n//////////////////////////////////////////\n");
    printf("Resta de 'a' y 'b': %d\n", restaUno);
    printf("Resta de 'c' y 'd': %d", restaDos);


}

int resta(){
    int a, b;
    printf("Incerte valor de 'a':");
    scanf(" %d", &a);
    printf("\nIncerte valor de 'b':");
    scanf(" %d", &b);

    return a-b;
}

int restaPunteros(){
    int c, d, *p = &c, *q = &d;

    printf("Incerte valor de 'c':");
    scanf(" %d", &c);
    printf("\nIncerte valor de 'd':");
    scanf(" %d", &d);

    return *p-*q;
}
