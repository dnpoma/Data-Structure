#include "Vector.h"

Vector::Vector(int vec[10]){
	for(int i=0; i<10;i++){
		vect[i] = vec[i];	
	}
}

Vector::~Vector(){
	
}

void Vector::set_vector(int vec[10]){
//	this->vect = new_vector;
	for(int i=0; i<10;i++){
		vect[i] = vec[i];	
	}
}

int *Vector::get_vector(){
	return vect;
}
