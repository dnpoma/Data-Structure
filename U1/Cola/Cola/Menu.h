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
#include "Process.h"
#include "Screen.h"
#include "Utils.h"

using namespace Utils;


class Menu
{
private:
	Screen scrn;
public:
	void main_menu();
	void generate_table(int, Process);
};


