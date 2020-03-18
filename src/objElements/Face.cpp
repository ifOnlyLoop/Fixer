#include "Face.h"

Face::Face()
{
	//faceVertexListData = NULL;
}

Face::Face(int x, int y, int z)
{
	//faceVertexListData = NULL;
	faceVertexList.clear();
	faceVertexList.push_back(x);
	faceVertexList.push_back(y);
	faceVertexList.push_back(z);
}

Face::~Face()
{
}

void Face::push(int d)
{
	faceVertexList.push_back(d);
}

void Face::push(int x, int y, int z)
{
	faceVertexList.clear();
	faceVertexList.push_back(x);
	faceVertexList.push_back(y);
	faceVertexList.push_back(z);
}

int Face::size()
{
	return faceVertexList.size();
}

void Face::clear()
{
	faceVertexList.clear();
}

int& Face::operator[](int idx)
{
	return faceVertexList[idx];
}