#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
public:
	
	 Matrix(unsigned int row, unsigned int col);
	~Matrix();

	float getElement(unsigned int row, unsigned int col);
	//Matrix& operator [](const vect& a);

private:
	unsigned int rows, cols;
	std::vector<float> data;
};

#endif
