
// Antes de todo, instalar la biblioteca MPI
// sudo apt-get install mpich

// Compilar y correr en linux
// mpicc bool.c -o bool.out
// mpirun -np 8 ./bool.out 16

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

// Función booleana
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

int main(int argc, char **argv){
    // current_id es el identificador del hilo
    // number_of_proces es la cantidad de hilos
	int ierr, current_id, number_of_process;
	
	ierr = MPI_Init(&argc, &argv);
	
	ierr = MPI_Comm_rank(MPI_COMM_WORLD,&current_id);
	ierr = MPI_Comm_size(MPI_COMM_WORLD,&number_of_process);
	
    //Casi el mísmo programa pero aprovechando cada hilo de ejecución
	/**************************************************************/
	int n=1,i,j;

    // "mpirun -np 8 ./bool.out 16" Asigna n=16 detectando
    // que han ingresado un dato por piping
	if(argc==2){
        // Convierte el dato de string a int 
		n = atoi( argv[1] ) ;
	}
	else{
        // Si no detecta datos pasados por piping
        // pide los datos por consola
		printf("Código binario de n bits\n");
		printf("> ");
		scanf("%d",&n);
		printf("\n");
	}
	
    // Sólo ocupamos el arreglo
	int A[16];
	
    // Se calculan los valores congruentes con 
    // "current_id (módulo number_of_proces)"
    // Es decir que si son dos hilos de ejecucion, uno ejecuta los pares y el otro los impares
    // si son 3 hilos h1, h2, h3 se ejecutan:
    // h1 = 0 (mod 3)
    // h2 = 1 (mod 3)
    // h3 = 2 (mod 3)
    // y así sucesivamente
	for(i=current_id;i<pot(2,n);i+=number_of_process){
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
	
	/**************************************************************/
	
	ierr = MPI_Finalize();
}
