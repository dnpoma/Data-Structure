#pragma once
template <class T>
class Node {
public:
	Node(T);
	int get_key();
	void set_key(int);
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
