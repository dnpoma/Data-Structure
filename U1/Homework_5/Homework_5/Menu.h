#pragma once
#include "Doubly_linked_list.h"
#include <iostream>
class Menu
{
public:
	void menu_principal();
	void menu_add(Doubly_linked_list<int>&);
	void menu_delete(Doubly_linked_list<int>&);
//private:
	//Doubly_linked_list<int>* lst = new Doubly_linked_list<int>();
	//Doubly_linked_list<Person>* persona = new Doubly_linked_list<Person>();
};

//class Person {
//	int edad;
//	std::string nombre;
//	std::string celular;
//	Person() = default;
//};