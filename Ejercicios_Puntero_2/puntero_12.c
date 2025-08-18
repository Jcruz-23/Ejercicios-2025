#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar(int*);
void mayor(int*);
void menor(int*);
void sumatoria(int*);
void menu(int*);

int main(){
    int v[5] = {0};
    int *p = &v;
    srand(time(NULL));

    menu(p);

    return 0;
}

void cargar(int *p){
    int num = 0;
    for(int i = 0; i < 5; i++){
        num = rand()%100+1;
        *(p + i) = num;
    }

    printf("\nNumeros cargados: ");
    for(int i = 0; i < 5; i++){
        printf("%d\t", *(p + i));
    }
}

void mayor (int *p){
    int mayor = *p;
    for(int i = 0; i < 5 - 1; i++){
        if(mayor < (*(p + i + 1))) mayor = *(p + i + 1);
    }

    printf("\nEl num. mas grande es: %d", mayor);
}

void menor (int *p){
    int menor = *p;
    for(int i = 0; i < 5 - 1; i++){
        if(menor > (*(p + i + 1))) menor = *(p + i + 1);
    }

    printf("\nEl num. mas chico es: %d", menor);
}

void sumatoria(int *p){
    int total = 0;
    for(int i = 0; i < 5; i++){
        total += *(p + i);
    }

    printf("\nLa sumatoria total es: %d", total);
}

void menu (int *p){
    char fin = ' '; 
    int op = 0;
    char carga = 0;
    int flag1 = 0;
    do{
        printf(" ----------MENU----------"
        "\n1-Cargar Vector"
        "\n2-Mostrar valor mas grande"
        "\n3-Mostrar valor mas chico"
        "\n4-Mostrar sumatoria total"
        "\n ------------------------");
        printf("\nElija una opcion: ");
        scanf(" %d", &op);

        switch(op){
            case 1: 
            if (flag1 == 1){
                printf("\nVector ya cargado! desea cargarlo de vuelta? S/N");
                scanf(" %c", &carga);
                if(carga == 's'|| carga == 'S'){
                    printf("\nCargando vector...");
                    cargar(p);
                }
            }else{
                printf("\nCargando vector...");
                cargar(p);
                flag1 = 1;
            }
            break;
            case 2: 
            if(flag1 == 1) mayor(p);
            else printf("\n\aVector sin cargar!");
            break;
            case 3: 
            if (flag1 == 1) menor(p);
            else printf("\n\aVector sin cargar!");
            break;
            case 4: 
            if(flag1 == 1) sumatoria(p);
            else printf("\n\aVector sin cargar!");
            break;
            default: printf("\n\aERROR!"); break;
        }

        printf("\nDesea continuar? S/N: ");
        scanf(" %c", &fin);
    }while(fin == 's'|| fin == 'S');
}