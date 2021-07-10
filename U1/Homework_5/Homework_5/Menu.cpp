#include "Menu.h"

void Menu::menu_principal() {
    Doubly_linked_list<int> lst;
    bool repite = true;
    int opcion;
    
    const char* titulo = "MENU DE OPCIONES";
    const char* opciones[] = { "Agregar", "Eliminar","Imprimir","Buscar", "Salir" };
    int n = 5; 
    do {
        std::cout << titulo<<std::endl;
        for (size_t i = 0; i < n; i++)
        {
            std::cout << i+1 << ". " << *(opciones + i) << std::endl;
        }
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            menu_add(lst);
            break;
        case 2:
            menu_delete(lst);
            break;
        case 3:
            system("cls");
            std::cout << "Indice\tValor" << std::endl;
            lst.print([](int valor, int indice) {
                std::cout << indice + 1 << "\t"<<valor << " " << std::endl;
                });
            system("pause>nul");
            break;
        case 4:
            system("cls");
            int index;
            std::cout << "Ingrese el indice que desea buscar: ";
            //index = Utils::Validation::validation_numbers<int>("");
            std::cin >> index;
            std::cout<<"Dato: "<<lst.search(index);
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

void Menu::menu_add(Doubly_linked_list<int>& lst) {
    bool repite = true;
    int opcion;
    int data;

    const char* titulo = "MENU DE OPCIONES";
    const char* opciones[] = { "Agregar por la cabeza", "Agregar por la cola","Agregar entre", "Salir" };
    int n = 4;
    do {
        std::cout << titulo << std::endl;
        for (size_t i = 0; i < n; i++)
        {
            std::cout<< i+1 << ". " << *(opciones + i) << std::endl;
        }
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "\nIngrese el numero:";
            std::cin >> data;
            lst.insert_start(data);
            break;
        case 2:
            std::cout << "\nIngrese el numero:";
            std::cin >> data;
            lst.insert_end(data);
            break;
        case 3:
            int index;
            std::cout << "\nIngrese el numero:";
            std::cin >> data;
            std::cout << "\nIngrese el indice:";
            std::cin >> index;
            lst.insert_between(index, data);
            break;
        case 4:
            system("cls");
            std::cout << "\n..........." << std::endl;
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
    system("cls");
}


void Menu::menu_delete(Doubly_linked_list<int>& lst) {
    bool repite = true;
    int opcion;
    int data;

    const char* titulo = "MENU DE OPCIONES";
    const char* opciones[] = { "Eliminar por la cabeza", "Eliminar por la cola","Eliminar entre", "Salir" };
    int n = 4;
    do {
        std::cout << titulo << std::endl;
        for (size_t i = 0; i < n; i++)
        {
            std::cout<< i+1 << ". " << *(opciones + i) << std::endl;
        }
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            lst.delete_first();
            break;
        case 2:
            lst.delete_last();
            break;
        case 3:
            int index;
            std::cout << "\nIngrese el indice:";
            std::cin >> index;
            lst.delete_element(index);
            break;
        case 4:
            system("cls");
            std::cout << "\n....." << std::endl;
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
    system("cls");
}