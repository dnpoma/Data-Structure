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

#pragma once
#include "Nodo.h"
#include <Functional>

class Cola
{
private:
	Nodo* front;
	Nodo* rear;
public:
	Cola();
	~Cola();
	int get_front();
	int get_rear();
	void push(int);
	void pop();
	void display();
	bool empty();
	float avarage();
	void calculate(std::function<void(int, int)>callback);
};

