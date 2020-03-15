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

void Face::triangulation(Face& face, ObjData objD)
{
    // Declare Mesh Pivot
    int pivot = face.faceVertexList[0];
    // temp face datatype
    Face tempFace;
    // Size of the Polygon "n"
    int argSize = face.faceVertexList.size();
    
    for (int i = 1; i < argSize - 1; i++)
    {
        tempFace.push
        (
            pivot,
            face.faceVertexList[i],
            face.faceVertexList[i + 1]
        );
        if (i & face.isSub)
            subDivision(tempFace, faceList);
        else
            faceList.push_back(tempFace);
    }
}


void Face::subDivision(Face& triface, std::vector<Face>& faceList, float u, float v)
{

    /* Equations
     * #1: uV1 + vV2 + wV3 = p(x,y,z)
     * #2: u   + v   + w   = 1
     */
    
     // Extract Segement Points
    vec3
        pivot = face.faceVertexList[TriF[2]]
        + u * (face.faceVertexList[TriF[0]] - face.faceVertexList[TriF[2]])
        + v * (face.faceVertexList[TriF[1]] - face.faceVertexList[TriF[2]]);

    // Add to File Vertex List
    Vertex TriV;
    TriV.push(pivot);
    // Add to File Vertex List
    vertexList.push_back(TriV);
    // Get Pivot Index in the Vertex List
    int j = vertexList.size() - 1,
        z = TriF.size();
    // Push SubDivided Faces to Face List 
    for (int i = 0; i < z; i++)
        faceList.push_back(Face(j, TriF[i], TriF[(i + 1) % z]));
}