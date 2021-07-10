#pragma once
#include <functional>
#include <iostream>
#include "Utils.h"

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


template <class T>
class Doubly_linked_list
{
public:
	Doubly_linked_list() = default;
	void insert_start(T);
	void print(std::function<void(std::string, int)>callback);
	void insert_end(T);
	void print();
	void insert_between(int, T);
	void delete_element(int);
	void delete_first();
	void delete_last();
	void modified();
	T search(T);
	void empty();
	bool search_email(std::string);
	void modified_change(int);
	void modified_input(std::string, std::string);
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
void Doubly_linked_list<T>::print() {
	Nodo<T>* tmp = first;
	while (tmp->get_next() != nullptr) {
		std::cout << tmp->get_data().get_id() << " " << tmp->get_data().get_name() << " ->";
		tmp = tmp->get_next();
	}
}

template <class T>
void Doubly_linked_list<T>::insert_end(T value) {
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
	int index_ = 0;
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
void Doubly_linked_list<T>::print(std::function<void(std::string, int)> callback) {
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
	int index_ = 0;
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

template <class T>
bool Doubly_linked_list<T>::search_email(std::string email) {
	bool validation = false;

	if (first != nullptr) {
		Nodo<T>* tmp = first;
		while (tmp->get_next() != nullptr) {
			if (email == tmp->get_data().get_email()) {
				validation = true;
			}
			tmp = tmp->get_next();
		}
	}
	return validation;
}

// dato a modificar, nuevo valor
template <class T>
void Doubly_linked_list<T>::modified_input(std::string nodo_search, std::string number) {
	Nodo<T>* tmp = first;
	bool find = false;
	//int nodo_search = 0;
	//cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	std::cout << "Nodo a buscar: " << nodo_search;
	//cin >> nodo_search;
	if (first != NULL) {
		do {
			if (tmp->get_data().get_id() == nodo_search) {
				std::cout << "\n Nodo con el dato ( " << nodo_search << " ) Encontrado";
				std::cout << "\n Ingrese el nuevo dato para este Nodo: ";
				std::cout << "\n Nuevo valor: " << number;
				//tmp->set_data(number);
				tmp->get_data().set_id(number);
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
// dato a modificar, nuevo valor
template <class T>
void Doubly_linked_list<T>::modified_change(int nodo_search) {
	Nodo<T>* tmp = first;
	bool find = false;
	//int nodo_search = 0;
	//cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	std::cout << "Nodo a buscar: " << nodo_search;
	//cin >> nodo_search;
	if (first != NULL) {
		do {
			int value_digits[3];
			int number = std::stoi(tmp->get_data().get_id());
			int* data = Utils::Validation::data_expand(number, value_digits);
			int i = (sizeof(data) / sizeof(data[0])) + 1;
			for (int s = i - 1; s >= 0; s--)
			{
				for (int j = i - 1; j >= 0; j--) {
					if ((s == 1 && j == 0) || (s == 2 && j == 1)) {
						number = data[s] * 10 + data[j];
						if (number == nodo_search) {
							std::cout << "\n Nodo con el dato ( " << tmp->get_data().get_id() << " ) Encontrado";
							// tiene que quedar el otro 13 2
							if (s == 1 && j == 0) {
								tmp->get_data().set_id(to_string(data[2]));
							}
							tmp->get_data().set_id(to_string(data[2]));
							tmp->get_data();
							std::cout << "\n Nodo Modificado\n\n";
							//find = true;
						}
					}
				}
			}
			tmp = tmp->get_next();

		} while (tmp != nullptr && find != true);
	}
	else {
		std::cout << "\n La lista se Encuentra Vacia\n\n";
	}
}