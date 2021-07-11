#pragma once
#include <iostream>
#include "Stack.h"
class Operation
{
public:
	int precedence(char);
	std::string infix_to_postfix(std::string);
	double postfix_evaluation(std::string);
	double prefix_evaluation(std::string);
	int str_to_it(char*);
};

