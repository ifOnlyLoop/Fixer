#pragma once

#include <vector>
#include "vec3.h"

class Vertex : public vec3
{
public:

	 Vertex();
	~Vertex();
	 Vertex(float x, float y, float z);
	
	 void push(vec3);
	 void push(float x, float y, float z);
	//vec3& operator[](int idx);
	
	
private:
	//std::vector<vec3> vertex;
};
