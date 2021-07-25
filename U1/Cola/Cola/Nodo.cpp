#include "Nodo.h"

/* 
* @brief Nodo
* @param int data y Nodo* _next
*/
Nodo::Nodo(int _data, Nodo* _next) {
	data = _data;
	next = _next;
}

/* 
* @brief get_data
* @return data
*/
int Nodo::get_data() {
	return data;
}
/* 
* @brief get_next
* @return next
*/
Nodo* Nodo::get_next() {
	return next;
}
/* 
* @brief set_next
* 
*/
void Nodo::set_next(Nodo* _next) {
	this->next = _next;
}

/* 
* @brief set_data
* 
*/
void Nodo::set_data(int _data) {
	this->data = _data;
}
