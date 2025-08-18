
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int a[2][3];
    srand(time(NULL));

    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            *(*(a + i)+j) = rand()%100 + 1;
        }
    }

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            printf("%d\t", *(*(a+i)+j));
        }
        printf("\n");
    }
}
