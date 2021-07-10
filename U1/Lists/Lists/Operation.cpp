#include "Operation.h"

/**
* @brief validate_email, valida si el email generado ya existe o no con respecto
* a los datos almacenados en la listas, en caso de existir se agrega un valor a email
*
* @param Person* persona permite acceder a los datos persona
*
* @return void
*/
void Operation::validate_email(Person* persona, Doubly_linked_list<Person>* list) {
	bool repeat = true;
	int operation = 0, number = 0;
	do {
		generate_email(persona, number);
		std::cout << persona->get_email();
		try {
			repeat = list->search_email(persona->get_email());
			if (repeat) {
				number++;
			}
			else {
				throw "\n\tEl correo se generará en un segundo\n";
				repeat = false;
			}
		}
		catch (const char* dato) {
			std::cout << dato;
		}
	} while (repeat);
}


/**
* @brief generate_email Se genera el email, validando los datos existentes de cada persona
*
* @param Person* persona permite acceder a los datos de persona
* @param value es las veces que se repite el email
*
* @return void
*/
void Operation::generate_email(Person* persona, int value)
{
	const char* domain = "@espe.edu.ec";
	std::string name[2], last_name[2];
	std::string* array_name = Utils::Validation::split(persona->get_name(), name);
	std::string* array_last_name = Utils::Validation::split(persona->get_last_name(), last_name);
	//llamar a una funcion uwu
	std::string email, username;

	if (array_name[1] != "") {
		username = { (array_name[0][0]), (array_name[1][0]) };
	}
	else {
		username = { (array_name[0][0]) };
	}
	if (value == 0) {
		username += (array_last_name[0]);
	}
	else {
		username += (array_last_name[0]) + std::to_string(value);
	}
	//std::cout << "Username: " << usuario <<"\n\n";
	email = username + domain;
	//std::cout <<"Correo: " << email;
	//std::cout << ("\n\n\n");
	persona->set_email(email);
}