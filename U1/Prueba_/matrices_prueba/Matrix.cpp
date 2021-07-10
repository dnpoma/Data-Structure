#include <iostream>
#include "Matrix.h"
using namespace std;

int Matrix::get_dimension() {
	return dimension;
}
void Matrix::set_dimension(int new_dimension) {
	this->dimension = new_dimension;
}
int Matrix::get_row() {
	return row;
}
void Matrix::set_row(int new_row) {
	this->row = new_row;
}

int Matrix::get_column() {
	return column;
}
void Matrix::set_column(int new_column) {
	this->column = new_column;
}
Matrix::Matrix() {
}
Matrix::~Matrix() {
	// TODO : implement
}