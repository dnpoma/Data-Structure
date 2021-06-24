#include <iostream>
#include "Doubly_linked_list.h"
using namespace std;
int main(int argc, char** argv) {
	Doubly_linked_list<int> lst;
	lst.insert_start(1);
	lst.insert_start(2);
	lst.insert_start(3);
	lst.insert_start(4);
	lst.insert_end(8);
	lst.insert_start(54);
	//lst.delete_element(2);

	//lst.delete_first();

	lst.delete_last();
	lst.modified();

	lst.print([](int valor, int indice) {
		std::cout << "Indice:  " << indice+1 << "  valor " << valor << std::endl;
		});
	int suma = 0;
	lst.print([&suma](int valor, int indice) {
		suma += valor;
		});
	std::cout << "suma de elementos " << suma << std::endl;
	return 0;
}
