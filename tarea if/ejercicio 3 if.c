#include <stdio.h>
int a = 0;
int b = 0;
int c = 0;
int r = 0;

int main(){
printf ("insertar primer numero: ");
scanf("%d", &a);
printf("insertar segundo numero: ");
scanf("%d",&b);

c = a/b;
r = a%b;



printf ("la division es = %d \n",c);
if(r!=0){
printf("la division no es exacta \n el resto es = %d", r);
}
else {
printf("la division es exacta");
}
}