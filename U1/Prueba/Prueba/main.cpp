#include "Menu.h"
#include "Operation.h"
#include <iostream>
#include <limits>

#include "Person.h"

int main(int argc, char** argv) {
	Operation op;
	Doubly_linked_list<int> lst;
	char respuesta = ' ';
	int number;
	do {
		number = op.input_numbers(3);
		std::cout << number <<std::endl;
		lst.insert_end(number);
		std::cout << "\n El numero se almaceno correctamente en la lista :)" << std::endl;
		//cin >> respuesta;
		std::cout << "Desea ingresar otro dato [S/N]: ";
		std::cin.get(respuesta);
	} while (respuesta != 'N');
	lst.print();



	std::cout << "\n";
	int value2 = op.input_numbers(2);
	std::cout<<"\n";
	lst.modified_change(value2);
	lst.print();
	return 0;
}


