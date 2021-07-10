#pragma once
#include <iostream>
#include "Stack.h"
class Operation
{
public:
	int precedence(char);
	void infix_to_postfix(std::string);
	double postfix_evaluation(char*);
	double prefix_evaluation(std::string);
};

