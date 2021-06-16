#pragma once
#include <iostream>

class Vector
{
private:
    int vect[10];

public:
	Vector(int[10]);
    ~Vector();
    void set_vector(int[10]);
    int *get_vector();
};
