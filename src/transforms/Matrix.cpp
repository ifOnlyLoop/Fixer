#include"Matrix.h"

Matrix::Matrix(unsigned int row, unsigned int col)
{
	rows = row; 
	cols = col;
	data.resize(row*col,0);


}

Matrix::~Matrix()
{
}

float Matrix::getElement(unsigned int row, unsigned int col)
{
	return 0;
}