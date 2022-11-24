#include <stdio.h>
#include <stdlib.h>

int prim(int p){
	int i,r=1;
	if(p<2){
		return 0;
	}
	for(i=2;i<p;i++){
		r *= (p%i != 0);
	}
	return r;
}

void burbuja(int A[], int n){
	int y,x,auxiliar;
	for(y=0;y<n;y++){
		for(x=1;x<n-y;x++){
			if( A[x-1] > A[x] ){
				auxiliar = A[x];
				A[x] = A[x-1];
				A[x-1] = auxiliar;
			}
		}
	}
}

int juego(int n){
	int resp = (rand()%3);
	if( resp == 0 ){
		printf("\nComputadora: Piedra\n");
	}
	else if( resp == 1 ){
		printf("\nComputadora: Papel\n");
	}
	else if( resp == 2 ){
		printf("\nComputadora: Tijeras\n");
	}
	
	if( n == resp ){
		printf("\nEmpate\n");
	}
	else if( (n+1)%3 == resp ){
		printf("\nPerdiste\n");
	}
	else{
		printf("\nGanaste!!!\n");
	}
}

int main(){
	int n,i,p, menu;
	do{
		printf("\nMENU\n1) Tabla de primos hasta n\n2) Ordenamiento burbuja\n3) Pierdra, Papel o Tijeras\n0) Salir\n> ");
		scanf("%d",&menu);
		if( menu == 1){
			printf("\nIngrese un entero para imprimir los primos\n> ");
			scanf("%d",&n);
			for(p=1;p<=n;){
				for(i=0;i<10;i++){
					if(prim(p)){
						if(p<10){
							printf("   |%d| ",p);
						}
						else if(p<100){
							printf("  |%d| ",p);
						}
						else if(p<1000){
							printf(" |%d| ",p);
						}
					}
					else{
						if(p<10){
							printf("    %d  ",p);
						}
						else if(p<100){
							printf("   %d  ",p);
						}
						else if(p<1000){
							printf("  %d  ",p);
						}
					}
					p++;
				}
				printf("\n");
			}
		}
		else if( menu == 2 ){
			printf("Ingrese la cantidad de datos\n> ");
			scanf("%d",&n);
			printf("Desea ingresar datos o generar?[1 ingresar / 0 generar]\n> ");
			scanf("%d",&p);
			int A[n];
			for(i=0;i<n;i++){
				if(p){
					printf("\nDato %d\n> ",i+1);
					scanf("%d",&A[i]);
				}
				else{
					A[i] = rand()%100;
				}
			}
			printf("\nDatos:\n[");
			for(i=0;i<n-1;i++){
				printf("%d, ",A[i]);
			}
			printf("%d]\n",A[n-1]);
			
			burbuja(A,n);
			
			printf("\nDatos Ordenados:\n[");
			for(i=0;i<n-1;i++){
				printf("%d, ",A[i]);
			}
			printf("%d]\n\n",A[n-1]);
		}
		else if( menu == 3 ){
			printf("\nJuego de piedra papel o tijeras\n");
			printf("\n0) Piedra\n1) Papel\n2) Tijeras\n> ");
			scanf("%d",&n);
			juego(n);
		}
	}while( menu );
	return 0;
}
