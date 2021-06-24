// correction_exam.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Person.h"
#include "Doubly_linked_list.h"
#include "string"
int main()
{
	Validation validation;
	Person person;
	Operation operation;
	//List list;
	Doubly_linked_list* lista = new Doubly_linked_list();


	char respuesta = ' ';
	int number;
	do {
		char cedula_A[11], nombre_A[25], apellido_B[25];
		string nombre, apellido;
		int cedula;
		cout << "Ingrese la cedula: ";
		operation.enter_ID(cedula_A);
		cedula = atoi(cedula_A);
		person.set_id("0"+to_string(cedula));

		//cout << "\nIngrese su nombre: ";
		//validation.letters(nombre_A);
		//nombre.append(nombre_A);
		//person.set_name(validation.capital_letter(nombre));

		//cout << "\nIngrese su Apellido:  ";
		//validation.letters(apellido_B);
		//apellido.append(apellido_B);
		//validation.capital_letter(apellido);
		//person.set_last_name(validation.capital_letter(apellido));

		//cout << "\nSu Correo es: ";
		//operation.generate_email(&person, 0);
		//cout << person.get_email();

		int  id[11], encryption;
		cout << "\nSuma cedula: "<< operation.plus_id(&person, id);
		//cout << "\nIngrese un número de encriptacion: ";
		std::cout << std::endl;
		encryption = operation.input_number(1);
		std::cout<<std::endl;
		operation.generate_encryption(&person, encryption);
		std::cout << person.get_encryption();

		lista->insert_end(person);
		std::cout << "\n El dato se almaceno correctamente en la lista :)" << std::endl;

		//int value2 = operation.input_number(1);
		//lista.modified_change(value2);

		std::cout << "\nDesea ingresar otro dato [S/N]: ";
		//cin >> respuesta;
		cin.get(respuesta);

		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input 
		if (respuesta == 'N') {
			lista->insert_end(person);
		}
	} while (respuesta != 'N');
	lista->print();
	return 0;

}

