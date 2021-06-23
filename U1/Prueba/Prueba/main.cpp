#include "Menu.h"
#include "Operation.h"
#include <iostream>
int* data_expand(int, int[]);
int input_numbers(int);
void comparation(int, Doubly_linked_list<int>);

int main(int argc, char** argv) {
	Operation op;
	Doubly_linked_list<int> lst;
	//lst.insert_start(2);
	//lst.insert_start(4);
	//lst.insert_start(3);
	//lst.insert_start(4);
	//lst.insert_start(1);
	//lst.print();
	//lst.modified();
	//lst.print();
	char respuesta = ' ';
	int number;
	do {
		number = op.input_numbers(3);
		lst.insert_end(number);
		std::cout << "\n El numero se almaceno correctamente en la lista :)" << std::endl;
		std::cout << "Desea ingresar otro dato [S/N]: ";
		//cin >> respuesta;
		cin.get(respuesta);

		cin.clear(); // unset failbit
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input 
		if (respuesta == 'N') {
			lst.insert_end(number);
		}
	} while (respuesta != 'N');

	lst.print();


	
	//int data_final[3];
	//int numero;
	//char dimension2[5];
	//std::cout << "\n Ingrese un numero con 2 digitos: ";
	//do {
	//	
	//	val.integer(dimension2, 2);
	//	value2 = atoi(dimension2);
	//	lenght2 = val.digits(value2);
	//	if (lenght2 != 2) {
	//		std::cout << "\nEl numero ingresado solo tiene " << lenght2 << " digitos" << std::endl;
	//		std::cout << "Ingrese otro numero: ";
	//	}
	//} while (lenght2 != 2);

	std::cout << "\n";
	int value2 = op.input_numbers(2);
	std::cout<<"\n";
	lst.modified_change(value2);

	//std::cout << "\n\n";
	//int value2 = input_numbers(2);

	//int value_digits[3];
	//// si se ingresa 234 retorna 5 4 3
	//// number = 543 value_2digits = []
	//int* data = data_expand(number, value_digits); 
	//// calcula la dimension del array 2
	//int i = (sizeof(data) / sizeof(data[0]))+1;
	//std::cout <<"\n\n"<< data[2] << "\n" << data[1] << "\n" << data[0] << "\n" << std::endl;
	//for (int s = i-1; s >= 0; s--)
	//{
	//	std::cout << s <<" : " <<data[s] << std::endl;
	//	std::cout << "---"<<std::endl;
	//	for (int j = i - 1; j >= 0; j--) {
	//		if ((s == 1 && j == 0) || (s == 2 && j == 1)) {
	//			number = data[s] * 10 + data[j];
	//			if (value2 == number) {
	//				// dato a modificar, nuevo valor
	//				lst.modified_input(value2,number);
	//			}
	//		}
	//		//if (s != j) {
	//		//	number = data[s] * 10 + data[j];
	//		//	//numero contiene a los valores
	//		//	std::cout << s << " " << j << " " << number << std::endl;
	//		//	if (value2 == number) {
	//		//		//std::cout << "Hereeee"<< number;
	//		//	}
	//		//}
	//	}
	//	std::cout << "---" << std::endl;
	//}

	lst.print();
	return 0;
}


