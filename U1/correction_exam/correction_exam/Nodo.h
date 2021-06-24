#pragma once
#include "Person.h"
class Nodo
{
public:
	Nodo(Person person);
	Nodo* get_next();
	void set_next(Nodo*);
	Nodo* get_last();
	void set_last(Nodo*);
	Person get_data();
	void set_data(Person);
private:
	Person person;
	Nodo* next = nullptr;
	Nodo* last = nullptr;
};

