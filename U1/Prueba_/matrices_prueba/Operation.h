#pragma once

#include <time.h>
#include "Matrix.h"

class Operation
{
public:
    int** segment();
    void waxing(int** matrix_A);
    void enter(float** matrix_A);
    void enter_data();
    template <typename T>
    void print(T** matrix_A);
    void enter_aletori(int** matrix_A);

};
