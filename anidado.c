#include <stdio.h>

void h(){
    printf("\tfunción h\n");
}

void f(){

    // defino una función dentro de otra
    void g(){
        printf("\t\tfunción g\n");
    }

    printf("\tfunción f\n");
    g();
    printf("\tfunción f\n");
    printf("\t");h();
    printf("\tfunción f\n");
}

int main(){
    printf("principio de main\n");
    h();
    f();
    printf("fin de main\n");
    return 0;
}
