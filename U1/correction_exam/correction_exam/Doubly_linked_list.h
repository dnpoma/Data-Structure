#pragma once
#include "Person.h"
#include "Nodo.h"
#include "Operation.h"
#include<functional>
using namespace std;

class Doubly_linked_list
{
private:
	Nodo* last();
	Nodo* first = nullptr;
	int size = 0;
	Person person;
	Operation op;
public:
	Doubly_linked_list() = default;
	void insert_start(Person);
	void print(std::function<void(std::string, int)>callback);
	void insert_end(Person);
	void insert_between(Person);
	void delete_element(Person);
	void delete_first();
	void modified();
	void modified_input(std::string, std::string);
	void delete_last();
	bool empty();
	void modified_change(int);
	void print();
	//~Linked_list();
};
