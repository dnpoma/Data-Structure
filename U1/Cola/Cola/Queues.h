/*
* Universidd de las Fuerzas Armadas ESPE
* Carrera: Ingeniería de Software
* Autores:
*
* Sebastian Alexander Zapata Zapata --- @sebastian771 --- Líder de Equipo
* Adriana Alejandra Vargas Aldas --- @adrivargas14
* Christopher Israel Loachamin Simbana --- @ciloachamin
* Mateo Nicolás Andrade Penafiel --- @MateoNiQueuessAndrade
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

#include <functional>
#include <iostream>
#pragma once
template <class T>
class Nodo
{
private:
	T data;
	Nodo* next;
public:
	Nodo(T, Nodo* next = nullptr);
	T get_data();
	Nodo* get_next();
	void set_next(Nodo*);
	void set_data(T);
};

template <class T>
Nodo<T>::Nodo(T _data, Nodo<T>* _next) {
	data = _data;
	next = _next;
}

template <class T>
T Nodo<T>::get_data() {
	return data;
}

template <class T>
Nodo<T>* Nodo<T>::get_next() {
	return next;
}

template <class T>
void Nodo<T>::set_next(Nodo<T>* _next) {
	this->next = _next;
}

template <class T>
void Nodo<T>::set_data(T _data) {
	this->data = _data;
}

template <class T>
class Queues
{
private:
	Nodo<T>* front;
	Nodo<T>* rear;
public:
	Queues();
	~Queues();
	T get_front();
	T get_rear();
	void push(T);
	void pop();
	void display();
	bool empty();
	float avarage();
	void calculate(std::function<void(T, int)>callback);
};

template <class T>
Queues<T>::Queues() {
	this->front = nullptr;
	this->rear = nullptr;
}

template <class T>
Queues<T>::~Queues() {}

template <class T>
T Queues<T>::get_front() {
	return front->get_data();
}

/**
 * @brief get_rear
 * @return rear->get_data()
 * 
 */
template <class T>
T Queues<T>::get_rear() {
	return rear->get_data();
}

/**
 * @brief empty
 * 
 */
template <class T>
bool Queues<T>::empty() {
	return(this->front == nullptr && this->rear == nullptr);
}

/**
 * @brief push
 * 
 */
template <class T>
void Queues<T>::push(T data) {
	Nodo<T>* new_nodo = new Nodo<T>(data);
	if (empty()) {
		front = rear = new_nodo;
	}
	else {
		rear->set_next(new_nodo);
		rear = new_nodo;
	}
}

/**
 * @brief display
 * 
 */
template <class T>
void Queues<T>::display() {
	Nodo<T>* tmp;
	if (empty()) {
		std::cout << "Cola vacia" << std::endl;
	}
	else {
		tmp = this->front;
		while (tmp != nullptr) {
			std::cout << tmp->get_data() << std::endl;
			tmp = tmp->get_next();
		}
	}
}

/**
 * @brief pop
 */
template <class T>
void Queues<T>::pop() {
	Nodo<T>* tmp = this->front;
	if (!empty()) {
		front = front->get_next();
		free(tmp);
	}
}

/**
 * @brief calculate
 * @param function
 * @param callback
 */
template <class T>
void Queues<T>::calculate(std::function<void(T, int)>callback) {
	Nodo<T>* tmp = this->front;
	int i = 0;
	while (tmp != nullptr) {
		callback(tmp->get_data(), i++);
		tmp = tmp->get_next();
	}
}

/**
 * @brief queues
 * @return plus/i
 */
template <class T>
float Queues<T>::avarage() {
	Nodo<T>* tmp;
	float plus = 0;
	int i = 0;
	if (empty()) {
		std::cout << "Cola vacia" << std::endl;
	}
	else {
		tmp = this->front;
		while (tmp != nullptr) {
			i++;
			plus += tmp->get_data();
			tmp = tmp->get_next();
		}
		return (plus / i);
	}
}
