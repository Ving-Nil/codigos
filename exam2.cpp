#include <iostream>
using namespace std;
void I(int A[99], int n){
    int i;
    for(i=0;i<n && i<99;i++){
        cout << "\nIngrese el valor " << i << " del arreglo: ";
        cin  >> A[i];
    }
    for(i=n;i<99;i++){
        A[i]=0;
    }
}
void V(int A[99], int n){
    int i;
    cout << "[";
    for(i=0;i<n-1;i++){
        cout << A[i] << ", ";
    }
    cout << A[n-1] << "]" << endl;
}

void pares(int A[99], int n){
    int i;
    cout << "[";
    for(i=0;i<n;i++){
        if(A[i]%2==0){
            cout << A[i] << " ";
        }
    }
    cout << "]" << endl;
}

void siete(int A[99], int n){
    int i;
    cout << "[";
    for(i=0;i<n;i++){
        if(A[i]%7==0){
            cout << A[i] << " ";
        }
    }
    cout << "]" << endl;
}

int main(){
    int resp,n=10,A[99];
    do{
        cout << "\nMENU\n";
        cout << "1) numeros que desea guardar\n";
        cout << "2) Capturar datos en el arreglo\n";
        cout << "3) Ver datos del arreglo\n";
        cout << "4) Enlistar todos los numeros pares\n";
        cout << "5) Enlistar todos los numeros multiplos de 7\n";
        cout << "0) Salir\n";
        cin  >> resp;
        if(resp==1){
            cout << "\nValor de N: ";
            do{cin  >> n;}while(n<=0||100<=n);
        }
        else if(resp==2){
            cout << "Capture los " << n << " datos\n";
            I(A,n);
        }
        else if(resp==3){
            cout << "Listado de todos los datos\n";
            V(A,n);
        }
        else if(resp==4){
            cout << "Listado de todos los datos pares\n";
            pares(A,n);
        }
        else if(resp==5){
            cout << "Listado de todos los datos multiplos de 7\n";
            siete(A,n);
        }
    }while(resp);
    return 0;
}

/**

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
1

Valor de N: 3

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
2
Capture los 3 datos

Ingrese el valor 0 del arreglo: 5

Ingrese el valor 1 del arreglo: 10

Ingrese el valor 2 del arreglo: 15

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
3
Listado de todos los datos
[5, 10, 15]

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
4
Listado de todos los datos pares
[10 ]

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
5
Listado de todos los datos multiplos de 7
[]

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
2
Capture los 3 datos

Ingrese el valor 0 del arreglo: 7

Ingrese el valor 1 del arreglo: 14

Ingrese el valor 2 del arreglo: 0

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
3
Listado de todos los datos
[7, 14, 0]

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
4
Listado de todos los datos pares
[14 0 ]

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
5
Listado de todos los datos multiplos de 7
[7 14 0 ]

MENU
1) numeros que dea guardar
2) Capturar datos en el arreglo
3) Ver datos del arreglo
4) Enlistar todos los numeros pares
5) Enlistar todos los numeros multiplos de 7
0) Salir
0

**/
