#include <stdio.h>

void g(int *n){
    printf("\tg: n = %d\n",*n);
}

void f(int *n){
    // es como si a *n le asignaramos la memoria &n
    // n interno a f
    // n = &n;
    //      ^
    //      n externa del main 
    printf("\tf: n = %d\n",*n);
    (*n)++;
    printf("\t");g(n);
    printf("\tf: n = %d\n",*n);
}

int main(){
    int n = 5;
    printf("Main: n = %d\n",n);
    f(&n);
    printf("Main: n = %d\n",n);
    return 0;
}
