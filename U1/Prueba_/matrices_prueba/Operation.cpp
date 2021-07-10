#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include "Operation.h"
#include "Matrix.h"
#include "Validation.h"
Matrix matrix;
Validation validation;
using namespace std;
int** Operation::segment() {
    int** matrix_G;
    matrix_G = (int**)malloc(matrix.get_row() * sizeof(int*));
    for (int j = 0; j < matrix.get_column(); j++)
        *(matrix_G + j) = (int*)malloc(matrix.get_column() * sizeof(int));
    return matrix_G;
}

void Operation::waxing(int** matrix_A) {
    for (int i = 0; i < matrix.get_row(); i++)
        for (int j = 0; j < matrix.get_column(); j++)
            *(*(matrix_A + i) + j) = 0;
}
/*
void Operation::enter(float** matrix_A) {
    char numero_A[5];
    float numero;
    for (int i = 0; i < matrix.get_dimension(); i++) {
        for (int j = 0; j < matrix.get_dimension(); j++) {
            cout << "\nEnter the element at position: [" << i << "][" << j << "]: ";
            validation.integer(numero_A);
            numero = atof(numero_A);
            *(*(matrix_A + i) + j) = numero;
        }
    }
}*/

void Operation::enter_aletori(int** matrix_A) {
    srand(time(NULL));
    int number;
    for (int i = 0; i < matrix.get_row(); i++) {
        for (int j = 0; j < matrix.get_column(); j++) {
            number = 1 + rand() % 9;
            *(*(matrix_A + i) + j) = number;
        }
    }
}
/*
void Operation::repit(int ** matrix_A) {
    int number;
    for (int i = 0; i < matrix.get_row(); i++) {
        for (int j = 0; j < matrix.get_column() ;j++) {
            *(*(matrix_A + i) + j) = *(*(matrix_A + i) + j);
        }
    }
}
*/

template <typename T>
void Operation::print(T** matrix_A) {
    for (int i = 0; i < matrix.get_row(); i++) {
        cout << "| ";
        for (int j = 0; j < matrix.get_column(); j++) {
            printf("%*s", j + 5, "");
            cout << *(*(matrix_A + i) + j);
        }
        cout << "  |" << endl;
        printf("\n");
    }
}


void Operation::enter_data() {
    char dimension_A[5], row_A[5], column_A[5];
    int dimension;
    int row;
    int column;
    int** matrix_identity;
    int** matrix_C;
    int** matrix_1;
    printf("\nIngrese la fila de la matriz: ");
    validation.natural_numbers(row_A);
    row = atoi(row_A);
    matrix.set_row(row);
    printf("\nIngrese la columna de la matriz: ");
    validation.natural_numbers(column_A);
    column = atoi(column_A);
    matrix.set_column(column);
    matrix_1 = segment();
    //matrix_C = segment();
    //matrix_identity = segment();
    waxing(matrix_1);
    enter_aletori(matrix_1);
    cout << "\n\n Matriz ingresada \n" << endl;
    print(matrix_1);

    /* copy(matrix_C, matrix_1);
     if (determinate(matrix_C) == 0) {
         cout << "\n\n  El determinante de la matriz es cero, la matriz es no invertible. \n" << endl;
     }
     else {
         make_identity(matrix_identity);
         cout << "\n\n Matriz a encontrar su identidad\n" << endl;
         print(matrix_1);
         reduce_pivot(matrix_1, matrix_identity);
         cout << "\n\n Matriz identidad \n" << endl;
         print(matrix_1);//resultado xd
         cout << "\n\n Matriz inversa\n" << endl;
         print(matrix_identity); //matriz inversa
     }*/

}


