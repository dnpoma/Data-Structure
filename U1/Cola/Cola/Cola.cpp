#include <iostream>
#include "Cola.h"

Cola::Cola() {
	this->front = nullptr;
	this->rear = nullptr;
}
Cola::~Cola() {}

int Cola::get_front() {
	return front->get_data();
}

int Cola::get_rear() {
	return rear->get_data();
}

bool Cola::empty() {
	return(this->front == nullptr && this->rear == nullptr);
}

void Cola::push(int data) {
	Nodo* new_nodo = new Nodo(data);
	if (empty()) {
		front = rear = new_nodo;
	}
	else {
		rear->set_next(new_nodo);
		rear = new_nodo;
	}
}

void Cola::display() {
	Nodo* tmp;
	if (empty()) {
		std::cout << "Cola vacia" << std::endl;
	}
	else {
		tmp = this->front;
		while (tmp != nullptr) {
			std::cout << tmp->get_data() << std::endl;
			tmp = tmp->get_next();
		}
	}
}

void Cola::pop() {
	Nodo* tmp = this->front;
	if (!empty()) {
		front = front->get_next();
		free(tmp);
	}
}


void Cola::calculate(std::function<void(int, int)>callback) {
	Nodo* tmp = this->front;
	int i = 0;
	while (tmp != nullptr) {
		callback(tmp->get_data(), i++);
		tmp = tmp->get_next();
	}
}


float Cola::avarage() {
	Nodo* tmp;
	float plus = 0;
	int i = 0;
	if (empty()) {
		std::cout << "Cola vacia" << std::endl;
	}
	else {
		tmp = this->front;
		while (tmp != nullptr) {
			i++;
			plus += tmp->get_data();
			tmp = tmp->get_next();
		}
		return (plus / i);
	}
}