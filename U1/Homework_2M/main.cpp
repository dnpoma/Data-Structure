#include <iostream>

using namespace std;

int suma(int);
int suma(int,float);
float suma(float,int);


int suma(int v){
	return v*5;
}
int suma(int v,float a){
	return int(v)+a; 
}
float suma(float v,int a){
	return float(a)+v;
}


int main(int argc, char** argv) {
	int a=5;
	float b=5.5f;
	cout<<"suma de un parametros %d "<<suma(a)<<endl;
	cout<<"suma de dos parametros %d "<<suma(a,b)<<endl;
	cout<<"suma de dos parametros %d "<<suma(b,a)<<endl;

	return 0;
}
