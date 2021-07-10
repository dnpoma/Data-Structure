#include "Order.h"

void Order::swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void Order::exchange(int* list, int size) {
	int tmp;
	//int size = sizeof(list);
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (*(list + i) > *(list + j)) {
				swap(*(list + i), *(list + j));
				//tmp = *(list + i);
				//*(list + i) = *(list + j);
				//*(list + j ) = tmp;
			}
		}
	}
}

void Order::bubble(int* list, int size) {
	int tmp;
	//int size = sizeof(list);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (*(list + j) > *(list + j + 1)) {
				swap(*(list + j), *(list + j + 1));
				//tmp = *(list + j);
				//*(list + j) = *(list + j + 1);
				//*(list + j + 1) = tmp;
			}
		}
	}
}

int Order::partition(int* arr, int low, int high)
{
	int pivot = *(arr+high); // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (*(arr+j) < pivot)
		{
			i++; // increment index of smaller element
			swap(*(arr+i), *(arr+j));
		}
	}
	swap(*(arr+i + 1), *(arr+high));
	return (i + 1);
}

void Order::quicksort(int* list, int low, int high) {
	//int size = sizeof(list);
	if (low < high) {
		int pi = partition(list, low, high);

		quicksort(list, low, pi - 1);
		quicksort(list, pi + 1, high);
	}
}

void Order::shellsort(int* list, int size) {
	//int size = sizeof(list);
	int jump = size / 2;
	while (jump > 0) {
		for (int i = jump; i < size; i++) {
			int j = i - jump;
			while (j >= 0) {
				int k = j + jump;
				if (*(list + j) <= *(list + k)) {
					j = -1;
				}
				else {
					swap(*(list + j), *(list + j + 1));
					j -= jump;
				}
			}
		}
		jump = jump / 2;
	}
	
}

void Order::distribution(int* list, int size) {
	//int size = sizeof(list);

}

int Order::get_max(int* list, int size) {
	int max = *(list);
	for (int i = 1; i < size; i++)
		if (*(list+i) > max)
			max = *(list+i);
	return max;
}

void Order::count_sort(int* list, int size, int exp) {
	int* output; 
	int i, count[10] = { 0 };

	for (i = 0; i < size; i++)
		count[(*(list+i) / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--) {
		output[count[(*(list +i) / exp) % 10] - 1] = *(list+i);
		count[(*(list+i) / exp) % 10]--;
	}


	for (i = 0; i < size; i++)
		*(list +i) = *(output+i);
}

void Order::radix_sort(int* list, int size) {
	//int size = sizeof(list);
	int m = get_max(list, size);

	for (int exp = 1; m / exp > 0; exp *= 10)
		count_sort(list, size, exp);
}

void Order::print(int* lst, int size) {
	//int size = sizeof(lst);
	for (int i = 0; i < size; i++) {
		std::cout << *(lst + i) << std::endl;
	}
}