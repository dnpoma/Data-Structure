#pragma once
class Matrix
{
private: 
	int dimension;
public:
	Matrix() = default;
	~Matrix();
	int get_dimension();
	void set_dimension(int);
};

