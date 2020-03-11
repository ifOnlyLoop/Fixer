#pragma once

#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "vec3.h"
#include "Vertex.h"
#include "Face.h"

class Vertex;
class Face;

class ObjFile
{
private:
	// PRIVATE MEMBER DATATYPES //

	std::string
		// Path of .obj Import File
		IMPORT_PATH,
		// Path of .obj Export File
		EXPORT_PATH,
		// Geometric Element
		ELEMENT;
	char * 
		// c String Version
		ELEMENT_C_STRING;

	/*
	 * START OF Temp DATA 
	 */

	Vertex  // Vertex Dummy Info (string streaming)
		vData;
	std::string  // Vertex Dummy Position
		x, y, z;
	char   // .obj Geometric Data Type 
		dataType;
	std::vector<int> FaceVertex;
	/*
	 * END OF DUMMY DATA
	 */
	
	// Set the .obj Import File
	std::ifstream obj;
	// Set the .obj Export File
	std::ofstream objEXPORT;
	// Set Element Data
	std::stringstream info;
	
	// PRIVATE MEMBER FUNCTIONS //

	// Read From .obj Data
	void read();
	// Write to .obj Data
	void write();
	// Handle Vertex
	void vertexHandler();
	// Handle Face
	void faceHandler();
	// Triangulate Polygons
	void triangulation(std::vector<int>&, int mode);
	// 
	void subDivision(Face& TriF);

public:
	// Constrtuctor
	 ObjFile();
	~ObjFile();
	 ObjFile(std::string);
	// PUBLIC MEMBER FUNCTIONS //
	void IMPORT(std::string);
	void EXPORT(std::string);
	// PUBLIC MEMBER DATATYPES //
	std::vector<Vertex> vertex;
	std::vector<Face> face;
	// Traingulation Parameter
	float u, v;
	//std::vector<int>  face;
};

