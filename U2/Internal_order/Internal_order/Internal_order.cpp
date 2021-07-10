#include <iostream>
#include "Order.h"

int main()
{
	Order order;
	int num = 1 + rand() % (100 - 1);
	int *elements = new int[num];
	auto input = [&](){
		for (int i = 0; i < num; i++) {
			*(elements+i) = 1 + rand() % (100 - 1);
		}
	};

	input();

	std::cout << "Sin ordenar" << std::endl;
	order.print(elements, num);



	//std::cout << "Ordenamiento Burbuja" << std::endl;
	//order.bubble(elements, num);
	
	//std::cout << "Ordenamiento Intercambio" << std::endl;
	//order.exchange(elements, num);
	 
	//std::cout << "Ordenamiento Shell" << std::endl;
	//order.shellsort(elements, num);
	
	std::cout << "Ordenamiento quick sort" << std::endl;
	//order.quicksort(elements,0, num-1);
	order.radix_sort(elements, num);

	order.print(elements, num);
}
