#include "ObjFile.h"

ObjFile::ObjFile()
{
}
ObjFile::ObjFile(std::string filePath)
{
    ELEMENT = "";
    ELEMENT_C_STRING = NULL;
    x = y = z = 0.0f;
    u = 0.2f; 
    v = 0.7f;
    IMPORT(filePath);
}
ObjFile::~ObjFile()
{
}

/*
 * Read .obj File Data 
 */
void ObjFile::IMPORT(std::string filePath)
{
    // Set File Path
    IMPORT_PATH = filePath;
	// Open File
	obj.open(IMPORT_PATH);
	// Read Data
	read();
	// Close File
	obj.close();
}

void ObjFile::EXPORT(std::string filePath)
{
    // Set File Path
    EXPORT_PATH = filePath;
    // Open File
    objEXPORT.open(EXPORT_PATH);
    // Write Data
    write();
    // Close File
    objEXPORT.close();
}

/*
 * Store Data in the Suitasble c++ Format
 */
void ObjFile::read()
{
    while (!obj.eof())
    {
        // Get the First Element
        std::getline(obj, ELEMENT);
        // Stream the String
        info.str(ELEMENT);
        // Get Element Type
        info >> dataType;
        // Proccess Based on Type
        if (dataType == 'v')
            vertexHandler();
        if (dataType == 'f')
            faceHandler();
      
    }
}


void ObjFile::write()
{
    
    for (auto p : vertex)
    {
        objEXPORT << "v\t"<< p.x << "\t" << p.y << "\t" << p.z << std::endl;
    }
    for (auto f : face)
    {
        objEXPORT << "f\t";
        for (int i : f.face)
            objEXPORT << i+1 << "\t"; // from 0to1 index
        objEXPORT << std::endl;
    }
}

void ObjFile::vertexHandler()
{
    // Get Vertex Postion
    info >> x >> y >> z;
    // String to Float
    vData.push(stof(x), stof(y), stof(z));
    // Push the Postion
    vertex.push_back(vData);
    // Clear Buffer
    info.clear();
}
//
void ObjFile::faceHandler()
{
    // Get Verteces 
    std::string stringData;
    // Read Face Vertex Index in Vertex Data Member 
    while (info >> stringData)
        FaceVertex.push_back(stof(stringData)-1);
    // Polymesh to Trimesh
    triangulation(FaceVertex,1);
    // SubDivide the Trimesh
    //subDivision();
    // Clear 
    FaceVertex.clear();
}

void ObjFile::triangulation(std::vector<int>& FaceVertexArg,int mode=0)
{
    // Declare Mesh Pivot 
    int pivot = FaceVertexArg[0];
    // temp face datatype
    Face tempFace;
    // Size of the Polygon "n"
    int argSize = FaceVertexArg.size();
    for (int i = 1; i < argSize-1; i++)
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
            face.push_back(tempFace);
    }
}

// trangulate
void ObjFile::subDivision(Face& TriF)
{
    
    /* Equations
     * #1: uV1 + vV2 + wV3 = p(x,y,z) 
     * #2: u   + v   + w   = 1        
     */
        
    // Extract Segement Points
    vec3
        pivot = vertex[TriF[2]]
        + u * (vertex[TriF[0]] - vertex[TriF[2]])
        + v * (vertex[TriF[1]] - vertex[TriF[2]]);

    // Add to File Vertex List
    Vertex TriV;
    TriV.push(pivot);
    // Add to File Vertex List
    vertex.push_back(TriV);
    // Get Pivot Index in the Vertex List
    int j = vertex.size() - 1,
        z = TriF.size();
    // Push SubDivided Faces to Face List 
    for (int i = 0; i < z; i++)
        face.push_back(Face(j, TriF[i], TriF[(i + 1) % z]));
    
}



// over load with segments (constrain) segment
/*
void ObjFile::subDivision(Face& TriF)
{

     * Equations
     * #1: uV1 + vV2 + wV3 = p(x,y,z)
     * #2: u   + v   + w   = 1
     *

     // Extract Segement Points
vec3
pivot1 = vertex[TriF[2]]
+ u * (vertex[TriF[0]] - vertex[TriF[2]])
+ v * (vertex[TriF[1]] - vertex[TriF[2]]);

u = 0.4f;
v = 0.1f;

vec3
pivot2 = vertex[TriF[2]]
+ u * (vertex[TriF[0]] - vertex[TriF[2]])
+ v * (vertex[TriF[1]] - vertex[TriF[2]]);

// Add to File Vertex List
Vertex TriV1, TriV2;

TriV1.push(pivot1);
vertex.push_back(TriV1);
int i = vertex.size() - 1;

// sub Segement start
TriV2.push(pivot2);
vertex.push_back(TriV2);
int j = vertex.size() - 1;

vec3 parallelEdge = pivot1 - pivot2;
float cosValue = 0, tempCos = 0;
int k = 0, z = TriF.size();

for (int r = 0; r < z; r++)
{
    tempCos = fabs(parallelEdge * (vertex[TriF[r]] - vertex[TriF[(r + 1) % z]])) //vertex[(i)])) //
        / (
            norm(parallelEdge) *
            norm(vertex[TriF[r]] - vertex[(r + 1) % z])
            );

    if (tempCos - cosValue > 0.0f)
    {
        cosValue = tempCos;
        k = (r + 2) % z;//TriF[r];
    }
}

//face.push_back(Face(i, TriF[0], TriF[1]));
//sub Segment end

std::vector<int> divFace(4, 0);
int
iClosest = TriF[(k + 1) % z],
jClosest = TriF[(k + 2) % z];

if (dist(vertex[i], vertex[TriF[(k + 1) % z]]) <
    dist(vertex[i], vertex[TriF[(k + 2) % z]]))

    std::swap(iClosest, jClosest);

divFace[0] = i;
divFace[1] = iClosest;
divFace[2] = jClosest;
divFace[3] = j;

triangulation(divFace, 0);

//face.push_back(Face(i, j, TriF[k]));
//face.push_back(Face(i, iClosest, TriF[k]));
//face.push_back(Face(j, jClosest, TriF[k]));

divFace.clear();
}*/