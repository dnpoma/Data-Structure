#pragma once
#include <iostream>
#include <functional>
class Order
{
public:
	Order() = default; 
	//@bried cambia las posiciones
	void swap(int&, int&);
	//@bried m�todo de ordenamiento intercambio
	void exchange(int*, int);
	
	//@brieg m�todo de ordenamiento burbuja
	void bubble(int*, int);

	int partition(int*, int, int);

	//@brieg m�todo de ordenamiento quicksort
	void quicksort(int*, int, int);

	//@brieg m�todo de ordenamiento shellsort
	void shellsort(int*, int);

	//@brieg m�todo de ordenamiento distribuci�n
	void distribution(int*, int);

	int get_max(int*, int);

	void count_sort(int*, int, int);

	//@brieg m�todo de ordenamiento radix sort
	void radix_sort(int*, int);

	void print(int*, int);
};

