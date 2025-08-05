#include <stdio.h>
int a = 0;
int b = 0;

int main(){
    printf("incerte primer numero: ");
    scanf("%d",&a);
    printf("incerte segundo numero: ");
    scanf("%d", &b);

    
    if(a>b){
        printf("%d es mayor",a);
        printf("%d es menor\n",b);

    }
    else{
        printf("%d es mayor",b);
        printf("%d es menor\n",a);

    }
    return 0;
}