#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void letrasMayus(int*);
void mostrar(int*);
void letrasMinus(int*);
void menu(int*);

int main(){
    int *abc;
    menu(abc);
}

void letrasMayus(int *abc){
    int letra = 65;
    for(int i = 0; i<27; i++){
        *(abc + i) = letra;
        letra++;
    }
}

void letrasMinus(int *abc){
    int minus = 0;
    for(int i = 0; i<26; i++){
        minus = tolower(*(abc + i));
        *(abc + i) = minus;
    }
}


void mostrar(int *abc){
    for (int i = 0; i<26; i++){
        printf("%c\t", *(abc +i));
    }
}

void menu(int *abc){
    system("clear");
    char fin = ' ';
    int op = 0;
    int aux = 0;
    do{
        printf("--Generador de abecedario--"
        "\n¿Que desea hacer?"
        "\n1- Generar mayusculas"
        "\n2- Generar minusculas"
        "\n3- Generar ambos");
        scanf(" %d", &op);
        
        switch(op){
            case 1:
            letrasMayus(abc);
            mostrar (abc);
            aux = 1;
            break;
            case 2:
            if(aux == 1){
                letrasMinus(abc);
                mostrar(abc);
            }else{
                letrasMayus(abc);
                letrasMinus(abc);
                mostrar(abc);
            }
            break;
            case 3:
            letrasMayus(abc);
            mostrar(abc);
            letrasMinus(abc);
            printf("\n///////////////////////////////////////////\n");
            mostrar(abc);
            default:
            printf("\a\n¡¡ERROR!!");
            break;
        }


        
        printf("\nDesea continuar? S(si)/N(no)");
        scanf(" %c", &fin);
    }while(fin == 's' || fin== 'S');
}