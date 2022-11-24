#include <stdio.h>

void g(){
    printf("\testo es la funcion g\n");
}

void f(){
    printf("\testo es la funcion f\n");
    printf("\t");g();
    printf("\testo es la funcion f\n");
}

int main(){
    printf("Bienvenido a la función main\n");
    f();
    g();
    printf("Adiós desde la función main\n");
    return 0;
}
