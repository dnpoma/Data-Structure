#pragma once
#include "Person.h"
#include "Utils.h"
#include "Doubly_linked_list.h"
class Operation
{
public:
	void validate_email(Person*, Doubly_linked_list<Person>*);
	void generate_email(Person*, int);
};

