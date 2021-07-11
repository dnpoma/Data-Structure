#include "Menu.h"

void Menu::main_menu()
{
	bool repeat_menu = true;
	const char* title = "Cola - Tabla";
	const char* options_menu[] = { "Generar tabla", "Generar tabla aleatoria", "Salir" };
	int option_selected;

    do {
        system("cls");
        system("COLOR 0F");
        scrn.ajust_size();
        option_selected = scrn.print_menu(title, options_menu, 3);
        Process prcs;
        switch (option_selected) {
        case 1:
            system("cls");
            char clients[100];
            int value;
            std::cout << "Ingrese el numero de clientes a calcular: ";
            Utils::Validation::integer(clients, 3);
            value = Utils::Validation::atoi(clients);
            generate_table(value, prcs);
            system("pause>nul");
            break;
        case 2:
            system("cls");
            generate_table(Utils::Validation::random_numbers(1, 50), prcs);
            system("pause>nul");
            break;
        case 3:
            repeat_menu = false;
            std::cout << "Gracias por utilizar nuestro programa uwu" << std::endl;
            break;
        }
    } while (repeat_menu == true);
}

void Menu::generate_table(int clients, Process prcs) {
    std::cout<<""<< std::endl;
    prcs.calculate_all(clients);
    prcs.print_table(clients);
    system("pause>nul");
    std::cout << "" << std::endl;
    prcs.print_total();
}