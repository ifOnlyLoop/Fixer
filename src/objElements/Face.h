#pragma once

#include <vector>
#include"Vertex.h"

class Vertex;

class Face
{
public:
	 Face();
	~Face();
	 // Tri Face
	 Face(int x, int y, int z);
	
	 // Get This Face Number of  Verteces
	 int size();
	 // Clear Vertex List
	 void clear();
	 // Get This Polygon Face Vertex by Index 
	 int& operator[](int idx);

	// Push Vertex Number in Polygons 
	void push(int);
	// Push Tri Face Verteces
	void push(int x, int y, int z);
	// List of This Face Verteces
	std::vector<int> faceVertexList;
	// List of This Face Verteces Data
	bool isSub;
	// std::vector<Vertex>& vertexListData;
	

private:
	
};
