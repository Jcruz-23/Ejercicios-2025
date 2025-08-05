#include <stdio.h>
/*el banco de la ciudad ha decidido aumentar el límite de crédito de las tarjetas de 
crédito de sus clientes, para esto considera que si su cliente tiene tarjeta tipo 1,
el aumento será de 25 %; si tiene tipo 2, será de 35 %; si tiene tipo 3, de 40 %, y 
para cualquier otro tipo, de 50 %. Realice un algoritmo para determinar el nuevo límite 
de crédito que tendrá una persona en su tarjeta, para ello deberá solicitar el tipo de 
tarjeta y el monto actual de su tarjeta. (Calcular el porcentaje con regla de 3 simple)*/

int t = 0;
float p = 0;
float r = 0;

int main(){
    
    printf("seleccione tipo de tarjeta \n");
    printf("1-tipo uno \n2-tipo dos \n3-tipo tres \n4- otro \n");
    scanf("%d",&t);
    
    printf ("incerte credito: ");
    scanf ("%f",&p);

    switch (t){
    case 1: 
        r = (p*25)/100 + p;
       printf("el total abonado es: %f", r);
       break;
    
    case 2 :
        r = (p*35)/100 + p;
       printf("el total abonado es: %f", r);
       break;
    
    case 3 :
        r = (p*40)/100 + p;
       printf("el total abonado es: %f", r);
       break;
    
    case 4: 
        r = (p*50)/100 + p; 
       printf("el total abonado es: %f", r);
       break;
    }
 
        
    return 0;
}
