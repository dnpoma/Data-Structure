#include "Menu.h"
#include <iostream>
#include <string>
void Menu::menu_opc() {
    //Circular_Linked_List<int> lst;
    Person person;
    Operation operation;
    Doubly_linked_list<Person>* lst = new Doubly_linked_list<Person>;
    bool repite = true;
    int option;

    char cedula_A[11], name_A[25], last_name_B[25], direction_[50];
    std::string name, last_name, direction;

    const char* title = "Menu de opciones";
    const char* options[] = { "Agregar", "Eliminar", "Imprimir", "Buscar", "Salir" };
    int n = 5, index;
    do {
        std::cout << title << std::endl;
        for (size_t i = 0; i < n; i++)
        {
            std::cout << i + 1 << ". " << *(options + i) << std::endl;
        }
        std::cin >> option;

        switch (option) {
        case 1:
             //:) Aqui poner el texto uwu
            std::cout << "\nNombre: ";
            Utils::Validation::letters(name_A,25);
            name.append(name_A);
            person.set_name(Utils::Validation::upper(name));


            std::cout << "\nApellido: ";
            Utils::Validation::letters(last_name_B, 25);
            last_name.append(last_name_B);
            person.set_last_name(Utils::Validation::upper(last_name));


            std::cout << "\nDireccion: ";
            Utils::Validation::letters(direction_, 50);
            direction.append(direction_);
            person.set_direction(Utils::Validation::upper(direction));

            

            std::cout << "\nTelefono: ";
            person.set_phone(Utils::Validation::input_phone(10));

            std::cout << "\nCorreo: ";
            operation.validate_email(&person, lst);
            lst->insert_end(person);
            //menu_add(lst);
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            break;
        case 2:
            int index;
            std::cout << "Ingrese el valor que desea eliminar: ";
            std::cin >> index;
            //lst.deleteNodeByKey(index);
            break;
        case 3:
            system("cls");
            //std::cout << "Indice\tValor" << std::endl;
            //lst.print();
            lst->print();
            system("pause>nul");
            break;
        case 4:
            system("cls");
            std::cout << "Ingrese el valor que desea buscar: ";
            //index = Utils::Validation::validation_numbers<int>("");
            std::cin >> index;
            //lst.search_data(index);
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

void Menu::menu_sn() {
    std::string respuesta;
    int number;
    do {
        std::cout << " ";
        std::cout << " ";
        std::cout << " ";



        std::cout << "\nDesea ingresar otro dato [S/N]: ";
        getline(std::cin, respuesta, '\n');
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');

    } while (respuesta[0] != 'N');
    //Dayse inserta otra lista aqui!!
}
