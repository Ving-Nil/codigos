#include <iostream>
using namespace std;
int main(){
    int i=0,k=0,n;
    char S[] = "Lavan esa base naval";

    cout << S << endl;

    while( S[i] != '\0' ){
        if( 65 <= S[i] && S[i] <= 90 ){
            S[i] = S[i] + 32;
        }
        if( 97 <= S[i] && S[i] <= 122 ){
            S[i-k] = S[i];
        }
        else{
            k++;
        }
        i++;
    }
    // cuantas letras tiene?
    n = i-k;
    S[i-k] = '\0';

    // i va de    0 a n-1
    // k va de  n-1 a 0 

    // detectar si todos son 1's
    // o si existe algún 0
    
    int resp = 1;
    for(i=0,k=n-1;i<n;i++,k--){
        // dos casos
        // 1) 1*1*1*1*1*1*(...)*1 = 1 es palindromo si son todas las parejas iguales
        // 2) 1*1*1*1*0*1*(...)*1 = 0 no es palindromo si falla en al menos una pareja
        //            ^
        resp = resp * (int)(S[i] == S[k]);
    }
    
    if(resp){
        cout << "Es palindromo\n";
    }
    else{
        cout << "No es palindromo\n";
    }
    return 0;
}
