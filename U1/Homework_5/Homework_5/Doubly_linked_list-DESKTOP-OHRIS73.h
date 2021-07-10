#pragma once
#include "Nodo.h"
#include <functional>
#include <iostream>

template <class T>
class Doubly_linked_list
{
public:
	Doubly_linked_list() = default;
	void insert_start(T);
	void print(std::function<void(T, T)>callback);
	void insert_end(T);
	void insert_between(int, T);
	void delete_element(int);
	void delete_first();
	void delete_last();
	void modified();
	T search(T);
	void empty();
	//~Linked_list();
private:
	Nodo<T>* last();
	Nodo<T>* first = nullptr;
	int size = 0;
};

template <class T>
Nodo<T>* Doubly_linked_list<T>::last() {
	Nodo<T>* tmp = first;
	while (tmp->get_next() != nullptr) {
		tmp = tmp->get_next();
	}
	return tmp;
}

template <class T>
void Doubly_linked_list<T>::insert_end(T value){
	Nodo<T>* new_nodo = new Nodo<T>(value);
	if (first == nullptr) {
		this->first = new_nodo;
		size++;
		return;
	}
	Nodo<T>* last_nodo = last();
	last_nodo->set_next(new_nodo);
	new_nodo->set_last(last_nodo);
	size++;
}

template <class T>
void Doubly_linked_list<T>::insert_start(T value) {
	Nodo<T>* new_nodo = new Nodo<T>(value);
	if (first == nullptr) {
		this->first = new_nodo;
		size++;
		return;
	}
	first->set_last(new_nodo);
	new_nodo->set_next(first);
	first = new_nodo;
	size++;
}

template <class T>
void Doubly_linked_list<T>::insert_between(int index, T value) {
	if (index >= size || index < 0) {
		std::cout << "Indice fuera de la lista" << std::endl;
		return;
	}
	if (index == 0) {
		insert_start(value);
		return;
	}
	if (index == size - 1) {
		insert_end(value);
		return;
	}
	Nodo<T>* tmp = first;
	Nodo<T>* previus;
	Nodo<T>* new_nodo = new Nodo<T>(value);
	int index_ = 0;
	while (index != index_) {
		tmp = tmp->get_next();
		index_++;
	}
	previus = tmp->get_last();
	previus->set_next(new_nodo);
	tmp->set_last(previus);
	new_nodo->set_last(previus);
	new_nodo->set_next(tmp);
	size++;
}

template <class T>
void Doubly_linked_list<T>::delete_element(int index) {
	if (index >= size || index < 0) {
		std::cout << "Indice fuera de la lista" << std::endl;
		return;
	}
	if (index == 0) {
		delete_first();
		return;
	}
	if (index == size - 1) {
		delete_last();
		return;
	}
	Nodo<T>* tmp = first;
	Nodo<T>* previus;
	Nodo<T>* post_previus;
	int index_=0;
	while (index != index_) {
		tmp = tmp->get_next();
		index_++;
	}
	previus = tmp->get_last();
	post_previus = tmp->get_next();

	post_previus->set_last(previus);
	previus->set_next(post_previus);
	free(tmp);
	size--;
}

template <class T>
void Doubly_linked_list<T>::delete_first() {
	if (first == nullptr)
		return;
	if (size == 1) {
		free(first);
		first = nullptr;
		return;
	}
	Nodo<T>* tmp;
	tmp = first->get_next();
	tmp->set_last(nullptr);
	free(first);

	first = tmp;
	size--;
}

template <class T>
void Doubly_linked_list<T>::delete_last() {
	if (first == nullptr) {
		return;
	}
	if (size == 1) {
		free(first);
		first = nullptr;
		return;
	}
	Nodo<T>* tmp = first;
	Nodo<T>* last_ = last();
	while (tmp->get_next()->get_next() != nullptr) {
		tmp = tmp->get_next();
	}
	tmp->set_next(nullptr);
	free(last_);
	size--;
}

template <class T>
void Doubly_linked_list<T>::print(std::function<void(T, T)> callback) {
	Nodo<T>* tmp = first;
	int index = 0;
	while (tmp != nullptr) {
		callback(tmp->get_data(), index++);
		tmp = tmp->get_next();
	}  
}

template <class T>
T Doubly_linked_list<T>::search(T index) {
	if (index >= size || index < 0) {
		std::cout << "Indice fuera de la lista" << std::endl;
		return 0;
	}
	Nodo<T>* tmp = first;
	int index_=0;
	while (index != index_) {
		tmp = tmp->get_next();
		index_++;
	}
	return tmp->get_data();
}

template <class T>
void Doubly_linked_list<T>::modified() {
	Nodo<T>* tmp = first;
	bool find = false;
	int nodo_search = 0;
	int number;
	std::cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	std::cin >> nodo_search;
	if (first != NULL) {
		do {

			if (tmp->get_data() == nodo_search) {
				std::cout << "\n Nodo con el dato ( " << nodo_search << " ) Encontrado";
				std::cout << "\n Ingrese el nuevo dato para este Nodo: ";
				std::cin >> number;
				tmp->set_data(number);
				tmp->get_data();
				std::cout << "\n Nodo Modificado\n\n";
				find = true;
			}

			tmp = tmp->get_next();

		} while (tmp != nullptr && find != true);

		if (!find) {
			std::cout << "\n Nodo no Encontrado\n\n";
		}
	}
	else {
		std::cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

template <class T>
void Doubly_linked_list<T>::empty() {
	if (first == nullptr)
		std::cout << "Lista vacia";
}