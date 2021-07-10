#pragma once
#include <iostream>
template <class T>
class Node {
public:
	Node(T);
	Node* get_next();
	void set_next(Node*);
	Node* get_last();
	void set_last(Node*);
	T get_data();
	void set_data(T);
private:
	T data;
	Node* next = nullptr;
	Node* last = nullptr;
};

template <class T>
Node<T>::Node(T _data) {
	this->data = _data;
}

template <class T>
Node<T>* Node<T>::get_next() {
	return next;
}

template <class T>
void Node<T>::set_next(Node* _next) {
	this->next = _next;
}

template <class T>
Node<T>* Node<T>::get_last() {
	return last;
}

template <class T>
void Node<T>::set_last(Node* _last) {
	this->last = _last;
}


template <class T>
T Node<T>::get_data() {
	return data;
}

template <class T>
void Node<T>::set_data(T _data) {
	this->data = _data;
}

template <class T>
class Circular_Linked_List {
public:
	Circular_Linked_List();
	void search_data(T);
	Node<T>* search(T);
	void append(T);
	void prependNode(T);
	void insertNodeAfter(T, T);
	void deleteNodeByKey(T);
	void update(T, T);
	void print();
private:
	Node<T>* head;
};


template <class T>
Circular_Linked_List<T>::Circular_Linked_List() {
	head = nullptr;
}

template <class T>
void Circular_Linked_List<T>::search_data(T _value) {
	Node<T>* ptr = search(_value);
	if (ptr != nullptr) {
		std::cout << "Nodo encontrado: " << ptr->get_data() << std::endl;
	}
	else {
		std::cout << "Nodo no encontrado: " << _value << std::endl;
	}
}

// Verificar si un nodo existe con esa key existe y retorna el dato
template <class T>
Node<T>* Circular_Linked_List<T>::search(T _data) {
	Node<T>* tmp = nullptr;
	Node<T>* ptr = head;
	if (ptr == nullptr) {
		return tmp;
	}
	else {
		do {
			if (ptr->get_data() == _data) {
				tmp = ptr;
			}
			ptr = ptr->get_next();
		} while (ptr != head);
		return tmp;
	}
}

//Insertar un nodo en la cola uwu
template <class T>
void Circular_Linked_List<T>::append(T value) {
	Node<T>* new_nodo = new Node<T>(value);
	if (head == nullptr) {
		head = new_nodo;
		new_nodo->set_next(head);
	}
	else {
		Node<T>* ptr = head;
		while (ptr->get_next() != head) {
			ptr = ptr->get_next();
		}
		ptr->set_next(new_nodo);
		new_nodo->set_next(head);
	}
}

//por la cabeza
template <class T>
void Circular_Linked_List<T>::prependNode(T value) {
	Node<T>* new_nodo = new Node<T>(value);
	if (head == nullptr) {
		head = new_nodo;
		new_nodo->set_next(head);
	}
	else {
		Node<T>* ptr = head;
		while (ptr->get_next() != head) {
			ptr = ptr->get_next();
		}
		ptr->set_next(new_nodo);
		new_nodo->set_next(head);
		head = new_nodo;
	}
}
//Insertar despues de key....
template <class T>
void Circular_Linked_List<T>::insertNodeAfter(T _key, T value) {
	Node<T>* new_nodo = new Node<T>(value);
	Node<T>* ptr = search(_key);
	if (ptr == nullptr) {
		std::cout << "No existe el nodo: " << _key << std::endl;
	}
	else {
		if (ptr->get_next() == head) {
			new_nodo->set_next(head);
			ptr->set_next(new_nodo);
		}
		else {
			new_nodo->set_next(ptr->get_next());
			ptr->set_next(new_nodo);
		}
	}
}

template <class T>
void Circular_Linked_List<T>::deleteNodeByKey(T _key) {
	Node<T>* ptr = search(_key);
	if (ptr == nullptr) {
		std::cout << "No existe el nodo: " << _key << std::endl;
	}
	else {
		if (ptr == head) {
			if (head->get_next() == nullptr) {
				head = nullptr;
			}
			else {
				Node<T>* tmp = head;
				while (tmp->get_next() != head) {
					tmp = tmp->get_next();
				}
				tmp->set_next(head->get_next());
				head = head->get_next();
			}
		}
		else {
			Node<T>* tmp = nullptr;
			Node<T>* prev = head;
			Node<T>* current = head->get_next();
			while (current != nullptr) {
				if (current->get_data() == _key) {
					tmp = current;
					current = nullptr;
				}
				else {
					prev = prev->get_next();
					current = current->get_next();
				}
			}
			prev->set_next(tmp->get_next());
			std::cout << "Node unliked: " << _key << std::endl;
		}
	}
}

template <class T>
void Circular_Linked_List<T>::update(T _key, T new_data) {
	Node<T>* ptr = search(_key);
	if (ptr != nullptr) {
		ptr->set_data(new_data);
		std::cout << "Node se actualizo correctamente" << std::endl;
	}
	else {
		std::cout << "No existe el nodo: " << _key << std::endl;
	}
}

template <class T>
void Circular_Linked_List<T>::print() {
	int i = 1;
	if (head == nullptr) {
		std::cout << "No hay nodos registrados" << std::endl;
	}
	else {
		std::cout << "Circulas Linkend List Values <3.<3" << std::endl;
		std::cout << "Key\tData" << std::endl;
		Node<T>* tmp = head;
		do {
			std::cout << i++ << "\t" << tmp->get_data() << std::endl;
			tmp = tmp->get_next();
		} while (tmp != head);
	}
}