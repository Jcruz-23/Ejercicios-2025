#include <stdio.h>
int a = 0;
int main(){
printf("inserte un numero: ");
scanf("%d",&a);

if(a%2 == 0){
    printf ("%d es par",a);                
}
else {
    printf ("%d es impar",a);
}   
return 0;
}