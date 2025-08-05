#include <stdio.h>

int edad = 0;
int ing = 0;

int main (){
    printf ("ingresar edad \n");
    scanf("%d",&edad);
    printf("ingesar ingreso");
    scanf("%d",&ing);

    
    
    if (edad>=25 && ing>=200000){
        printf("puede tributar");
    }
    else {
        printf("no puede tributar");
    }
    return 0;
}