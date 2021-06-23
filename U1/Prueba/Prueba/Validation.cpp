#include "Validation.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void Validation::natural_numbers(char* character) {
    int i = 0, number_character = 3;
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

void Validation::integer(char* character, int number) {
    int i = 0, number_character = number;
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

int Validation::digits(int number) {
    int contador=1;
    while (number / 10 > 0)
    {
        number = number / 10;
        contador++;
    }
    return contador;
}

/*
int &Validation::descomposition(int number) {
    int data[3], i=0;
    while (number > 0) {
        data[i] = number % 10;
        number = number / 10;
        i++;
    }
    return data;
}*/