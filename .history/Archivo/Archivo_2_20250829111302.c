/*Escriba un programa que cree un menú de opciones que permita 
a) abrir un archivo, b) escribir un archivo, c) leer un archivo. (Sin utilizar funciones)
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *a; 
    int op = 0;
    char fin = ' ';
    char ch;
    char linea[100];
    do{
        system("clear");
        printf("1)Abrir archivo \n2)Escribir archivo \n2)leer archivo");
        scanf(" %d", &op);

        switch(op){
            case 1: 
            a = fopen("archivo2.txt", "w");
            printf("\nAbriendo archivo. . .");
            if(a == NULL){
                printf("\nError al abrir archivo");
            }else{
                printf("\nArchivo abierto!");
            }
            break;
            case 2:
            printf("\n----------------Modo Escritura----------------\n");
            getchar();
            while((ch = fgetc(stdin)) != EOF){
                if(ch != '$'){
                fputc(ch, a);
                }else{
                    break;
                }
                printf("\aCerrando archivo. . .");
                fclose(a);
            }
            case 3: 
            printf("\nAbriendo archivo para leer");
            a = fopen("archivo2.txt", "r");
            printf("\n-----------------Modo Lectura-----------------\n");
            while(fgets(linea, 100, a) != NULL){
                printf("%s", linea);
            }
            }

        printf("\nDesa continuar? (s/n)");
        scanf(" %c", &fin);
    }while(fin == 's'|| fin == 'S');
}