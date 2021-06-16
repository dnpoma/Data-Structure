#pragma once
#include "Matrix.h"
#include "Validation.h"
class Operation
{
private:
	Matrix matrix;
	Validation validation;
public:
	int** segmentar();
	void encerar(int** matriz);
	void pascal_triangle(int** matriz);
	void print(int** matriz);
	void information(int);
	void set_matrix(Matrix _matrix);
	Matrix get_matrix();
	Validation get_validation();
	void set_validation(Validation _validation);
};

