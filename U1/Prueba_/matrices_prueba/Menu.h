#pragma once
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "Operation.h"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

using namespace std;
Operation operation;
int menu(const char* titulo, const char* opciones[], int n);

void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void menu_principal() {
	bool repeat = true;
	int opcion;
	const char* title = "---MATRIZ---";
	const char* option_menu[] = { "Ingresar matriz", "SALIR" };
	int number_option = 2; //Número de opciones
	do {
		opcion = menu(title, option_menu, number_option);
		//Alternativas
		switch (opcion) {
		case 1:
			system("cls");
			operation.enter_data();
			system("pause");
			break;
		case 2:
			repeat = false;
			system("cls");
			cout << "\n Gracias por usar el programa! :)" << endl;
			exit(0);
			break;
		}
	} while (repeat);
}

int menu(const char* title, const char* option_menu[], int number_option)
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