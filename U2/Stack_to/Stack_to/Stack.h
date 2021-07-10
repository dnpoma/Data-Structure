#pragma once
#include <iostream>

//Clase Nodo con templetes

template <class T>
class Nodo
{
private:
	T data;
	Nodo<T>* next;
public:
	/**
	 * @brief Construct a new Nodo< T> object
	 *
	 */
	Nodo<T>(T, Nodo<T>* next = nullptr);

	/**
	 * @brief Get the data object
	 *
	 * @return T
	 */
	T get_data();

	/**
	 * @brief Set the data object
	 *
	 */
	void set_data(T);

	/**
	 * @brief Get the next object
	 *
	 * @return Nodo<T>*
	 */
	Nodo<T>* get_next();

	/**
	 * @brief Set the next object
	 *
	 */
	void set_next(Nodo<T>*);
};

template<class T>
Nodo<T>::Nodo(T _data, Nodo<T>* _next)
{
	this->data = _data;
	this->next = _next;
}

template<class T>
T Nodo<T>::get_data()
{
	return this->data;
}

template<class T>
void Nodo<T>::set_data(T _data)
{
	this->data = _data;
}


template<class T>
Nodo<T>* Nodo<T>::get_next()
{
	return this->next;
}

template<class T>
void Nodo<T>::set_next(Nodo<T>* _new_nodo)
{
	this->next = _new_nodo;
}



//
// Clase Stack con templates :)
//

template <class T>
class Stack
{
private:
	Nodo<T>* first;
	Nodo<T>* now;
public:

	/**
	 * @brief Comprobar pila vacia
	 *
	 * @return true
	 * @return false
	 */
	bool empty_stack();

	/**
	 * @brief Construct a new Stack< T> object
	 *
	 */
	Stack<T>();

	/**
	 * @brief insertar por cola
	 *
	 */
	void insert_rear(T);

	/**
	 * @brief Set the first object
	 *
	 */
	void set_first(Nodo<T>*);

	/**
	 * @brief Get the first object
	 *
	 * @return Nodo<T>*
	 */
	Nodo<T>* get_first();

	/**
	 * @brief Set the now object
	 *
	 */
	void set_now(Nodo<T>*);

	/**
	 * @brief Get the now object
	 *
	 * @return Nodo<T>*
	 */
	Nodo<T>* get_now();

	/**
	 * @brief Insertar por cabezas
	 *
	 */
	void insert_front(T);

	/**
	 * @brief Borrar por cola
	 *
	 */
	void delete_rear();

	/**
	 * @brief Borrar por cabeza
	 *
	 */
	void delete_front();

	/**
	 * @brief show
	 *
	 */
	void show();

	/**
	 * @brief Ver Expresion
	 *
	 */
	void show_expression();

	/**
	 * @brief show Expresion Invetida
	 *
	 */
	void show_expression_inverted();

	/**
	 * @brief Llenar lista aleatorio
	 *
	 */
	void fill_random();

	/**
	 * @brief Vaciar Lista
	 *
	 */
	void clear_stack();

	/**
	 * @brief MCD
	 *
	 * @return T
	 */
	T maximo_comun_divisor(T);

	/**
	 * @brief Contar elementos
	 *
	 * @return T
	 */
	T count_elements();

};

template<class T>
void Stack<T>::show()
{
	Nodo<T>* temporal = this->first;
	while (temporal) {
		std::cout << temporal->get_data() << " " << std::endl;
		temporal = temporal->get_next();

	}
	std::cout << std::endl;
}

template<class T>
void Stack<T>::show_expression()
{
	Nodo<T>* temporal = this->first;
	while (temporal) {
		std::cout << temporal->get_data() << " ";
		temporal = temporal->get_next();

	}
	std::cout << std::endl;
}

template<class T>
void Stack<T>::show_expression_inverted()
{
	Stack<T> copia;
	Nodo<T>* temporal = this->first;
	while (temporal) {
		copia.insert_front(temporal->get_data());
		temporal = temporal->get_next();

	}
	temporal = copia.get_first();
	while (temporal) {
		std::cout << temporal->get_data() << " ";
		temporal = temporal->get_next();

	}
	std::cout << std::endl;
}

template<class T>
void Stack<T>::clear_stack() {
	while (empty_stack()) {
		delete_rear();
	}
}

template<class T>
bool Stack<T>::empty_stack()
{
	return (this->first == NULL);
}

template<class T>
Stack<T>::Stack()
{
	this->first = NULL;
	this->now = NULL;
}

template<class T>
void Stack<T>::insert_rear(T val)
{
	Nodo<T>* nuevo = new Nodo<T>(val, NULL);
	if (empty_stack()) {
		this->first = nuevo;
	}
	else {
		this->now->set_next(nuevo);
	}
	this->now = nuevo;
}

template<class T>
void Stack<T>::set_first(Nodo<T>* new_first) {
	this->first = new_first;
}

template<class T>
Nodo<T>* Stack<T>::get_first() {
	return first;
}

template<class T>
void Stack<T>::set_now(Nodo<T>* new_now) {
	this->now = new_now;
}

template<class T>
Nodo<T>* Stack<T>::get_now() {
	return now;
}

template<class T>
void Stack<T>::insert_front(T val)
{
	Nodo<T>* nuevo = new Nodo<T>(val, NULL);

	if (empty_stack()) {
		this->now = nuevo;
	}
	else {
		nuevo->set_next(this->first);
	}
	this->first = nuevo;
}

template<class T>
void Stack<T>::delete_rear()
{
	if (!empty_stack()) {
		Nodo<T>* temp = this->now;
		Nodo<T>* temp1 = this->first;
		while (temp1->get_next()->get_next() != nullptr) {
			temp1 = temp1->get_next();
		}
		temp1->set_next(nullptr);
		this->now = temp1;
		free(temp);
	}
}

template<class T>
void Stack<T>::delete_front()
{
	if (!empty_stack()) {
		Nodo<T>* temp;
		temp = this->first;
		this->first = this->first->get_next();
		free(temp);
	}
}

template<class T>
void Stack<T>::fill_random()
{
	Nodo<T>* temp = this->first;
	std::srand(std::time(nullptr));
	int aleatorio = 0;
	while (aleatorio != 5) {
		aleatorio = 1 + rand() % (6);
		if (aleatorio == 2 || aleatorio == 4) {
			insert_rear(aleatorio);
		}
	}
}

template<class T>
T Stack<T>::maximo_comun_divisor(T elementos)
{
	int mcd = 0;
	int contador = 0;
	Nodo<T>* temporal = this->first;
	for (int i = 1; i < 1000; i++) {
		contador = 0;
		temporal = this->first;
		while (temporal) {

			if (temporal->get_data() % i == 0) {

				contador = contador + 1;
			}
			temporal = temporal->get_next();
		}
		if (elementos == contador) {
			mcd = i;
		}
	}
	return T(mcd);
}


template<class T>
T Stack<T>::count_elements()
{
	int elementos = 0;
	Nodo<T>* temporal = this->first;
	while (temporal) {
		elementos = elementos + 1;
		temporal = temporal->get_next();
	}
	return T(elementos);
}
