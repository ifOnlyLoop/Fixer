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
	std::string//char   // .obj Geometric Data Type for String Streaming
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
	void vertexHandler(bool);
	// Handle Face
	void faceHandler();
	// split face's normal and vertex index
	void objElementSplit(std::string&);

public:
	// Constrtuctor //
	 ObjFile();
	~ObjFile();
	 ObjFile(std::string);

	// PUBLIC MEMBER FUNCTIONS //
	void IMPORT(std::string);
	void EXPORT(std::string);
	void ROTATE(float, float, float);
	// PUBLIC MEMBER DATATYPES //
	std::vector<Vertex> vertexList;
	std::vector<Face> faceList;
	// .obj File Extracted Data
	ObjData Data;
	// Traingulation Parameter
	float u, v;
	
};

