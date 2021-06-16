/*
* Universidd de las Fuerzas Armadas ESPE
* Carrera: Ingeniería de Software
* Autores:
*
* Sebastian Alexander Zapata Zapata --- @sebastian771 --- Líder de Equipo
* Adriana Alejandra Vargas Aldas --- @adrivargas14
* Christopher Israel Loachamin Simbana --- @ciloachamin
* Mateo Nicolás Andrade Penafiel --- @MateoNicolasAndrade
* Dayse Nicole Poma Aguilar --- @dnpoma
*
* Enunciado: Realice el triángulo de pascal de forma matemática utilizando matrices con memoria dinámica.
*
* Fecha de creación: 05/06/2021
* Fecha de modificación: 06/06/2021
*
*/

#include "Operation.h"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>


/**
* @brief segmentar
*
* @param
*
* @return matriz
*/
int** Operation::segmentar() {
    int **matriz, j;
    matriz = (int**)malloc(matrix.get_dimension() * sizeof(int*));
    for (j = 0; j < matrix.get_dimension(); j++)
        *(matriz + j) = (int*)malloc(matrix.get_dimension() * sizeof(int));
    return matriz;
}

/**
* @brief encerar
*
* @param int** matriz
*
* @return 
*/
void Operation::encerar(int** matriz) {
    int i, j;
    for (i = 0; i < matrix.get_dimension(); i++)
        for (j = 0; j < matrix.get_dimension(); j++)
        *(*(matriz + i) + j) = 0;
}

/**
* @brief pascal_triangle
*
* @param int** matriz
*
* @return
*/
void Operation::pascal_triangle(int** matriz) {
    int i, j, coef = 1;
    for (i = 0; i < matrix.get_dimension(); i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;
                *(*(matriz + i) + j) = *(*(matriz + i) + j) + coef;
        }
    }
}

/**
* @brief print
*
* @param int** matriz
*
* @return
*/
void Operation::print(int** matriz) {
    int i, j, space;
    for (i = 0; i < matrix.get_dimension(); i++) {
        for (space = 1; space <= matrix.get_dimension() - i; space++)
            printf("  ");
        for (j = 0; j < matrix.get_dimension(); j++) {
            if (*(*(matriz + i) + j) != 0)
                std::cout << std::setw(4) << *(*(matriz + i) + j);
        }
        printf("\n");
    }
}

/**
* @brief set_matrix
*
* @param _matrix
*
* @return 
*/
void Operation::set_matrix(Matrix _matrix) {
    matrix = _matrix;
}

/**
* @brief get_matrix
*
* @param
*
* @return matrix
*/
Matrix Operation::get_matrix() {
    return matrix;
}

/**
* @brief get_validation
*
* @param
*
* @return validation
*/
Validation Operation::get_validation() {
    return validation;
}


/**
* @brief set_validation
*
* @param _validation
*
* @return
*/
void Operation::set_validation(Validation _validation) {
    validation = _validation;
}


/**
* @brief information se genera el triángulo de Pascal y se imprime.
*
* @param 
*
* @return
*/
void Operation::information(int dimension) {
    int** matrix1;
 /*   int dimension;
    char option[5];

    printf("\nIngrese la dimensión del triángulo: ");
    validation.validate(option);
    dimension = atoi(option);
    */
    printf("\n\n\n");
    matrix.set_dimension(dimension);
    matrix1 = segmentar();
    encerar(matrix1);
    pascal_triangle(matrix1);
    print(matrix1);
}