#include "Menu.h"

void Menu::menu_principal() {
	Circular_Linked_List<int> lst;
	bool repite = true;
	int option;

	const char* title = "Menu de opciones";
	const char* options[] = {"Agregar", "Eliminar", "Imprimir", "Buscar", "Salir"};
	int n = 5, index;
    do{
	    std::cout << title << std::endl;
	    for (size_t i = 0; i < n; i++)
	    {
		    std::cout << i + 1 << ". " << *(options + i) << std::endl;
	    }
	    std::cin >> option;

        switch (option) {
        case 1:
            menu_add(lst);
            break;
        case 2:
            int index;
            std::cout << "Ingrese el valor que desea eliminar: ";
            std::cin >> index;
            lst.deleteNodeByKey(index);
            break;
        case 3:
            system("cls");
            std::cout << "Indice\tValor" << std::endl;
            lst.print();
            system("pause>nul");
            break;
        case 4:
            system("cls");
            std::cout << "Ingrese el valor que desea buscar: ";
            //index = Utils::Validation::validation_numbers<int>("");
            std::cin >> index;
            lst.search_data(index);
            break;
        case 5:
            system("cls");
            std::cout << "\nGracias por utilizar nuestro programa" << std::endl;
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
}

void Menu::menu_add(Circular_Linked_List<int>& list) {
    bool repite = true;
    int option;
    int data;
    const char* title = "Menu de opciones";
    const char* options[] = { "Agregar por la cola", "Agregar por la cabeza", "Agregar después", "Salir" };
    int n = 4;
    do {
        std::cout << title << std::endl;
        for (size_t i = 0; i < n; i++)
        {
            std::cout << i + 1 << ". " << *(options + i) << std::endl;
        }
        std::cin >> option;

        switch (option) {
        case 1:
            std::cout << "\nIngrese el numero:";
            std::cin >> data;
            list.append(data);
            break;
        case 2:
            std::cout << "\nIngrese el numero:";
            std::cin >> data;
            list.prependNode(data);
            break;
        case 3:
            int index;
            std::cout << "\nIngrese el numero:";
            std::cin >> data;
            std::cout << "\nIngrese el indice:";
            std::cin >> index;
            list.insertNodeAfter(index, data);
            system("pause>nul");
            break;
        case 4:
            system("cls");
            std::cout << "\n...." << std::endl;
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
}