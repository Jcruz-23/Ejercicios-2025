#include <stdio.h>
#include <stdlib.h>

void cargar(int *);
int main(){
    int *saldos;
    cargar(saldos);
}


void cargar(int *saldos){
    int lim = 0;
    int num = 0;
    int *p = num;
    char fin = ' ';
    printf("Cargue los saldos que desea (max. 10 saldos)\n");
    do{
        num++;
        printf("Saldo num %d: ", num);
        scanf(" %d", &*(saldos + lim));
        lim ++;

        printf("\nDesea agregar otro? S/N\n");
        scanf(" %c", &fin);

        if(fin == 'n' || fin == 'N'){lim = 11;}
    }while(lim <= 10);
}