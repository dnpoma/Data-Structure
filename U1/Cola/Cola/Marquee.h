/*
* Universidd de las Fuerzas Armadas ESPE
* Carrera: Ingeniería de Software
* Autores:
*
* Sebastian Alexander Zapata Zapata --- @sebastian771 --- Líder de Equipo
* Adriana Alejandra Vargas Aldas --- @adrivargas14
* Christopher Israel Loachamin Simbana --- @ciloachamin
* Mateo Nicolás Andrade Penafiel --- @MateoNicolasAndrade
* Dayse Nicole Poma Aguilar --- @dnpoma
*
* Enunciado: La Universidad de las Fuerzas Armadas ESPE solicita a los estudinates
* de tercer nivel de la asignatura estructura de datos automatizar el proceso de
* ser atendido, donde se especifica el tiempo de llegada que es aleatorio,  el tiempo
* de espera, el tiempo que no trabaja el cajero el tiempo de servicio y el tiempo de
* salida.
*
* Fecha de creación: 03/07/2021
* Fecha de modificación: 03/07/2021
*
*/
#pragma warning(disable : 4996)
#include <thread>
#include <iostream>
#include <Windows.h>
#include <string>
#include "Utils.h"

using namespace Utils;

class Marquee {
private:
	const char* content;
	int lenght;
	COORD coord = { 0,0 };
public:
	//Marquee() = default;
	Marquee(const char*, int);
	char* marquee(int);
	void print_to(int x, int y);
	void show();
	void animation();
};

Marquee::Marquee(const char* _content, int _lenght) {
	this->content = _content;
	this->lenght = _lenght;
}

char* Marquee::marquee(int position) {
	int counter = 0; 
	char* display = (char*)malloc(sizeof(char) * (lenght + 1));
	char* travel = (char*)malloc(sizeof(char) * 256);
	char* temp = (char*)malloc(sizeof(char) * (strlen(content) + 1));
	Utils::String::strcpy(travel, content);
	while (counter < position) {
		temp[counter] = travel[0];
		travel++;
		counter = counter + 1;
	}
	temp[counter + 1] = '\0';
	Utils::String::strcat(travel, " ");
	Utils::String::strcat(travel, temp);
	Utils::String::strncpy(display, travel, lenght);
	display[lenght] = '\0';
	return display;
}

void Marquee::show() {
	char* singboard;
	while (1) {
		for (int i = 0; i < lenght; i++) {
			singboard = marquee(i);
			print_to(20, 1); 
			std::cout << singboard;
			print_to(27, 3);
			std::cout<< std::endl;
			//delete(singboard);
			Sleep(600);
			//system("@cls||clear");
		}
	}
}

void Marquee::print_to(int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	fflush(stdout);
}

void Marquee::animation() {
	std::thread first(&Marquee::show, this);
	//system("pause");
	fflush(stdout);
	//first.join();
	first.detach();
}
//void Marquee::print() {
//	int lenght = content.length();
//	while (1) {
//		const char* format = content.c_str();
//		for (int i = 0; i < lenght; i++) {
//			char dest[1024 * 16];
//			va_list argptr;
//			va_start(argptr, format);
//			vsprintf(dest, format, argptr);
//			va_end(argptr);
//			printf("\n");
//		}
//	}
//}
