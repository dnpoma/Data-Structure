#include "Nodo.h"

Nodo::Nodo(Person _person) {
	this->person = _person;
}

Nodo* Nodo::get_next() {
	return next;
}


void Nodo::set_next(Nodo* _next) {
	this->next = _next;
}


Nodo* Nodo::get_last() {
	return last;
}


void Nodo::set_last(Nodo* _last) {
	this->last = _last;
}


Person Nodo::get_data() {
	return person;
}


void Nodo::set_data(Person _person) {
	this->person = _person;
}