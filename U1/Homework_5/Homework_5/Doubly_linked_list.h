#pragma once
#include "Nodo.h"
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
	void delete_last();
	bool empty();
	//~Linked_list();
private:
	Nodo<T>* last();
	Nodo<T>* first = nullptr;
	int size = 0;
};

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
	for (int i = 0; i < value-2; i++) 
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