#include"Screen.h"
/**
 * @brief print_coordinates
 * @param x
 * @param y
 */

void Screen::print_coordinates(short int x, short int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x,y };
	SetConsoleCursorPosition(handle, coord);
}

/**
 * @brief ajust_size
 *
 *
 */

void Screen::ajust_size()
{
	system("mode con lines=40 cols=150");
}

/**
 * @brief print menu
 * @param title
 * @param options_menu
 * @param elements_menu
 * @return options_select
 */

int Screen::print_menu(const char* title, const char* options_menu[], int elements_menu)
{
	bool repeat_menu = true;
	int option_select = 1;
	int key;

	do {
		system("cls");
		//print_squart(0, 0, 78, 39);
		//print_squart(1, 1, 77, 3);
		print_coordinates(5, 3 + option_select);
		std::cout << "---->";

		print_coordinates(15, 2);
		std::cout << title;

		for (int i = 0; i < elements_menu; i++) {
			print_coordinates(10, 4 + i);
			std::cout << *(options_menu + i);
		}

		do {
			key = _getch();
		} while (key != kEY_UP && key != KEY_DOWN && key != KEY_ENTER);

		switch (key) {
		case 72:
			option_select--;
			if (option_select < 1)
			{
				option_select = elements_menu;
			}
			break;
		case 80:
			option_select++;
			if (option_select > elements_menu)
			{
				option_select = 1;
			}
			break;
		case 13:
			repeat_menu = false;
			break;
		}

	} while (repeat_menu);
	return option_select;
}

/**
 * @brief print squard
 * @param x_initial
 * @param y_initial
 * @param x_final
 * @param y_final
 */
//void Screen::print_squart(int x_initial, int y_initial, int x_final, int y_final)
//{
//	int i;
//
//	for (i = x_initial; i < x_final; i++)
//	{
//		print_coordinates(i, y_initial); printf("\304");
//		print_coordinates(i, y_final); printf("\304");
//	}
//
//	for (i = y_initial; i < y_final; i++)
//	{
//		print_coordinates(x_initial, i); printf("\263");
//		print_coordinates(x_final, i); printf("\263");
//	}
//
//	print_coordinates(x_initial, y_initial); printf("\332");
//	print_coordinates(x_initial, y_final); printf("\300");
//	print_coordinates(x_final, y_initial); printf("\277");
//	print_coordinates(x_final, y_final); printf("\331");
//}