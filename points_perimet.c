#include <stdio.h>
#include <math.h>
int main(){
    float suma = 0,x0,y0,x1,y1,x2,y2;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%f %f",&x1,&y1);
        if(i==0){
            x0=x1;
            y0=y1;
            x2=x1;
            y2=y1;
        }else{
            suma += sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
            x2=x1;
            y2=y1;
        }
    }
    // el último punto recibido con el primer punto recibido
    suma += sqrt( (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) );
    printf("%.2f\n",suma);
    return 0;
}
