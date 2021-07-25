#include <iostream>
#include "Cola.h"

/**
 * @brief Cola constructor
 * 
 */
Cola::Cola() {
	this->front = nullptr;
	this->rear = nullptr;
}

/**
 * @brief Cola Destructor
 * 
 */
Cola::~Cola() {}

int Cola::get_front() {
	return front->get_data();
}

/**
 * @brief get_rear
 * 
 */
int Cola::get_rear() {
	return rear->get_data();
}

/**
 * @brief empty
 * @return front y rear
 * 
 */
bool Cola::empty() {
	return(this->front == nullptr && this->rear == nullptr);
}

/**
 * @brief push
 * @param data 
 * 
 */
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

/**
 * @brief display
 * 
 */
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

/**
 * @brief pop
 * 
 */
void Cola::pop() {
	Nodo* tmp = this->front;
	if (!empty()) {
		front = front->get_next();
		free(tmp);
	}
}

/**
 * @brief calculate
 * @param function y callback
 */
 
void Cola::calculate(std::function<void(int, int)>callback) {
	Nodo* tmp = this->front;
	int i = 0;
	while (tmp != nullptr) {
		callback(tmp->get_data(), i++);
		tmp = tmp->get_next();
	}
}

/**
 * @brief avarage
 * @return plus/i
 */

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
