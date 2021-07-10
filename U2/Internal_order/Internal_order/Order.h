#pragma once
#include <iostream>
#include <functional>
class Order
{
public:
	Order() = default; 
	//@bried cambia las posiciones
	void swap(int&, int&);
	//@bried método de ordenamiento intercambio
	void exchange(int*, int);
	
	//@brieg método de ordenamiento burbuja
	void bubble(int*, int);

	int partition(int*, int, int);

	//@brieg método de ordenamiento quicksort
	void quicksort(int*, int, int);

	//@brieg método de ordenamiento shellsort
	void shellsort(int*, int);

	//@brieg método de ordenamiento distribución
	void distribution(int*, int);

	int get_max(int*, int);

	void count_sort(int*, int, int);

	//@brieg método de ordenamiento radix sort
	void radix_sort(int*, int);

	void print(int*, int);
};

