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
//#include "Cola.h"
#include "Queues.h"
#include "Utils.h"
using namespace Utils;

class Process
{
private:
	Queues<int>* client = new Queues<int>;
	Queues<int>* time_wait = new Queues<int>;
	Queues<int>* time_arrival = new Queues<int>;
	Queues<int>* time_notworking = new Queues<int>;
	Queues<int>* time_service = new Queues<int>;
	Queues<int>* time_out = new Queues<int>;
	Queues<int>* time_between = new Queues<int>;
	/*Cola* client = new Cola;
	Cola* time_arrival = new Cola;
	Cola* time_wait = new Cola;
	Cola* time_notworking = new Cola;
	Cola* time_service = new Cola;
	Cola* time_out = new Cola;
	Cola* time_between = new Cola;*/

	int size = 0;
public:

	/**
	* @brief Elimina el primer valor
	*
	* @param
	*
	* @return
	*/
	void pop();


	/**
	* @brief Es lo que hace funcionar todas las colas
	*
	* @param lenght es el numero de clientes a ser atendidos uwu
	*
	* @return
	*/
	void calculate_all(int);

	/**
	* @brief Calcular cliente
	*
	* @param 
	*
	* @return
	*/
	void calculate_client();

	/**
	* @brief Calcular tiempo de llegada
	*
	* @param
	*
	* @return
	*/
	void calculate_time_arrival();

	/**
	* @brief Calcular tiempo de espera
	*
	* @param
	*
	* @return
	*/
	void calculate_time_wait();

	/**
	* @brief Calcular tiempo de no trabjo del cajero
	*
	* @param
	*
	* @return
	*/
	void calculate_time_notworking();

	/**
	* @brief Calcular tiempo de servicio
	*
	* @param
	*
	* @return
	*/
	void calculate_time_service();

	/**
	* @brief Calcular tiempo de salida
	*
	* @param
	*
	* @return
	*/
	void calculate_time_out();

	/**
	* @brief Calcular tiempo de entre llegada 
	*
	* @param
	*
	* @return
	*/
	void calculate_time_between(int);

	/**
	* @brief Imprime todos los promedios de cada una de las colas
	*
	* @param
	*
	* @return
	*/
	void print_total();

	/**
	* @brief Imprimir todas colas en forma de tabla :)
	*
	* @param
	*
	* @return
	*/
	void print_table(int);

	/**
	* @brief Getter time_client
	*
	* @param
	*
	* @return Cola*
	*/
	Queues<int>* get_time_client();

	/**
	* @brief Getter time_arrival
	*
	* @param
	*
	* @return Cola*
	*/
	Queues<int>* get_time_arrival();

	/**
	* @brief Getter time_wait
	*
	* @param
	*
	* @return Cola*
	*/
	Queues<int>* get_time_wait();

	/**
	* @brief Getter time_notworking
	*
	* @param
	*
	* @return Cola*
	*/
	Queues<int>* get_time_notworking();

	/**
	* @brief Getter time_service
	*
	* @param
	*
	* @return Cola*
	*/
	Queues<int>* get_time_service();

	/**
	* @brief Getter time_out
	*
	* @param
	*
	* @return Cola*
	*/
	Queues<int>* get_time_out();

	/**
	* @brief Getter time_between
	*
	* @param
	*
	* @return Cola*
	*/
	Queues<int>* get_time_between();
};

