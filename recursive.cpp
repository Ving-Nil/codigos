#include <iostream>

using namespace std;

void f( int n ){
    if (n<1){
        cout << 0 << endl;
    }
    else{
        cout << n << " ";
        f(n-1);
    }
}

void g(int n){
    if (n==0){
        cout << 0;
    }
    else{
        cout << n << " < ";
        g(n-1);
        cout << " > " << n;
    }
}

void h( int n ){
    if ( n<1 ){
        cout << 0 << " ";
    }
    else{
        h(n-1);
        cout << n << " ";
        h(n-1);
    }
}

int main(  ){
    f(10);
    g(3);
    cout << endl;
    h(3);
}
