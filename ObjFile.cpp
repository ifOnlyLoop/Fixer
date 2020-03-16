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

/*
 * Store Data in the Suitasble c++ Format
 */
void ObjFile::read()
{
    while (!obj.eof())
    {
        // Get the First Element
        std::getline(obj, ELEMENT);
        // Stream to String Buffer
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


void ObjFile::write()
{
    std::cout<<"VOAM";
    for (auto p : Data.vertexList)
    {
        objEXPORT << "v\t"<< p.x << "\t" << p.y << "\t" << p.z << std::endl;
    }
    for (auto f : Data.faceList)
    {
        objEXPORT << "f\t";
        for (int i : f.faceVertexList)
        {
            objEXPORT << i + 1 << "\t"; // from 0to1 index
        }
        objEXPORT << std::endl;
    }
}

void ObjFile::vertexHandler()
{
    // Get Vertex Postion
    info >> x >> y >> z;
    // String to Float
    vertexPosition.push(stof(x), stof(y), stof(z));
    // Push the Postion
    Data.vertexList.push_back(vertexPosition);
    // Clear Buffer for Next Reading
    info.clear();
}
//
void ObjFile::faceHandler()
{
    Face tempFace;
    // Read Face Vertex Index List
    while (info >> faceVertexIndex) 
        tempFace.push(stoi(faceVertexIndex)-1);
    tempFace.clear();
}
