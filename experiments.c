#include <stdio.h>

int main(){
    int resp = -10;

    if(1){
        printf("Siempre se ejecuta\n");
    }
    if(0){
        printf("Nunca se ejecuta\n");
    }
    if(resp){
        printf("Sorpresa!!!\n");
    }
    return 0;
}
