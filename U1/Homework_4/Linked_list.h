#pragma once
#include <iostream>
#include "Nodo.h"
template <class T>
class Linked_list
{
public:
	Linked_list();
	void insert_start(T);
	void insert_end(T);
	void print();
	void delete_element(T);
	void delete_first();
	void delete_last();
	bool empty();
	~Linked_list();
private:
	Nodo<T>* first;
	Nodo<T>* last;

};


template <class T>
Linked_list<T>::Linked_list() {
	this->first = nullptr;
	this->last = nullptr;
}

template<class T>
bool Linked_list<T>::empty() {
	return(this->first == nullptr);
}

template<class T>
Linked_list<T>::~Linked_list() {

}

template <class T>
void Linked_list<T>::insert_end(T value) {
	Nodo<T>* new_nodo = new Nodo<T>(value);
	if (empty()) {
		this->first = new_nodo;
		first->set_next(nullptr);
		last = new_nodo;
	}
	else {
		this->last->set_next(new_nodo);
		new_nodo->set_next(nullptr);
		last = new_nodo;
	}
	this->last = new_nodo;
}

template <class T>
void Linked_list<T>::insert_start(T value) {
	Nodo<T>* new_nodo = new Nodo<T>(value);
	Nodo<T>* fore = first;
	if (empty()) {
		this->first = new_nodo;
		//first->next = nullptr;
		first->set_next(nullptr);
		last = new_nodo;
	}
	else {
		new_nodo->set_next(first);
		first = new_nodo;
			//	while (fore) {
	//		if (new_nodo == last) {
	//			//first->next = new_nodo;
	//			first->set_next(new_nodo);
	//		}
	//		fore = new_nodo;
	//		new_nodo = new_nodo->get_next();
	//	}
	}
}

template <class T>
void Linked_list<T>::print() {
	Nodo<T>* tmp = this->first;
	while(tmp)
	{
		std::cout << tmp->get_data() << " -> ";
		tmp = tmp->get_next();
	}
	std::cout << "NULL\n";
}

template <class T>
void Linked_list<T>::delete_element(T delete_nodo) {
	if (!empty()) {
		Nodo<T>* search = this->first;
		Nodo<T>* fore = nullptr;
		bool modified = false;
		while (search!=nullptr && modified!=true)
		{
			if (search->get_data() == delete_nodo) {
				std::cout << "Dato buscado encontrado:" << std::endl;

				if (search == first) {
					first = first->get_next();
				}
				else if (search == last) {
					fore->set_next(nullptr);
					last = fore;
				}
				else {
					last->set_next(search->get_next());
				}
				std::cout << "El nodo ha sido modificado" << std::endl;
				modified = true;
			}
			fore = search;
			search = search->get_next();
		}
		if (!modified) {
			std::cout << "No existe el nodo" << std::endl;
		}
	}
	else if (empty()) {
		std::cout << "Lista vacia" << std::endl;
	}
}

template <class T>
void Linked_list<T>::delete_first() {
	Nodo<T>* actually = this->first;
	Nodo<T>* fore = nullptr;
	if (!empty()) {
		first = first->get_next();
		fore = actually;
		actually = actually->get_next();
	}

}


template <class T>
void Linked_list<T>::delete_last() {
	Nodo<T>* actually = this->first;
	Nodo<T>* fore = nullptr;
	if (!empty()) {
		while (actually != nullptr) {
			if (actually == last) {
				fore->set_next(nullptr);
				last = fore;
			}
			fore = actually;
			actually = actually->get_next();
		}
	}
}