#pragma once

#include <vector>

#include"vec3.h"
class vec3;

class Face
{
public:
	 Face();
	~Face();
	 Face(int x, int y, int z);
	
	 int size() { return face.size(); }
	int& operator[](int idx);

	void push(int);
	void push(int x, int y, int z);
	std::vector<int> face;
private:
	
};
