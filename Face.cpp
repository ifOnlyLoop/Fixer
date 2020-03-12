#include "Face.h"

Face::Face()
{
	//vertexListData = NULL;
}

Face::Face(int x, int y, int z)
{
	//vertexListData = NULL;
	vertexList.clear();
	vertexList.push_back(x);
	vertexList.push_back(y);
	vertexList.push_back(z);
}

Face::~Face()
{
}

void Face::push(int d)
{
	vertexList.push_back(d);
}

void Face::push(int x, int y, int z)
{
	vertexList.clear();
	vertexList.push_back(x);
	vertexList.push_back(y);
	vertexList.push_back(z);
}

int Face::size()
{
	return vertexList.size();
}

void Face::clear()
{
	vertexList.clear();
}

int& Face::operator[](int idx)
{
	return vertexList[idx];
}
