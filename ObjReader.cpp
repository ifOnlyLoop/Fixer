#include"ObjReader.h"
#include"vec3.h"
//#include<string>
ObjReader::ObjReader(std::string filePath)
{
    // Initialize Data
    //*vertex = &vertexArray;
    // Open File
	obj.open(filePath);
    // Read Data
	readData();
    // Close File
	obj.close();
}

ObjReader::~ObjReader()
{
}

void ObjReader::readData()
{
    std::string line, v, x, y, z;
    vec3 v3(0,0,0);


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
    for (auto p : vertex)
    {
        std::cout << p.x << "\t" << p.y << "\t" << p.z << std::endl;
    }
    std::cout << vv << " " << ff;
}
