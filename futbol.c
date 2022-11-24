 
#include <stdio.h>
#include <stdlib.h>
 
//Funcióón para imprimir enteros positivos de forma mejor
void print(int n){
    if(n<10){printf("   %d",n);}
    else if(n<100){printf("  %d",n);}
    else if(n<1000){printf(" %d",n);}
    else if(n<10000){printf("%d",n);}
}
 
int main(){
    int n,m,i,j,c=0;
    printf("Bienvenido\n");
 
    //Etapa 1
    FILE * f = fopen("1_equipos.txt", "w");
    if(f==NULL){
        printf("El archivo no se pudo abrir o crear correctamente\n");
    }
    else{
        do{
            printf("Ingrese la cantidad de equipos a registrar\n>>> ");
            scanf("%d",&n);
            printf("\n");
        }while( n<8 || n%2==1);
        m=(int)(n/2);
        for(i=0;i<=n;i++){
            fflush(stdin);
            if(i!=0){
                printf("Equipo numero %d\n",i);
                printf("Ingrese el nombre del equipo\n>>> ");
            }
            char *line = NULL;
            size_t len=0;
            getline(&line,&len,stdin);
            if(i!=0){
                fprintf(f,"%d %s",i,line);
            }
            if(line){free(line);}
        }
        printf("\n\n");
    }
    fclose(f);
 
    //Etapa 2
    int A[m][2],B[m*(2*n-2)][4];
 
    FILE * g = fopen("2_calendario.txt", "w");
    if(g==NULL){
        printf("Error leyendo archivo\n");
    }
    else{
        //printf("Local, visitante\tlocal, visitante");
        for(j=1;j<=n-1;j++){
            printf("\nSemana %d \t Semana %d\n",2*j-1,2*j);
            fprintf(g,"Semana %d\n",2*j-1);
            if(j==1){
                for(i=0;i<m;i++){
                    A[i][0] = 2*m-i+1;
                    A[i][1] = i+2;
                    if(i==0){A[i][0] = 1;}
 
                    print(A[i][0]);
                    printf(" ");
                    print(A[i][1]);
                    printf(" \t ");
                    print(A[i][1]);
                    printf(" ");
                    print(A[i][0]);
                    printf("\n");
                    
                    B[c][0]=A[i][0];B[c][1]=A[i][1];B[c][2]=rand()%7;B[c][3]=rand()%7;
                    fprintf(g,"equipo %d vs equipo %d, goles: %d %d\n",B[c][0],B[c][1],B[c][2],B[c][3]);
                    c++;
                }
            }
            else{
                int aux1,aux2,a1,a2;
                for(i=0;i<m;i++){
                    if(i==0){aux1=A[1][0];aux2=A[m-1][1];a1=A[0][1];}
                    if (0<i){
                        A[i-1][0] = A[i][0];
                        
                        a2 = A[i][1];
                        A[i][1] = a1;
                        a1=a2;
                    }
                    if(i==m-1){A[0][1]=aux1;A[m-1][0]=aux2;}
                    A[0][0] = 1;
                }
                for(i=0;i<m;i++){
                    
                    print(A[i][0]);
                    printf(" ");
                    print(A[i][1]);
                    printf(" \t ");
                    print(A[i][1]);
                    printf(" ");
                    print(A[i][0]);
                    printf("\n");
                    
                    B[c][0]=A[i][0];B[c][1]=A[i][1];B[c][2]=rand()%7;B[c][3]=rand()%7;
                    fprintf(g,"equipo %d vs equipo %d, goles: %d %d\n",B[c][0],B[c][1],B[c][2],B[c][3]);
                    c++;
                }
            }
            fprintf(g,"Semana %d\n",2*j);
            for(i=0;i<m;i++){
                    B[c][0]=A[i][1];B[c][1]=A[i][0];B[c][2]=rand()%7;B[c][3]=rand()%7;
                    fprintf(g,"equipo %d vs equipo %d, goles: %d %d\n",B[c][0],B[c][1],B[c][2],B[c][3]);
                    c++;
            }
        }
    }
    fclose(g);
    
    //Etapa 3
    int equipo[n]; //Guarda los puntajes
    FILE * h = fopen("3_partidos_puntajes.txt", "w");
    
    for(i=0;i<n;i++){equipo[i]=0;}
    for(i=0;i<m*(2*n-2);i++){
        equipo[ B[i][0] - 1 ] += B[i][2] * 1; //Un punto locales
        equipo[ B[i][1] - 1 ] += B[i][3] * 2; //Dos puntos visitantes
    }
    printf("\nEquipos y puntajes obtenidos en toda la jornada\n");
    for(i=0;i<n;i++){
        printf("Equipo: %d\tPuntaje: %d\n",i+1,equipo[i]);
        fprintf(h,"equipo %d con puntaje %d\n",i+1,equipo[i]);
    }
    
    fclose(h);
    
    //Etapa 4
    
    int Eq[n];for(i=0;i<n;i++){Eq[i]=i+1;}
    for(i=n-1;0<=i;i--){
        for(j=0;j<i;j++){
            if(equipo[j+1] > equipo[j]){
                c = equipo[j+1];
                equipo[j+1] = equipo[j];
                equipo[j] = c;
                c = Eq[j+1];
                Eq[j+1] = Eq[j];
                Eq[j] = c;
            }
        }
    }
    
    printf("\nEquipos\n");
    printf("[");
    for(i=0;i<n;i++){
        printf("%d ",Eq[i]);
    }
    printf("]\n");
    
    printf("Puntajes por equipo\n");
    printf("[");
    for(i=0;i<n;i++){
        printf("%d ",equipo[i]);
    }
    printf("]\n");
    
    
    FILE * p = fopen("4_8_mejores.txt", "w");
    printf("\n8 Mejores equipos\n");
    for(i=0;i<8;i++){
        printf("Lugar: %d\tEquipo: %d\tPuntaje: %d\n",i+1,Eq[i],equipo[i]);
        fprintf(p,"Lugar %d, equipo %d, puntaje %d\n",i+1,Eq[i],equipo[i]);
    }
    fclose(p);
    
    printf("\nEquipo ganador\n");
    FILE * q = fopen("1_equipos.txt", "r");
    FILE * r = fopen("GANADOR.txt", "w");
    char *line = NULL;
    size_t len=0;
    i=1;
    while( !feof(q) && i<=n ){
        getline(&line,&len,q);
        if(i==Eq[0]){
            printf("\nCon %d puntos el equipo ganador es ",equipo[0]);
            fprintf(r,"numero: %d, puntos totales: %d, nombre: ",i,equipo[0]);
            j=0;c=0;
            while(line[j]!='\0'){
                if(c){printf("%c",line[j]);fprintf(r,"%c",line[j]);}
                if(line[j]==' ' && !c){c=!c;}
                j++;
            }
        }
        i++;
    }
    fclose(q);
    fclose(r);
    return 0;
}

/**

Bienvenido
Ingrese la cantidad de equipos a registrar
>>> 8

Equipo numero 1
Ingrese el nombre del equipo
>>> q
Equipo numero 2
Ingrese el nombre del equipo
>>> w
Equipo numero 3
Ingrese el nombre del equipo
>>> e
Equipo numero 4
Ingrese el nombre del equipo
>>> 
Equipo numero 5
Ingrese el nombre del equipo
>>> r
Equipo numero 6
Ingrese el nombre del equipo
>>> t
Equipo numero 7
Ingrese el nombre del equipo
>>> y
Equipo numero 8
Ingrese el nombre del equipo
>>> u



Semana 1 	 Semana 2
   1    2 	    2    1
   8    3 	    3    8
   7    4 	    4    7
   6    5 	    5    6

Semana 3 	 Semana 4
   1    8 	    8    1
   7    2 	    2    7
   6    3 	    3    6
   5    4 	    4    5

Semana 5 	 Semana 6
   1    7 	    7    1
   6    8 	    8    6
   5    2 	    2    5
   4    3 	    3    4

Semana 7 	 Semana 8
   1    6 	    6    1
   5    7 	    7    5
   4    8 	    8    4
   3    2 	    2    3

Semana 9 	 Semana 10
   1    5 	    5    1
   4    6 	    6    4
   3    7 	    7    3
   2    8 	    8    2

Semana 11 	 Semana 12
   1    4 	    4    1
   3    5 	    5    3
   2    6 	    6    2
   8    7 	    7    8

Semana 13 	 Semana 14
   1    3 	    3    1
   2    4 	    4    2
   8    5 	    5    8
   7    6 	    6    7

Equipos y puntajes obtenidos en toda la jornada
Equipo: 1	Puntaje: 66
Equipo: 2	Puntaje: 57
Equipo: 3	Puntaje: 63
Equipo: 4	Puntaje: 55
Equipo: 5	Puntaje: 51
Equipo: 6	Puntaje: 55
Equipo: 7	Puntaje: 58
Equipo: 8	Puntaje: 43

Equipos
[1 3 7 2 4 6 5 8 ]
Puntajes por equipo
[66 63 58 57 55 55 51 43 ]

8 Mejores equipos
Lugar: 1	Equipo: 1	Puntaje: 66
Lugar: 2	Equipo: 3	Puntaje: 63
Lugar: 3	Equipo: 7	Puntaje: 58
Lugar: 4	Equipo: 2	Puntaje: 57
Lugar: 5	Equipo: 4	Puntaje: 55
Lugar: 6	Equipo: 6	Puntaje: 55
Lugar: 7	Equipo: 5	Puntaje: 51
Lugar: 8	Equipo: 8	Puntaje: 43

Equipo ganador

Con 66 puntos el equipo ganador es q

**/
