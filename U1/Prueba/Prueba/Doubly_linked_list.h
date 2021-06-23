#pragma once
#include "Nodo.h"
#include "Operation.h"
#include<functional>
using namespace std;

template <class T>
class Doubly_linked_list
{
public:
	Doubly_linked_list() = default;
	void insert_start(T);
	void print(std::function<void(int, int)>callback);
	void insert_end(T);
	void insert_between(T);
	void delete_element(T);
	void delete_first();
	void modified();
	void modified_input(T, T);
	void delete_last();
	bool empty();
	void modified_change(T);
	void print();
	//~Linked_list();
private:
	Nodo<T>* last();
	Nodo<T>* first = nullptr;
	int size = 0;
	Operation op;
};

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

}

template <class T>
void Doubly_linked_list<T>::insert_between(T value) {
	Nodo<T>* new_nodo = new Nodo<T>(value);
	if (first == nullptr) {
		this->first = new_nodo;
		size++;
		return;
	}
	Nodo<T>* last_nodo = last();
	last_nodo->set_next(new_nodo);
	new_nodo->set_last(last_nodo);
}

template <class T>
void Doubly_linked_list<T>::delete_element(T value) {
	Nodo<T>* tmp = first;
	if (value == 1) {
		first = tmp->get_next();
		return;
	}
	for (int i = 0; i < value - 2; i++)
		tmp = tmp->get_next();
	Nodo<T>* tmp1 = tmp->get_next();
	tmp->set_next(tmp1->get_next());
}

template <class T>
void Doubly_linked_list<T>::delete_first() {
	Nodo<T>* tmp;
	if (first == nullptr)
		return;
	tmp = first;
	first = first->get_next();
	first->set_last(0);
}

template <class T>
void Doubly_linked_list<T>::delete_last() {
	Nodo<T>* tmp;
	if (last() == nullptr)
		return;
	else {
		tmp = last();
		last()->set_last(last()->get_next());
		last() = last()->get_last();
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
		cout<<tmp->get_data()<<" ->";
		tmp = tmp->get_next();
	}
}

template <class T>
void Doubly_linked_list<T>::modified() {
	Nodo<T>* tmp = first;
	bool find = false;
	int nodo_search = 0;
	int number;
	cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cin >> nodo_search;
	if (first != NULL) {
		do {

			if (tmp->get_data() == nodo_search) {
				cout << "\n Nodo con el dato ( " << nodo_search << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cin >> number;
				tmp->set_data(number);
				tmp->get_data();
				cout << "\n Nodo Modificado\n\n";
				find = true;
			}

			tmp = tmp->get_next();

		} while (tmp != nullptr && find != true);

		if (!find) {
			cout << "\n Nodo no Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

template <class T> // dato a modificar, nuevo valor
void Doubly_linked_list<T>::modified_input(T nodo_search, T number) {
	Nodo<T>* tmp = first;
	bool find = false;
	//int nodo_search = 0;
	//cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cout << "Nodo a buscar: " << nodo_search;
	//cin >> nodo_search;
	if (first != NULL) {
		do {

			if (tmp->get_data() == nodo_search) {
				cout << "\n Nodo con el dato ( " << nodo_search << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cout << "\n Nuevo valor: "<< number;
				tmp->set_data(number);
				tmp->get_data();
				cout << "\n Nodo Modificado\n\n";
				find = true;
			}

			tmp = tmp->get_next();

		} while (tmp != nullptr && find != true);

		if (!find) {
			cout << "\n Nodo no Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

template <class T> // dato a modificar, nuevo valor
void Doubly_linked_list<T>::modified_change(T nodo_search) {
	Nodo<T>* tmp = first;
	bool find = false;
	//int nodo_search = 0;
	//cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cout << "Nodo a buscar: " << nodo_search;
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
							cout << "\n Nodo con el dato ( " << tmp->get_data() << " ) Encontrado";
							// tiene que quedar el otro 13 2
							if (s == 1 && j == 0) {
								tmp->set_data(data[2]);
							}
							tmp->set_data(data[0]);
							tmp->get_data();
							cout << "\n Nodo Modificado\n\n";
							//find = true;
						}						
					}
				}
			}
			tmp = tmp->get_next();

		} while (tmp != nullptr && find != true);
	}
	else {
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}



