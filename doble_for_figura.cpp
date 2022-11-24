#include <iostream>
using namespace std;
int main()
{
    int n = 20;
    int x,y;
    for( y=n ; y>=-n ; y-- ){
        for(x=-n;x<=n;x++){
            if( x*x + y*y <= n*n && x>=0 &&  y>=0){
                cout<<". ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    return 0;
}
