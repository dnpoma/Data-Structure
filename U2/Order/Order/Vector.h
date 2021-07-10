#pragma once
class Vector
{
private:
	int* array = new int[100];
	//int* array;
public:
	Vector() = default;
	Vector(int*);
	void set_vector(int*);
	int* get_vector();
};

