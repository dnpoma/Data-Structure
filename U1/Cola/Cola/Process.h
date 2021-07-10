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
#include "Cola.h"
#include "Utils.h"
using namespace Utils;

class Process
{
private:
	Cola* client = new Cola;
	Cola* time_arrival = new Cola;
	Cola* time_wait = new Cola;
	Cola* time_notworking = new Cola;
	Cola* time_service = new Cola;
	Cola* time_out = new Cola;
	Cola* time_between = new Cola;

	int size = 0;
public:
	void push();
	void pop();
	void calculate_all(int);
	void calculate_client();
	void calculate_time_arrival();
	void calculate_time_wait();
	void calculate_time_notworking();
	void calculate_time_service();
	void calculate_time_out();
	void calculate_time_between(int);
	void print_total();
	void print_table(int);


	Cola* get_time_client();
	Cola* get_time_arrival();
	Cola* get_time_wait();
	Cola* get_time_notworking();
	Cola* get_time_service();
	Cola* get_time_out();
	Cola* get_time_between();
};

