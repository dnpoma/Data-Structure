
#pragma once
class Matrix
{
private:
    int** matrix_A;
    int dimension;
    int row;
    int column;
public:
    int get_dimension();
    void set_dimension(int new_dimension);

    int get_row();
    void set_row(int new_row);
    int get_column();
    void set_column(int new_column);
    Matrix();
    ~Matrix();
};