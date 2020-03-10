#include "Vertex.h"


Vertex::Vertex(vec3 v3)
{
	this->x = v3.x;
	this->y = v3.y;
	this->z = v3.z;
}

Vertex::~Vertex()
{
}

/*vec3& Vertex::operator[](int idx)
{
	return vertex[idx];
}
*/
void Vertex::push(vec3 v3)
{
	this->x = v3.x;
	this->y = v3.y;
	this->z = v3.z;
}