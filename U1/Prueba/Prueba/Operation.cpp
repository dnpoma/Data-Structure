#include "Operation.h"
#include <iostream>
int* Operation::data_expand(int valor, int data[]) {
	int i = 0;
	while (valor > 0) {
		data[i] = valor % 10;
		valor = valor / 10;
		i++;
	}
	return data;
}


int Operation::input_numbers(int value) {
	char dimension[5];
	int operation = 0, lenght = 0, number = 0;
	std::cout << "Ingrese un numero con " << value << " digitos: ";
	do {
		val.integer(dimension, value);
		number = atoi(dimension);
		lenght = val.digits(number);
		if (lenght != value) {
			std::cout << "\nEl numero ingresado solo tiene " << lenght << " digitos" << std::endl;
			std::cout << "Ingrese otro numero: ";
		}
	} while (lenght != value);
	return number;
}