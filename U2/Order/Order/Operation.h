#pragma once
#include "Vector.h"
#include <functional>
#include <iostream>
class Operation
{
public:
	void generate_elements(Vector*, int);
	void bubble_order(Vector*, int);
	void exchange_order(Vector*, int);
	void shellsort_order(Vector*, int);
	void swap(int&, int&);
	void print(Vector*, int);
	void print(Vector*,int,std::function<void(int, int)>callback);
};

