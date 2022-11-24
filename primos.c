#include <stdio.h>
int prim(int p){
    if ( p<2 ){return 0;}
    for(int i=2;i<p;i++){
        if ( p%i==0 ){return 0;}
    }
    return 1;
}
int main(){
    int n=500;
    for(int i=0;i<n;i++)
    if( prim(i) ){printf("%d True\n",i);}
    //else{printf("False\n");}
    return 0;
}
