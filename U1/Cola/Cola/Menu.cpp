#include "Menu.h"



/* 
* @brief main_menu
*
*/
void Menu::main_menu()
{
	bool repeat_menu = true;
	const char* title = "Cola - Tabla";
	const char* options_menu[] = { "Generar tabla", "Generar tabla aleatoria", "Salir" };
	int option_selected;
    
    //Marquee mrk(" Grupo 9 - Extras ", 17);
    do {
   
        system("COLOR 0F");
        option_selected = scrn.print_menu(title, options_menu, 3);
        Process prcs;        
       // mrk.animation();
        switch (option_selected) {
        case 1:
            system("@cls||clear");
            char clients[100];
            int value;
            //mrk.print_to(1, 3);
            std::cout << "\n\n\nIngrese el numero de clientes a calcular: ";
            //mrk.print_to(27,3);
            Utils::Validation::integer(clients, 3);
            value = Utils::Validation::atoi(clients);
            //mrk.print_to(27, 5);
            generate_table(value, prcs);
            system("pause>nul");
            break;
        case 2:
            system("@cls||clear");
            generate_table(Utils::Validation::random_numbers(1, 50), prcs);
            system("pause>nul");
            break;
        case 3:
            repeat_menu = false;
            //mrk.print_to(1, 7);
            std::cout << std::endl << std::endl << std::endl << std::endl;
            std::cout << "Gracias por utilizar nuestro programa uwu" << std::endl;
            std::cout << std::endl << std::endl;
            break;
        }
        
    } while (repeat_menu == true);
}

/* 
* @brief generate table
*
*/
void Menu::generate_table(int clients, Process prcs) {
    //Marquee mrk("Grupo 9 - Extras", 17);
    std::cout<<"\n\n\n\n"<< std::endl;
    prcs.calculate_all(clients);
    prcs.print_table(clients);
    std::cout << "" << std::endl;
    prcs.print_total();
    system("pause>nul");
    //mrk.animation();
}
