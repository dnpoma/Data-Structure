#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int factorial(int);
int factorial(int n)
{
	if(n<1)
		return 1; //para suma retorno 0; 
	else
		return n*factorial(n-1);
}

int factorial(int n)
{
	return (n<0)?:n*factorial(n-1);
}

int main(int argc, char** argv) {
	cout<<fatorial(5)<<endl;
	return 0;
}
