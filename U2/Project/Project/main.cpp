#include <iostream>
#include "Tree.h"
#include "file.h"

int main()
{
	Tree tree;
	tree.push("Hola", "hi");
	tree.push("Sol", "sun");
	tree.push("inteligente", "smart");
	tree.push("telefono", "phone");
	tree.push("casa", "house");
	tree.search("casa");

	tree.delet("Sol");
	std::cout << "---------------------" << std::endl;
	tree.print();
	
	//tree.print([](std::string eng, std::string spa) {
	//	std::cout << "Search: "<< eng<<spa;
	//	if ("CASA" == eng || "CASA" == spa) {
	//	}
	//});
}