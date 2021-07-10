// Order.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Vector.h"
#include "Operation.h"

int main()
{
    int* array = new int[100];
    Vector *vect = new Vector[1];
    Operation operation;
    operation.generate_elements(vect, 100);
    std::cout << "Vector" << std::endl;
    operation.print(vect, 100);
    operation.shellsort_order(vect, 100);
    std::cout << "Vector ordenado" << std::endl;
    operation.print(vect, 100);
}
