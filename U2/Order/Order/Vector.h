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
#include <iostream>
#include <functional>
template <class T>
class Vector
{
private:
	T* array = new T[100];
	//int* array;
public:
	Vector() = default;
	Vector(T*);
	void set_vector(T*);
	T* get_vector();
	void print(int,std::function<void(int, int)>callback);
};

/**
* @brief Constructor
*
* @param T* _array 
*
* @return
*/
template <class T>
Vector<T>::Vector(T* _array) {
	array = _array;
}

/**
* @brief set_vector
*
* @param T* _array
*
* @return
*/
template <class T>
void Vector<T>::set_vector(T* _array) {
	array = _array;
}

/**
* @brief get_vector
*
* @param 
*
* @return T array
*/
template <class T>
T* Vector<T>::get_vector() {
	return array;
}

/**
* @brief print
*
* @param T size and function
*
* @return
*/
template <class T>
void Vector<T>::print(int size, std::function<void(int, int)>callback) {
	for (int i = 0; i < size; i++) {
		std::cout << *(get_vector() + i) << std::endl;
	}
}