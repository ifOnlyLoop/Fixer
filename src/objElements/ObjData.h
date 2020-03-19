#include "Vertex.h"
#include "Face.h"

class Vertex;
class Face;

class ObjData
{
public:
	 ObjData();
	~ObjData();

	bool isSub;

	// Mesh List of Verteces
	std::vector<Vertex> vertexList, normalList;
	// Mesh List of Faces
	std::vector<Face> faceList;
	// Temp Data to Save Face list of 
	// vertex indeces for processing 
	std::vector<int> faceVertexList;

private:

};
