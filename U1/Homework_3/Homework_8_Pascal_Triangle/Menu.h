#pragma once
#include <iostream>
#include "Operation.h"
#include "Validation.h"

class Menu
{
private:
	int option;
	Operation operation;
	Validation validation;
public:
	int get_option();
	void set_option(int);
	Operation get_operation();
	void set_operation(Operation _operation);
	Validation get_validation();
	void set_validation(Validation _validation);
	void menu(std::ostream& output);
};