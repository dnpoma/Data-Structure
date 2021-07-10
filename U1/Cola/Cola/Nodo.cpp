#include "Nodo.h"
Nodo::Nodo(int _data, Nodo* _next) {
	data = _data;
	next = _next;
}

int Nodo::get_data() {
	return data;
}
Nodo* Nodo::get_next() {
	return next;
}
void Nodo::set_next(Nodo* _next) {
	this->next = _next;
}
void Nodo::set_data(int _data) {
	this->data = _data;
}