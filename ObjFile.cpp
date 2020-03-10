#include "ObjFile.h"

#include <string>

#include <iostream>
#include <sstream>

#include "vec3.h"

ObjFile::ObjFile()
{
}
ObjFile::ObjFile(std::string filePath)
{
    import(filePath);
}
ObjFile::~ObjFile()
{
}

/*
 * Read .obj File Data 
 */
void ObjFile::import(std::string filePath)
{
    // Set File Path
    PATH = filePath;
	// Open File
	obj.open(PATH);
	// Read Data
	read();
	// Close File
	obj.close();
}

void ObjFile::Export(std::string filePath)
{
    // Set File Path
    EXPORT_PATH = filePath;
    // Open File
    objExport.open(EXPORT_PATH);
    // Read Data
    write();
    // Close File
    objExport.close();
}

/*
 * Store Data in the Suitasble c++ Format
 */
void ObjFile::read()
{
    std::string line, v, x, y, z;
    Vertex v3;


    int vv = 0, ff = 0;
    while (!obj.eof())
    {
        // Get the First Element
        std::getline(obj, line);
        // Process the Element 
        std::stringstream info(line);
        // Get Element Type
        info >> v;
        // Proccess Based on Type

        if (v[0] == 'v')
        {
            vv++;
            info >> x >> y >> z;

                v3.x = std::stof(z),
                v3.y = std::stof(y),
                v3.z = std::stof(z);
            
                vertex.push_back(v3);
            //std::cout << v << "\t" << x << "\t" << y << "\t" << z << std::endl;
        }
        if (v[0] == 'f') ff++;

    }
    /*for (auto p : vertex)
    {
        std::cout << p.x << "\t" << p.y << "\t" << p.z << std::endl;
    }*/
    std::cout << vv << " " << ff;
}


void ObjFile::write()
{
    
    /*for (auto p : vertex)
    {
        objExport << "v\t"<< p.x << "\t" << p.y << "\t" << p.z << std::endl;
    }*/
}