/*Se desea cargar en un vector los saldos de proveedores. La cantidad de saldos es ingresada por el usuario (máximo 10). 
La carga finaliza con un saldo menor o igual a cero. Además, desarrolle las siguientes funciones para mostrar:
a. Cantidad de saldos cargados.
b. Promedio de saldos.
c. Cantidad de saldos menores al promedio.
d. Cantidad de saldos mayores al promedio.
e. Calcular cuánto fue lo recaudado en el mes.
Cada ítem es una función. Para recorrer el vector utilice punteros.
*/


#include <stdio.h>
#include <stdlib.h>

void menu(int *, int *);
void cargar(int *, int *);
float prom(int *, int *);
int menorProm(int*,int*, float );
int mayorProm(int*,int*, float );
int recaudado(int*, int*);


int main(){
    int *saldos;
    int cont = 0;
    menu(saldos, &cont);
    return 0;
}


void cargar(int *saldos, int *cont){
    int lim = 0;
    char fin = ' ';
    int aux = 0;
    printf("Cargue los saldos que desea (max. 10 saldos)\n");
    do{
        aux++;
        printf("Saldo num %d: ", aux);
        scanf(" %d", &*(saldos + lim));
        lim ++;

        printf("\nDesea agregar otro? S/N\n");
        scanf(" %c", &fin);

        if(fin == 'n' || fin == 'N'){lim = 11;}
    }while(lim < 10);

    *cont = aux;
}


float prom(int *saldos, int *cont){
    float totalSaldos = 0;
    float prom;
    for (int i = 0; i < *cont; i++){
        totalSaldos+=*(saldos+i);
    }

    prom = totalSaldos/ *cont;
    return prom;
}

int menorProm(int *saldos, int *cont, float promedio){
    int menor = 0;
    for(int i = 0; i < *cont; i++){
    if(*(saldos + i) < promedio) menor++;
}
return menor;
}

int mayorProm(int *saldos, int *cont, float promedio){
    int mayor = 0;
for(int i = 0; i < cont; i++){
    if(*(saldos + i)>promedio)mayor++;
}
return mayor;
}

int recaudado(int *saldos, int *cont){
    int total = 0;
    for(int i = 0; i < *cont; i++){
        total += *(saldos + i);
    }

    return total;
}

void menu(int *saldos, int *cont){
    float promedio = 0;
    int mayor = 0;
    int menor = 0;
    int total = 0;
    char fin = ' ';
    char op = ' ';
    int flag1 = 0;
    int flag2 = 0;
    do{
        system("clear");
        printf("\t------- MENU --------"
        "\na) Cargar saldos"
        "\nb) Mostrar promedio de saldos"
        "\nc) Mostrar promedios menores al promedio"
        "\nd) Mostrar promedios mayores al promedio"
        "\ne) Total recaudado del mes"
               "\n\t---------------------\n");
               scanf(" %c", &op);
               switch(op){
                case 'a':
                if (flag1 == 0){
                    cargar(saldos, &cont);
                    flag1 = 1;
                }else{
                    printf("\nSaldos ya cargados");
                }
                
                break;
                case 'b':
                if (flag1 == 1){
                promedio = prom(saldos, &cont);
                printf("\nPromedio de saldos: %.2f", promedio);
                flag2 = 1;
                }else{
                    printf("\n\aSaldos sin cargar");
                }
                break;
                case 'c': 
                if(flag2 == 1){
                menor = menorProm(saldos, &cont, promedio);
                printf("\nCantidad de saldos menores al promedio: %d", menor);
                }else{
                    printf("\nPromedio no generado");
                }
                break;
                case 'd':
                if(flag2 == 1){  mayor = menorProm(saldos, &cont, promedio);
                printf("\nCantidad de saldos mayores al promedio: %d", mayor);
                }else{
                    printf("\nPromedio no generado");
                }
                break;
                case 'e':
                total = recaudado(saldos, &cont);
                printf("\nTotal recaudado: %d", total);
                break;
                default:
                printf("\n\aERROR!!");
               }
        printf("\nDesea continuar? S/N");
        scanf(" %c", &fin);
    }while(fin == 's'|| fin == 'S');
}