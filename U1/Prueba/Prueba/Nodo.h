#pragma once
template<class T>
class Nodo
{
public:
	Nodo(T);
	Nodo* get_next();
	void set_next(Nodo*);
	Nodo* get_last();
	void set_last(Nodo*);
	T get_data();
	void set_data(T);
private:
	T data;
	Nodo* next = nullptr;
	Nodo* last = nullptr;
};


template <class T>
Nodo<T>::Nodo(T _data) {
	this->data = _data;
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
Nodo<T>* Nodo<T>::get_last() {
	return last;
}

template <class T>
void Nodo<T>::set_last(Nodo* _last) {
	this->last = _last;
}


template <class T>
T Nodo<T>::get_data() {
	return data;
}

template <class T>
void Nodo<T>::set_data(T _data) {
	this->data = _data;
}