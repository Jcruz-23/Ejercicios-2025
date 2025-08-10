#include <stdio.h>

void swap(int*, int*);

int main(){
int a = 6, b = 3;

printf("a: %d\n", a);
printf("b: %d\n", b);
swap(&a, &b);
printf("intercamiando valores...\n");
printf("a: %d\n", a);
printf("b: %d\n", b);

return 0;
}


void swap(int *x, int *y){
    int help;
    help = *y;
    *y = *x;
    *x = help;
}