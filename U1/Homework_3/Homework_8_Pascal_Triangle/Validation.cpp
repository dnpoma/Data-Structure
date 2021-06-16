#include "Validation.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>


void Validation::validate(char* character) {
    int i = 0, number_character = 2;
    char key;
    character[0] = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 1) {
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

