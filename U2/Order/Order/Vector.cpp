#include "Vector.h"

Vector::Vector(int* _array) {
	array = _array;
}


void Vector::set_vector(int* _array) {
	array = _array;
}

int* Vector::get_vector() {
	return array;
}