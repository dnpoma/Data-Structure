#include "Menu.h"


#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <windows.h>


#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

using namespace std;

void Menu::gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void Menu::menu_principal() {
	bool repeat = true;
	int opcion, number;
	char dimension[5];
	const char* title = "---Lista enlazada simple---";
	const char* option_menu[] = { "Insertar cabeza","Insertar cola", "Imprimir", 
		"Eliminar elemento", "Eliminar el primero elemento","Eliminar el ultimo elemento"
		, "SALIR"};
	int number_option = 7; //Número de opciones
	do {
		opcion = menu(title, option_menu, number_option);
		//Alternativas
		switch (opcion) {
		case 1:
			system("cls");
			std::cout << "Ingrese un dato : ";
			val.natural_numbers(dimension);
			number = atoi(dimension);
			lst.insert_start(number);
			cout << "\n";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "Ingrese un dato : ";
			val.natural_numbers(dimension);
			number = atoi(dimension);
			lst.insert_end(number);
			cout << "\n";
			system("pause");
			break;

		case 3:
			system("cls");
			std::cout << "Imprimir ";
			lst.print();
			cout << "\n";
			system("pause");
			break;

		case 4:
			system("cls");
			std::cout << "Eliminar elemento: ";
			val.natural_numbers(dimension);
			number = atoi(dimension);
			lst.delete_element(number);
			cout << "\n Se elimino correctamente el elemento\n" << endl;
			system("pause");
			break;

		case 5:
			system("cls");
			std::cout << "Eliminar primer elemento";
			lst.delete_first();
			cout << "\n Se elimino correctamente el elemento\n" << endl;
			system("pause");
			break;

		case 6: 
			system("cls");
			std::cout << "Eliminar ultimo elemento ";
			lst.delete_last();
			cout << "\n Se elimino correctamente el elemento\n" << endl;
			system("pause");
			break;

		case 7:
			repeat = false;
			system("cls");
			cout << "\n Gracias por usar el programa! :)\n" << endl;
			exit(0);
			break;
		}
	} while (repeat);
}

int Menu::menu(const char* title, const char* option_menu[], int number_option)
{
	int selected_option = 1;
	int key;
	bool repeat = true;

	do {
		system("cls");
		gotoxy(5, 3 + selected_option); cout << ">>>";
		gotoxy(15, 2); cout << title;//Imprime el título	

		for (int i = 0; i < number_option; i++) {   //Imprime las opciones
			gotoxy(10, 4 + i); cout << i + 1 << ") " << option_menu[i];
		}
		do {
			key = _getch();
		} while (key != TECLA_ARRIBA && key != TECLA_ABAJO && key != ENTER);
		switch (key) {
		case TECLA_ARRIBA:
			selected_option--;
			if (selected_option < 1) {
				selected_option = number_option;
			}
			break;
		case TECLA_ABAJO:
			selected_option++;
			if (selected_option > number_option) {
				selected_option = 1;
			}
			break;
		case ENTER:
			repeat = false;
			break;
		}
	} while (repeat);

	return selected_option;
}

