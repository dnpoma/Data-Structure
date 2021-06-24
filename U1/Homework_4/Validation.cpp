#include "Validation.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void Validation::natural_numbers(char* character) {
    int i = 0, number_character = 4;
    char key;
    character[0] = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 8) {
            cout << "\b \b";
            character[--i] = '\0';
        }
        else {
            if ((key >= 48 && key <= 57)) {
                cout << key;
                character[i++] = key;
            }
        }
    } while ((key != 13 || character[0] == '\0') && i < number_character);
    character[i] = '\0';
    return;
}

void Validation::integer(char* character) {
    int i = 0, number_character = 3;
    char key;
    char key_ = 45;
    character[0] = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 8) {
            cout << "\b \b";
            character[--i] = '\0';
        }
        else {
            if ((key >= 48 && key <= 57) || (key >= 45 && key <= 45)) {
                cout << key;
                character[i++] = key;
            }
        }
    } while ((key != 13 || character[0] == '\0') && i < number_character);
    character[i] = '\0';
    return;
}
