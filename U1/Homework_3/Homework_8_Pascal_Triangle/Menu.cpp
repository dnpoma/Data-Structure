#include "Menu.h"

/**
* @brief menu
*
* @param
*
* @return int option
*/
int Menu::get_option() {
    return option;
}

/**
* @brief set_option
*
* @param _option
*
* @return
*/
void Menu::set_option(int _option) {
    option = _option;
}

/**
* @brief get_operation
*
* @param 
*
* @return operation
*/
Operation Menu::get_operation() {
    return operation;
}

/**
* @brief get_validation
*
* @param
*
* @return validation
*/
Validation Menu::get_validation() {
    return validation;
}

/**
* @brief set_validation
*
* @param Validation _validation
*
* @return 
*/
void Menu::set_validation(Validation _validation) {
    validation = _validation;
}

/**
* @brief set_operation
*
* @param _operation
*
* @return _operation
*/
void Menu::set_operation(Operation _operation) {
    operation = _operation;
}


/**
* @brief Imprime el menu de opciones
*
* @param std::ostream& output se utiliza para realizar las pruebas y comprobar resultado
*
* @return
*/

void Menu::menu(std::ostream& output) {
    //Operation operation;
    char opc[5];
    do {
        system("cls");
        std::cout << "------ Triángulo de Pascal ------" << std::endl;
        std::cout << "\nMenu de Opciones" << std::endl;
        std::cout << "1. Generar triángulo" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese la operación a realizar: ";
      //scanf_s("%d", &option);
        validation.validate(opc);
        option = atoi(opc);
        system("cls");
        switch (option) {
        case 1:
            int dimension;
            char option[5];
            printf("\nIngrese la dimensión del triángulo: ");
            validation.validate(option);
            dimension = atoi(option);
            operation.information(dimension);
            std::cout << std::endl;
            system("pause");
            break;
        case 0:
            output << "Gracias por usar el programa! :)";
            std::cout << "Gracias por usar el programa! :)" << std::endl;
            exit(0);
            break;
        default:
            output << "!Opción invalida!";
            std::cout << "!Opción invalida!" << std::endl;
            system("pause");
            break;
        }

    } while (option != 0);
}