#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,i;
    for(i=1;i<10;i++){
        long int j,k=1;
        for(j=1;j<=i;j++){k*=10;}
        long int aleatorio = (rand()%78)*k;

        if(0<=aleatorio && aleatorio<10){
            printf("     %ld\n",aleatorio);
        }
        else if(10<=aleatorio && aleatorio<100){
            printf("    %ld\n",aleatorio);
        }
        else if(100<=aleatorio && aleatorio<1000){
            printf("   %ld\n",aleatorio);
        }
        else if(1000<=aleatorio && aleatorio<10000){
            printf("  %ld\n",aleatorio);
        }
        else if(10000<=aleatorio && aleatorio<100000){
            printf(" %ld\n",aleatorio);
        }
        else{
            printf("%ld\n",aleatorio);
        }
    }
    return 0;
}
