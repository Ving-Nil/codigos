#include <iostream>

using namespace std;

int main( int argc, char * argv[] ){
    if ( 1 < argc ){
        for(int i=0;i<argc;i++){
            cout << argv[i] << endl;
        }
    }else{
        cout << "El programa corre normalmente\n";
    }
}
