#pragma once

#include<vector>
#include<string>
#include <fstream>


#include"Vertex.h"


//class Vertex;
class Face;

class ObjFile
{
private:
	// Path of Last .obj File
	std::string PATH, EXPORT_PATH;
	// Set the .obj File
	std::ifstream obj;
	//
	std::ofstream objExport;
	// Read From .obj Data
	void read();
	// Write to .obj Data
	void write();

public:
	 ObjFile();
	~ObjFile();
	 ObjFile(std::string);

	void import(std::string);
	void Export(std::string filePath);

	std::vector<Vertex> vertex;
	//std::vector<Face> face;
	//std::vector<int>  face;

;
	
};

