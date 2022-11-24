#include <iostream>
using namespace std;
void I(int A[5], int n){
    int i;
    for(i=0;i<n;i++){
        cout << "\nIngrese el valor " << i << " del arreglo: ";
        cin  >> A[i];
    }
}
void V(int A[5], int n){
    int i;
    cout << "[";
    for(i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << "]" << endl;
}
void ooo(int A[5], int n){
    int aux, i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(A[j]>A[j+1]){
                aux    = A[j];
                A[j]   = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}
int main(){
    int valores[5];
    I(valores,5);
    ooo(valores,5);
    V(valores,5);
    return 0;
}

/**

Ingrese el valor 0 del arreglo: 5

Ingrese el valor 1 del arreglo: 10

Ingrese el valor 2 del arreglo: 2

Ingrese el valor 3 del arreglo: 3

Ingrese el valor 4 del arreglo: 1
[1 2 3 5 10 ]

**/
