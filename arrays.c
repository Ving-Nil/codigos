#include <stdio.h>

int main(){
    // Array, arreglo, vectores
    //                    0  1   2  3  4
    int n = 6, i, A[5] = {2, 4, 12, 3, 0};
    printf("[");
    for(i=0;i<5;i++){
        printf("%d ", A[i]);
    }
    printf("]\n");

    A[2] = 8;

    printf("[");
    for(i=0;i<5;i++){
        printf("%d ", A[i]);
    }
    printf("]\n");   
    
    for(i=0;i<5;i++){
        A[i] = 5-i;
    }

    printf("[");
    for(i=0;i<5;i++){
        printf("%d ", A[i]);
    }
    printf("]\n"); 

    return 0;
}
