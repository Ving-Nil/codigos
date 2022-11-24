#include <stdio.h>

void g(int *p){
    printf("\tg: n = %d\n",*p);
}

void f(int *puntero){
    // es como si a *puntero le asignaramos la memoria &n
    // puntero interno a f
    // puntero = &n;
    //            ^
    //            n externa del main 
    printf("\tf: n = %d\n",*puntero);
    (*puntero)++;
    printf("\t");g(puntero);
    printf("\tf: n = %d\n",*puntero);
}

int main(){
    int n = 5;
    printf("Main: n = %d\n",n);
    f(&n);
    printf("Main: n = %d\n",n);
    return 0;
}
