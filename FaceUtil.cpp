#include "FaceUtil.h"


FaceUtil::FaceUtil()
{
}

FaceUtil::~FaceUtil()
{
}

void FaceUtil::process(ObjFile& obj, std::vector<int>& faceVertexList)
{
    triangulation(obj.)
}

void FaceUtil::triangulation(std::vector<int>& FaceVertexArg, int mode = 0)
{
    // Declare Mesh Pivot 
    int pivot = FaceVertexArg[0];
    // temp face datatype
    Face tempFace;
    // Size of the Polygon "n"
    int argSize = FaceVertexArg.size();
    for (int i = 1; i < argSize - 1; i++)
    {
        tempFace.push
        (
            pivot,
            FaceVertexArg[i],
            FaceVertexArg[i + 1]
        );
        if (i & mode)
            subDivision(tempFace);
        else
            faceList.push_back(tempFace);
    }
}

// trangulate
void FaceUtil::subDivision(Face& TriF)
{

    /* Equations
     * #1: uV1 + vV2 + wV3 = p(x,y,z)
     * #2: u   + v   + w   = 1
     */

     // Extract Segement Points
    vec3
        pivot = vertexList[TriF[2]]
        + u * (vertexList[TriF[0]] - vertexList[TriF[2]])
        + v * (vertexList[TriF[1]] - vertexList[TriF[2]]);

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
