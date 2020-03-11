#include "Face.h"

Face::Face()
{
}

Face::Face(int x, int y, int z)
{
	face.clear();
	face.push_back(x);
	face.push_back(y);
	face.push_back(z);
}

Face::~Face()
{
}

void Face::push(int d)
{
	face.push_back(d);
}

void Face::push(int x, int y, int z)
{
	face.clear();
	face.push_back(x);
	face.push_back(y);
	face.push_back(z);
}

int& Face::operator[](int idx)
{
	return face[idx];
}