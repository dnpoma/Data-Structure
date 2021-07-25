#include "Operation.h"
#include <random>

void Operation::swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}



void Operation::generate_elements(Vector<int>* vector, int size) {
	vector->set_vector(new int[size]);
	//generate random number 
	std::random_device rdm;
	std::mt19937 mt(rdm());
	std::uniform_real_distribution<double> motor(1, 1000);
	int random = 0;
	for (int i = 0; i < size; i++) {
		random = int(motor(mt));
		*(vector->get_vector() + i) = random;
	}
}

void Operation::print(Vector<int>* vector, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << *(vector->get_vector() + i) << std::endl;
	}
}

//void Operation::print(Vector<int>* vector,int size, std::function<void(int, int)>callback) {
//	for (int i = 0; i < size; i++) {
//		std::cout << *(vector->get_vector() + i) << std::endl;
//	}
//}

void Operation::exchange_order(Vector<int>* vector, int size) {
	int tmp;
	//int size = sizeof(list);
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (*(vector->get_vector() + i) > *(vector->get_vector() + j)) {
				swap(*(vector->get_vector() + i), *(vector->get_vector() + j));
				//tmp = *(list + i);
				//*(list + i) = *(list + j);
				//*(list + j ) = tmp;
			}
		}
	}
}


void Operation::bubble_order(Vector<int>* vector, int size) {
	int tmp = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (*(vector->get_vector() + j) > *(vector->get_vector() + j + 1)) {
				swap(*(vector->get_vector() + j), *(vector->get_vector() + j + 1));
				/*
				tmp = *(vector->get_vector() + j);
				*(vector->get_vector() + j) = *(vector->get_vector() + j + 1);
				*(vector->get_vector() + j + 1) = tmp;*/
			}
		}
	}
}

void Operation::shellsort_order(Vector<int>* vector, int size) {
	//int size = sizeof(list);
	int jump = size / 2;
	while (jump > 0) {
		for (int i = jump; i < size; i++) {
			int j = i - jump;
			while (j >= 0) {
				int k = j + jump;
				if (*(vector->get_vector() + j) <= *(vector->get_vector() + k)) {
					j = -1;
				}
				else {
					swap(*(vector->get_vector() + j), *(vector->get_vector() + j + 1));
					j -= jump;
				}
			}
		}
		jump = jump / 2;
	}

}
