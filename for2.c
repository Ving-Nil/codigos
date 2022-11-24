#include <stdio.h>
int main(){
    int n=10,i=3;
    for(;;){
        if( !(i<n) ){
            break;
        }
        printf("i = %d\n",i);
        i++;
    }
    return 0;
}
