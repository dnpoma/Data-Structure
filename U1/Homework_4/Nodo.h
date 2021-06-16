#pragma once
template<class T>
class Nodo
{
public:
	Nodo();
	Nodo(T, Nodo* next = nullptr);
	Nodo* get_next();
	void set_next(Nodo*);
	T get_data();
	void set_data(T);
private:
	T data;
	Nodo* next;
};

//#include "Nodo.h"
template <class T>
Nodo<T>::Nodo()
{
	data = nullptr;
	next = nullptr;
}

template <class T>
Nodo<T>::Nodo(T _data, Nodo* _next) {
	data = _data;
	next = _next;
}

template <class T>
Nodo<T>* Nodo<T>::get_next() {
	return next;
}

template <class T>
void Nodo<T>::set_next(Nodo* _next) {
	this->next = _next;
}

template <class T>
T Nodo<T>::get_data() {
	return data;
}

template <class T>
void Nodo<T>::set_data(T _data) {
	this->data = _data;
}
