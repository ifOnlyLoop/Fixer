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

	std::vector<Vertex> vertexList;
	std::vector<Face> faceList;
	std::vector<int> faceVertexList;

private:

};
