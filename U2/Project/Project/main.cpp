#include <iostream>
#include "Tree.h"
#include "file.h"

int main()
{
	Tree tree;
	tree.push("Hola", "hi");
	tree.push("Carro", "car");
	tree.delet("Hola");
	std::cout << "---------------------" << std::endl;
	tree.print();
	tree.search("carro");
	tree.search("car");

	//tree.print([](std::string eng, std::string spa) {
	//	std::cout << "Search: "<< eng<<spa;
	//	if ("CASA" == eng || "CASA" == spa) {
	//	}
	//});
}