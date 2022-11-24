
#include <stdio.h>
#include <stdlib.h>  // Función int atoi(char*), convierte string en int

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

//Potencia de x elevado a la n
long int pot(int x, int n){
	long int p=1;
	int k;
	for(k=1;k<=n;k++){
		p*=x;
	}
	return p;
}

// Imprimir de forma estética los números (alineados)
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

    //Si dan un numero al programa, hace n igual a ese número
	if(argc==2){
		n = atoi( argv[1] ) ;
	}
	else{
		printf("Código binario de n bits\n");
		printf("> ");
		scanf("%d",&n);
		printf("\n");
	}
	
    //A es el array para guardar el binario bit a bit para pasarlo a la función
    //unos guarda la cantidad de unos que devuelve en total todas las ejeciciones de la Función
	int A[16],unos=0, m;
	
    // patrón que genera todos los número binarios de n bits
    // genera los 2^n números de n bits cada uno bit por bit
	for(i=0;i<pot(2,n);i++){
		print(i);
		printf("  ");
		if(n==16){printf("f(");}    // Sólo con 16 bits puede correr la función
		for(j=0;j<n;j++){
			int aux = ((int)(i/pot(2,n-j-1))) % 2;
			if(n==16){A[j] = aux;}    // Sólo con 16 bits puede correr la función
			printf("%d", aux);
		}
		
		if(n==16){m = circuit(A);unos+=m;printf(")  = %d", m);}    // Sólo con 16 bits puede correr la función
		
		printf("\n");
	} 
	if(n==16){printf("\nLa función arroja %d unos\n",unos);}    // Sólo con 16 bits puede correr la función
	return 0;
}
