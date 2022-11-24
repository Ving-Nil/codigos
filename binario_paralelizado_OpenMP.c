
// install on linux
// sudo apt-get install libomp-dev

/* compile and run
 * note that is not separated by spaces OMP_NUM_THREADS = 4, this not work
 *
 * gcc bool_OMP.c -fopenmp -o bool_OMP.out 
 * export OMP_NUM_THREADS=4
 * ./bool_OMP.out
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


//bolean function
int circuit(int A[16]){
	int a=A[0], b=A[1], c=A[2], d=A[3], e=A[4], f=A[5], g=A[6], h=A[7], i=A[8], j=A[9], k=A[10], l=A[11], m=A[12], n=A[13], o=A[14], p=A[15];
	int x,y,z,w;
	x = (((a||b)&&(!b||!d))&&((c||d)&&(!d||!e)));
	y = (((e||!f)&&(f||g))&&((f||!g)&&(h||!i)));
	z = (((i||j)&&(i||!j))&&((!j||!k)&&(k||l)));
	w = (((l||j)&&(m||n))&&((!h||!n)||((n||!o)&&((o||p)&&(p||g)))));
	return (x&&y)&&(z&&w);
}

long int pot(int x, int n){
	long int p=1;
	int k;
	for(k=1;k<=n;k++){
		p*=x;
	}
	return p;
}

void print(int i){
	     if(i<10){printf("        %d",i);}
	else if(i<100){printf("       %d",i);}
	else if(i<1000){printf("     %d",i);}
	else if(i<10000){printf("   %d",i);}
	else if(i<100000){printf(" %d",i);}
	else if(i<1000000){printf("%d",i);}
}

int main(int argc, char * argv[]){
	int n=1,i,j;
	if(argc==2){
		n = atoi( argv[1] ) ;
	}
	else{
		printf("Código binario de n bits\n");
		printf("> ");
		scanf("%d",&n);
		printf("\n");
	}
	
	int A[16];
	
	#pragma omp parallel for
	for(i=0;i<pot(2,n);i++){
		print(i);
		printf("  ");
		if(n==16){printf("f(");}
		for(j=0;j<n;j++){
			int aux = ((int)(i/pot(2,n-j-1))) % 2;
			if(n==16){A[j] = aux;}
			printf("%d", aux);
		}
		
		if(n==16){printf(")  = %d", circuit(A));}
		
		printf("\n");
	}
	
	return 0;
}
