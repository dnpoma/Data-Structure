#pragma once
#include "Linked_list.h"
#include "Validation.h"
class Menu
{
public:
	Menu()=default;
	int menu(const char* , const char* [], int );
	void gotoxy(int x, int y);
	void menu_principal();
private:
	Linked_list<int> lst;
	Validation val;
};
