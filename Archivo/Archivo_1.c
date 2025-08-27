#include <stdio.h>

int main(){
FILE *fp;
int ch;

fp = fopen("diario.txt","w");
printf("Abriendo diario. . .");
if(fp == NULL){
    printf("\aError creando archivo!!");
    return 1;
}
printf("\n-------------------DIARIO-------------------\n");
while((ch = fgetc(stdin)) != EOF){
    if(ch != '$'){
        fputc(ch, fp);
    }else{
        break;
    }
}
printf("\nCerrando diario. . .");
fclose(fp);
}