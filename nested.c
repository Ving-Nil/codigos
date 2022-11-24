#include <stdio.h>

void f(int n){
    printf("\tprincipio de f\n");
    void g(int n){
        printf("\tg: n = %d\n",n);
    }
    void h(int n){
        printf("\th: n = %d\n",n);
        printf("\tf->");printf("\th->");g(n-4);
        printf("\tf->");printf("\th: n = %d\n",n);
    }
    printf("\tf: n = %d\n",n);

    printf("\tprincipio de g\n");
    printf("\tf->");g(n+5);
    printf("\tfin de g\n");

    printf("\tprincipio de h\n");
    printf("\tf->");h(n+2);
    printf("\tfin de h\n");

    printf("\tf: n = %d\n",n);
    printf("\tfin de f\n");
}

int main(){
    int n=10;
    printf("principio de main\n");
    printf("main: n = %d\n",n);
    printf("\n");

    f(n+7);

    printf("\n");
    printf("main: n = %d\n",n);
    printf("fin de main\n");
    return 0;
}
