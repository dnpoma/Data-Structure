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
* Enunciado: Realice 15 métodos de ordenamiento
*
* Fecha de creación: 7/07/2021
* Fecha de modificación: 11/07/2021
*
*/

#pragma once
#include "Vector.h"
#include <functional>
#include <iostream>
class Operation
{
public: 
	/**
	* @brief generate_elements integer numbers	
	* Orden ascendenete
	*
	* @param Vector size
	*
	* @return
	*/
	void generate_elements(Vector<int>*, int);

	/**
	* @brief bubble_order integer numbers	
	* Orden ascendenete
	*
	* @param Vector size
	*
	* @return
	*/
	void bubble_order(Vector<int>*, int);

	/**
	* @brief exchange_order integer numbers
	* Orden ascendenete
	*
	* @param Vector size
	*
	* @return
	*/
	void exchange_order(Vector<int>*, int);

	/**
	* @brief shellsort_order integer numbers
	* Orden ascendenete
	* 
	* @param Vector size
	*
	* @return
	*/
	void shellsort_order(Vector<int>*, int);

	/**
	* @brief swap intercambia la posicion de los elementos
	* Orden ascendenete
	*
	* @param x , y
	*
	* @return
	*/
	void swap(int&, int&);


	void print(Vector<int>*, int);
	//void print(Vector<int>*,int,std::function<void(int, int)>callback);
};

