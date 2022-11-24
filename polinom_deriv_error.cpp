#include <iostream>
using namespace std;

// funcion factorial
long int factorial( int n ){
    long int u=1;
    for(int i=2;i<=n;i++){
        u*=i;
    }
    return u;
}

// valor absoluto
int abs( int n ){
    if ( 0<=n ){
        return n;
    }
    else{
        return -n;
    }
}

// valor absoluto
double doubleAbs( double n ){
    if ( 0<=n ){
        return n;
    }
    else{
        return -n;
    }
}

// potencia de x a un número entero
double pow( double x, int n ){
    double prod=1;
    for( int i=0;i< abs(n) ;i++ ){
        prod *= x;
    }
    if ( 0<=n ){
        return prod;
    }
    else{
        return 1/prod;
    }
}

long int fd( int n, int k ){
    long int u = 1;
    for ( int i=0;i<k;i++){
        u *= (n-i);
    }
    return u;
}

double derivEval( double x, double P[], int m, int n ){
    int p = m+1;
    double valor = 0;
    for(int i=n;i<p;i++){
        valor += P[i] * fd(i,n) * pow(x,i-n);
    }
    return valor;
}

int main(){
    // m es el grado del polinomio
    // n es el grado de la derivada
    int m = 2, n = 2;
    double x = 4, x0 = 1;
    double P[]={ 1.8 , 2.5 , -1 };

    double suma = 0, valor = 0;
    for(int i=0;i<m+1;i++){
		valor += P[i] * pow(x,i);
	}
	
	cout << "\n\n\n";
    for( int j = 0; j<n+1; j++){
        double e = derivEval( x0, P, m, j );
        suma += pow(x-x0,j)*e/factorial(j);
        cout << "Valor: " << valor << ", Suma: " << suma << ", Error: " << 100*doubleAbs((valor-suma)/valor) << endl;
    }
	cout << "\n\n\n\n";
    return 0;
}

