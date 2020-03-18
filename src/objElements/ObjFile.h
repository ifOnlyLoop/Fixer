#pragma once

// STL
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
// UD
#include"./Vertex.h"
#include"Face.h"
#include"ObjData.h"
class Vertex;
class Face;
class ObjData;


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
	
	Vertex  // Vertex Dummy Info for String Streaming
		vertexPosition;
	std::string  // Vertex Dummy Position for String Streaming
		x, y, z, faceVertexIndex;
	char   // .obj Geometric Data Type for String Streaming
		dataType;

	/*
	 * END OF DUMMY DATA
	 */
	
	// Set the .obj Import File Reader
	std::ifstream obj;
	// Set Geometric Element Data Reader
	std::stringstream info;
	// Set the .obj Export File
	std::ofstream objEXPORT;
	
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
	// Constrtuctor //
	 ObjFile();
	~ObjFile();
	 ObjFile(std::string);

	// PUBLIC MEMBER FUNCTIONS //
	void IMPORT(std::string);
	void EXPORT(std::string);

	// PUBLIC MEMBER DATATYPES //
	std::vector<Vertex> vertexList;
	std::vector<Face> faceList;
	// .obj File Extracted Data
	ObjData Data;
	// Traingulation Parameter
	float u, v;
	
};
