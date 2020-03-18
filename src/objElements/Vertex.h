#pragma once

#include <vector>
#include "../transforms/vect.h"

class Vertex : public vect
{
public:

	 Vertex();
	~Vertex();
	 Vertex(float x, float y, float z);
	
	 void push(vect);
	 void push(float x, float y, float z);
	//vect& operator[](int idx);
	
	
private:
	//std::vector<vect> vertex;
};
