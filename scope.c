#include <stdio.h>

void g(int n){
    printf("\tg: n = %d\n",n);
}

void f(int n){
    printf("\tf: n = %d\n",n);
    n++;
    printf("\t");g(n*3);
    printf("\tf: n = %d\n",n);
}

int main(){
    int n = 5;
    printf("Main: n = %d\n",n);
    f(n+2);
    printf("Main: n = %d\n",n);
    return 0;
}
