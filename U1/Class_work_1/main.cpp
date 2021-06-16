#include <iostream>
#include "Vector.h"
#include "Operaciones.h"

int main(int argc, char** argv) {
	int vector[10];
	
	Vector vect(vector);
	Operaciones op;

	int &vectorrr = *vect.get_vector();
	op.encerar(&vectorrr);
	
	int option;
	do {
		system("cls");
		std::cout << "1. Encerar" << std::endl;
		std::cout << "2. Insertar" << std::endl;
		std::cout << "3. Calculo del promedio" << std::endl;
		std::cout << "4. Imprimir" << std::endl;
		std::cout << "0. Salir" << std::endl;
		std::cout << std::endl;
		std::cout << "Ingrese la operacion a realizar: ";
		std::cin >> option;

		switch (option) {
		case 0:
			std::cout << "Gracias por utilizar nuestro programa" << std::endl;
			break;
			
		case 1:
			std::cout<<"Se encero el vector correctamente"<<std::endl;
			op.encerar(&vectorrr);
			std::cout << std::endl;
			break;
		case 2:
			op.ingresar(&vectorrr);
			std::cout<<"Se insertaron los datos correctamente"<<std::endl;
			break;
		case 3:
			std::cout<<"El promedio es de: "<<op.procesar(&vectorrr)<<std::endl;
			break;
		case 4:
			std::cout<<"Los datos del vector son:"<<std::endl;
			op.imprimir(&vectorrr);
			std::cout << std::endl;
			break;
		default:
			std::cout << "La operacion ingresada no existe, vuelve a interntar" << std::endl;
		}
		system("pause");
	} while (option != 0);
	

	
	return 0;
}
