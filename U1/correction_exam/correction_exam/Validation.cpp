#include "Validation.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void Validation::natural_numbers(char* character) {
    int i = 0, number_character = 3;
    char key;
    character[0] = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 8) {
            std::cout << "\b \b";
            character[--i] = '\0';
        }
        else {
            if ((key >= 48 && key <= 57)) {
                std::cout << key;
                character[i++] = key;
            }
        }
    } while ((key != 13 || character[0] == '\0') && i < number_character);
    character[i] = '\0';
    return;
}

void Validation::integer(char* character, int number) {
    int i = 0, number_character = number;
    char key;
    char key_ = 45;
    character[0] = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 8) {
            std::cout << "\b \b";
            character[--i] = '\0';
        }
        else {
            if ((key >= 48 && key <= 57) || (key >= 45 && key <= 45)) {
                std::cout << key;
                character[i++] = key;
            }
        }
    } while ((key != 13 || character[0] == '\0') && i < number_character);
    character[i] = '\0';
    return;
}

void Validation::letters(char* character) {
    setlocale(LC_ALL, "");
    int i = 0, number_character = 25;
    char key;
    *(character + 0) = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 8) {
            std::cout << "\b \b";
            *(character + --i) = '\0';
        }
        else {
            if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || key == 'ñ' || key == 'Ñ' || (key == 32)) {
                std::cout << key;
                *(character + i++) = key;
            }
        }
    } while ((key != 13 || *(character + 0) == '\0') && i < number_character);
    *(character + i) = '\0';
    return;
}


std::string Validation::capital_letter(std::string cadena) {

    for (int i = 0; i < cadena.length(); i++) {
        cadena[i] = toupper(cadena[i]);
    }
    return cadena;
}