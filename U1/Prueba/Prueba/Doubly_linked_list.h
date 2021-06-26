#pragma once
#include "Nodo.h"
#include "Operation.h"
#include <functional>

template <class T>
class Doubly_linked_list
{
public:
	Doubly_linked_list() = default;
	void insert_start(T);
	void print();
	void print(std::function<void(int, int)>callback);
	void insert_end(T);
	void insert_between(int, T);
	void delete_element(int);
	void delete_first();
	void modified();
	void modified_input(T, T);
	void delete_last();
	void modified_change(T);
	T search(T);
	void empty();
		//void print();
		//~Linked_list();
private:
	Nodo<T>* first = nullptr;
	Nodo<T>* last();
	int size = 0;
	Operation op;
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
void Doubly_linked_list<T>::print() {
	Nodo<T>* tmp = first;
	while (tmp->get_next() != nullptr) {
		std::cout << tmp->get_data() << " ->";
		tmp = tmp->get_next();
	}
}

template <class T>
void Doubly_linked_list<T>::print(std::function<void(int, int)>callback) {
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



template <class T> // dato a modificar, nuevo valor
void Doubly_linked_list<T>::modified_input(T nodo_search, T number) {
	Nodo<T>* tmp = first;
	bool find = false;
	//int nodo_search = 0;
	//cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	std::cout << "Nodo a buscar: " << nodo_search;
	//cin >> nodo_search;
	if (first != NULL) {
		do {

			if (tmp->get_data() == nodo_search) {
				std::cout << "\n Nodo con el dato ( " << nodo_search << " ) Encontrado";
				std::cout << "\n Ingrese el nuevo dato para este Nodo: ";
				std::cout << "\n Nuevo valor: " << number;
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

template <class T> // dato a modificar, nuevo valor
void Doubly_linked_list<T>::modified_change(T nodo_search) {
	Nodo<T>* tmp = first;
	bool find = false;
	//int nodo_search = 0;
	//std::cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	std::cout << "Nodo a buscar: " << nodo_search;
	//cin >> nodo_search;
	if (first != NULL) {
		do {
			int value_digits[3];
			int number = tmp->get_data();
			int* data = op.data_expand(number, value_digits);
			int i = (sizeof(data) / sizeof(data[0])) + 1;
			for (int s = i - 1; s >= 0; s--)
			{
				for (int j = i - 1; j >= 0; j--) {
					if ((s == 1 && j == 0) || (s == 2 && j == 1)) {
						number = data[s] * 10 + data[j];
						if (number == nodo_search) {
							std::cout << "\n Nodo con el dato ( " << tmp->get_data() << " ) Encontrado";
							// tiene que quedar el otro 13 2
							if (s == 1 && j == 0) {
								tmp->set_data(data[2]);
							}
							tmp->set_data(data[0]);
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



