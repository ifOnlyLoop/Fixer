#include "ObjFile.h"

ObjFile::ObjFile()
{
}
ObjFile::ObjFile(std::string filePath)
{
    ELEMENT = "";
    ELEMENT_C_STRING = NULL;
    x = y = z = 0.0f;
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
    info >> x >> y >> z;
    vData.push(stof(x), stof(y), stof(z));
    vertex.push_back(vData);
    info.clear();
}
//
void ObjFile::faceHandler()
{
    int sizeQ = 0, i = -1, pivotVertex = 0;
    std::queue<int> triQ;
    std::string 
        vertexData, 
        triangulationVertex;

    info >> triangulationVertex; // First Vertex
    pivotVertex = stoi(triangulationVertex) - 1;
    
    while (info >> vertexData)
    {   
        triQ.push(stoi(vertexData)-1);
        sizeQ++;
        if (sizeQ & 2)
        {   
            Face triF;
            triF.push(pivotVertex);
            triF.push(triQ.front());
            triF.push(triQ.back());
            i++;
            face.push_back(triF);
            triQ.pop();
        }
    }
}
// trangulate
void ObjFile::triangulation()
{

}