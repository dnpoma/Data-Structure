#include "Operation.h"
#include "Person.h"
#include <iostream>
#include <string>

std::string Operation::input() {
	std::string information;
	getline(std::cin, information, '\n');
	//std::cin.ignore();
	return information;
}

// btw son dos generados pero necesito a las listas para ver los datos pero 
// por ahora lo voy a hacer con los objetos
// HAY QUE MODIFICAR PARA QUE SEAN CON LAS LISTASSSSSSSS
//str::string el email generado
void Operation::validate_email(Person* persona) {
	bool repeat = true;
	int operation = 0, number = 0;
	do {
		generate_email(persona, number);
		std::cout << persona->get_email();
		try {
			if (persona->get_email() == persona->get_email()) {
				number++;
			}
			else {
				throw "\n El correo se generará en un segundo";
				repeat = false;
			}
		}
		catch (const char* dato) {
			std::cout << dato;
		}
	} while (repeat);
}

//Aqui se genera el email uwu
void Operation::generate_email(Person* persona, int value)
{
	const char* domain = "@espe.edu.ec";
	std::string name[2], last_name[2];
	std::string* array_name = lower_separate(persona->get_name(), name);
	std::string* array_last_name = lower_separate(persona->get_last_name(), last_name);
	//llamar a una funcion uwu
	std::string email, username;

	if (*(array_name + 1) != "") {
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
	persona->set_username(username);
	persona->set_email(email);

}
void Operation::generate_password(Person* persona, int value)
{
	const char* domain = "@espe.edu.ec";
	std::string name[2], last_name[2], id[2];
	std::string* array_name = lower_separate(persona->get_name(), name);
	std::string* array_last_name = lower_separate(persona->get_last_name(), last_name);
	std::string* array_id = lower_separate(persona->get_id(), id);
	//llamar a una funcion uwu
	std::string email, username, password;

	if (array_name[1] != "") {
		username = { (array_name[0][0]), (array_name[0][1]),(array_name[1][4]), (array_name[1][5]) };
	}
	else {
		username = { (array_name[0][0]) };
	}

	if (value == 0) {
		username += { (array_last_name[0][7]), (array_last_name[0][8]) };
	}
	else {
		username += { (array_last_name[0][0]) };
	}

	if (value == 0) {
		username += { (array_id[0][2]), (array_id[0][3]) };
	}
	else {
		username += { (array_id[0][0]) };
	}
	persona->set_email(username);
}


void Operation::generate_encryption(Person* persona, int value) {
	std::string encryption;
	int id = stoi(persona->get_id());
	//std::cout << id << std::endl;
	int new_id[11], operation[2], caculator=0, rest = 0;
	int* data = data_expand(id, new_id);
	for (int s = 10 - 1; s >= 0; s--) {
		caculator = *(data+s) + value;
		if (s == 9 && (*(data + s) != 1 && *(data + s) != 2)) {
			encryption += std::to_string(value);
		}
		else {

			if (caculator > 9) {
				encryption += std::to_string(plus(caculator, operation, 2));
			}
			else {
				encryption += std::to_string(caculator);
			}
		}
		//std::cout <<s<<"  "<< value << "  " << *(data + s) << "   " << caculator  << "  "<< rest <<"  " << encryption << std::endl;
	}
	persona->set_encryption(encryption);
}

std::string* Operation::lower_separate(std::string information, std::string array_name[2]) {
	information += " ";
	//Coloca los caracteres en letra minusculas :)
	for (int i = 0; i < information.length(); i++)
	{
		information[i] = tolower(information[i]);
	}
	//Separa el string por los espacios " "
	std::string delimiter = " ", token;
	size_t pos = 0;
	int i = 0;
	while ((pos = information.find(delimiter)) != std::string::npos) {
		std::cout << array_name[i];
		token = information.substr(0, pos);
		array_name[i] = token; // guardo cada valor en un array de string
		information.erase(0, pos + delimiter.length());
		i++;
	}
	return array_name;
}

bool Operation::phone_validation(int phone, int lenght) {
	int value[10];
	int* data = data_expand(phone, value);
	//int lenght = (sizeof(data) / sizeof(data[0])) + 1;
	int condition[] = { 2,3,4,5,6,7 };
	bool repeat = true;

	if (data[lenght - 1] == lenght && lenght == 9) {
		std::cout << "\nEl numero ingresado corresponde a un numero de telefono mobil\n ";
		repeat = false;
	}
	if (lenght == 8) {
		for (int i = 0; i < 8; i++)
		{
			if (data[lenght - 1] == condition[i]) {
				std::cout << "\nEl numero ingresando corresponde a un numero convencional 0" << data[lenght - 1] << "\n";
				repeat = false;
			}
		}
	}
	return repeat;
}

//
//
//
int* Operation::data_expand(int value, int data[]) {
	int i = 0;
	while (value > 0) {
		data[i] = value % 10;
		value = value / 10;
		i++;
	}
	return data;
}


// Evalua que se ingresen los numeros que se supone
// si comienza en cero, no coge ese numero
// input 0996726158  10 digitos
// output 996726158 9 digitos
std::string Operation::input_numbers(int value) {
	char dimension[11];
	bool repeat = true;
	int operation = 0, lenght = 0, number = 0;

	do {
		val.integer(dimension, value);
		number = atoi(dimension);
		lenght = digits(number);
		try {
			if (lenght == value - 1 || lenght == value - 2) {
				repeat = phone_validation(number, lenght);
				//std::cout << "\n\nrepeat" << repeat;
			}
			else {
				throw "\n El numero ingresado es incorrecto\nIngrese otro numero: ";
			}
		}
		catch (const char* dato) {
			std::cout << dato;
		}
	} while (repeat);
	return dimension;
}

int Operation::digits(int number) {
	int contador = 1;
	while (number / 10 > 0)
	{
		number = number / 10;
		contador++;
	}
	return contador;
}

int Operation::date_comprobation(int limit1, int limit2, int value) {
	char dimension[5];
	bool repeat = true;
	int operation = 0, lenght = 0, number = 0;
	do {

		val.integer(dimension, value);
		number = atoi(dimension);
		try {
			if (number<limit1 || number>limit2) {
				throw "\n El numero ingresado es incorrecto: \nIngrese otro numero: ";
			}
		}
		catch (const char* dato) {
			std::cout << dato;
		}
	} while (number<limit1 || number>limit2);
	return number;
}

void Operation::enter_ID(char* character) {
	bool repeat = true;
	do {
	int i = 0, number_character = 10;
	int num, adition = 0, number;
	int digits[10];
	char key;
	
		*(character + 0) = '\0';
		do {
			key = _getch();
			if (i > 0 && key == 8) {
				std::cout << "\b \b";
				*(character + --i) = '\0';
			}
			else {
				if ((key >= 48 && key <= 57)) {
					std::cout << key;
					*(character + i++) = key;
				}
			}
		} while ((key != 13 || *(character + 0) == '\0') && i < number_character);
		*(character + i) = '\0';

		for (int i = 0; i < 10; i++) {
			num = *(character + i) - 48;
			*(digits + i) = num;
		}
		if (*(digits + 0) > 3) {
			std::cout << "\t Cedula no existe" << std::endl;;
		}
		else {
			for (i = 0; i < number_character - 1; i++) {
				number = *(digits + i);
				if ((i + 1) % 2 == 1) {
					number = *(digits + i) * 2;
					if (number > 9) {
						number = number - 9;
					}
				}
				adition = adition + number;
			}
			adition = 10 - (adition % 10);
			if (adition == *(digits + 9)) {
				std::cout << "\t Cedula valida " << std::endl;
				repeat = false;
			}
			else {
				std::cout << "\t La cedula  no existe" << std::endl;
				std::cout << "\n Ingrese de nuevo: ";
				repeat = true;
			}
		}
	} while (repeat);
	return;
}

int Operation::input_number(int value) {
	char dimension[5];
	int operation = 0, lenght = 0, number = 0;
	std::cout << "Ingrese un numero con " << value << " digitos: ";
	do {
		val.integer(dimension, value);
		number = atoi(dimension);
		lenght = digits(number);
		if (lenght != value) {
			std::cout << "\nEl numero ingresado solo tiene " << lenght << " digitos" << std::endl;
			std::cout << "Ingrese otro numero: ";
		}
	} while (lenght != value);
	return number;
}

int Operation::plus(int number, int id[11], int size) {
	int* data = data_expand(number, id);
	int sum = 0;
	for (int s = size - 1; s >= 0; s--) {
		sum += data[s];
	}
	return sum;
}