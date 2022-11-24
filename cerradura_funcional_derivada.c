#include <stdio.h>
#define h 0.0000001
typedef double (*func)(double);
typedef  func(*Oper)(func);

func Deriv( func f ){
	
	double g(double x){
		return ( (*f)(x+h)-(*f)(x) )/(h);
	}
	func df = &g;
	return df;
}

double square(double x){
	return x*x;
}

int main(){
	double x = 10;
	printf("\n%lf\n\n",square(x));
	Oper D = &Deriv;
	printf("%lf\n",(*D(square))(x));
	return 0;
}
