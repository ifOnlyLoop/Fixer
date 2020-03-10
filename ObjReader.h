#ifndef OBJREADER_H
#define OBJREADER_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "vec3.h"

class ObjData;

class ObjReader
{
public:
	// Constructor 
	  ObjReader(std::string path);
	 ~ObjReader();
	// Read File Data
	void readData();

private:
	// .obj File
	std::ifstream obj;
	// List of Verteces
	std::vector<vec3> vertex;
};
#endif