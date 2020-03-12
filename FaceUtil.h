#pragma once

#include"Vertex.h"
#include"Face.h"
#include"ObjFile.h"

class Vertex;
class Face;

class FaceUtil
{
public:
	 FaceUtil();
	~FaceUtil();

	void process(ObjFile&, std::vector<int>&);
	void triangulation(std::vector<int>&, int mode);
	// 
	void subDivision(Face& TriF);

private:

};
