#pragma once

#include <vector>
#include "vec3.h"

class Vertex : public vec3
{
public:

	 Vertex();
	~Vertex();
	 Vertex(vec3 v3);
	void push(vec3);
	//vec3& operator[](int idx);
	
	
private:
	//std::vector<vec3> vertex;
};
