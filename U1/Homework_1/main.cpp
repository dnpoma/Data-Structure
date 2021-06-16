#include <iostream>
#include <string>

#include "Number.h"
#include "Operation.h"

int main(int argc, char** argv) {
	
	float valor1, valor2;
	std::cout << "Ingrese el valor 1: ";
	std::cin >>valor1;
	
	std::cout << "Ingrese el valor2: ";
	std::cin >>valor2;
	
		
	Number<float> numero1;
	numero1.set_value1(valor1);
	
	Number<float> numero2;
	numero2.set_value1(valor2);
	
	Operation<float> operation;

	std::cout<<"Suma: "<<operation.addition(numero1.get_value1(), numero2.get_value1())<<std::endl;
	std::cout<<"Resta: "<<operation.subtraction(numero1.get_value1(), numero2.get_value1())<<std::endl;
	std::cout<<"Multiplicacion: "<<operation.multiplication(numero1.get_value1(), numero2.get_value1())<<std::endl;
	std::cout<<"Division: "<<operation.division(numero1.get_value1(), numero2.get_value1())<<std::endl;
	
//	std::cout<<numero1.to_string()<<std::endl;
	numero1.to_string();
	return 0;
}
