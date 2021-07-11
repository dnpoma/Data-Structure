/*
* Universidd de las Fuerzas Armadas ESPE
* Carrera: Ingenier�a de Software
* Autores:
*
* Sebastian Alexander Zapata Zapata --- @sebastian771 --- L�der de Equipo
* Adriana Alejandra Vargas Aldas --- @adrivargas14
* Christopher Israel Loachamin Simbana --- @ciloachamin
* Mateo Nicol�s Andrade Penafiel --- @MateoNicolasAndrade
* Dayse Nicole Poma Aguilar --- @dnpoma
*
* Enunciado: La Universidad de las Fuerzas Armadas ESPE solicita a los estudinates
* de tercer nivel de la asignatura estructura de datos automatizar el proceso de
* ser atendido, donde se especifica el tiempo de llegada que es aleatorio,  el tiempo
* de espera, el tiempo que no trabaja el cajero el tiempo de servicio y el tiempo de
* salida.
*
* Fecha de creaci�n: 03/07/2021
* Fecha de modificaci�n: 03/07/2021
*
*/
#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>


#define kEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

class Screen {
public:
	void print_coordinates(short int, short int);
	void ajust_size();
	int print_menu(const char*, const char* [], int);
	void print_squart(int, int, int, int);
};