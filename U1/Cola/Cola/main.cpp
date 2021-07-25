#include <iostream>
#include "Menu.h"
#include "Marquee.h"
int main() {
	Marquee mrk(" Grupo 9 - Extras ", 17);
	mrk.animation();
	Menu menu;
	menu.main_menu();
	system("pause");
	std::cout << std::endl;
}
