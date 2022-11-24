#include <stdio.h>
int main(){
    long int   n = 10, *p;
    float x = 10.012345, *f;
    p = &n;
    f = &x;
    printf("n = %ld, x = %f\n",n,x);
    // cast: x = (float)n; n = (int)x;
    printf("%d\n",(int)x);
    p = (long int*)f;
    printf("\n*p = %ld\n", *p);
    printf("n = %ld, x = %f\n",n,x);
    printf("*p = *p << 1\n");
    *p = *p << 1;
    printf("\n*p = %ld\n", *p);
    printf("n = %ld, x = %f\n",n,x);
    return 0;
}
