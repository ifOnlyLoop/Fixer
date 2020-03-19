#include "ObjFile.h"
#include "FaceUtil.h"
#include "../transforms/rmat.h"
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
        // Split Vertex//Normal Index
        objElementSplit(ELEMENT);
        // Stream to String Buffer
        info.str(ELEMENT);
        // Get Element Type
        info >> dataType;
        // Proccess Based on Type
        if (dataType == "v")
            vertexHandler(0);
        if (dataType == "vn")
            vertexHandler(1);
        if (dataType == "f")
            faceHandler();
        // Clear Buffer
        info.clear();
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
    for (auto p : Data.vertexList)
    {
        objEXPORT << "v\t" << p.x << "\t" << p.y << "\t" << p.z << std::endl;
    }
    for (auto p : Data.normalList)
    {
        objEXPORT << "vn\t"<< p.x << "\t" << p.y << "\t" << p.z << std::endl;
    }
    for (auto f : Data.faceList)
    {
        objEXPORT << "f\t";
        for (int i : f.faceVertexList)
        {
            objEXPORT << i + 1 << "//" << Data.vertexList[i].NORMAL_INDEX <<"\t"; // from 0to1 index
        }
        objEXPORT << std::endl;
    }
}

void ObjFile::vertexHandler(bool isNormal=0)
{
    // Get Vertex Postion
    info >> x >> y >> z;
    // String to Float
    vertexPosition.push(stof(x), stof(y), stof(z));
    // Push the Postion
    if(isNormal)
        Data.normalList.push_back(vertexPosition);
    else
        Data.vertexList.push_back(vertexPosition);
    // Clear Buffer for Next Reading
    info.clear();
}
//
void ObjFile::faceHandler()
{
    Face tempFace;
    // EVEN: vertex ODD: normal
    int vertexOrNormal = 0;
    // Read Face Vertex Index List
    while (info >> faceVertexIndex)
    {
        if (vertexOrNormal & 1)
            Data.vertexList[tempFace.faceVertexList.back()].NORMAL_INDEX = stoi(faceVertexIndex) - 1;
        else // link vertex with its normal
            tempFace.push(stoi(faceVertexIndex) - 1);
        vertexOrNormal++;
    }
        
    // Process Face
    Data.faceList.push_back(tempFace);
    FaceUtil().triangulation(Data.faceList.size() - 1, Data);
    // Clear temp Data for next Iteration
    tempFace.clear();
}

void ObjFile::ROTATE(float h, float p, float b)
{
    rmat rotM;
    rotM.orientation(h, p, b);
    for (auto &v : Data.vertexList)
        rotM.rotate(v);
    for (auto& v : Data.normalList)
        rotM.rotate(v);
}


void ObjFile::objElementSplit(std::string& s)
{
    for (char& c : s)
        if (c == '/') c = ' ';
}


