#include <stdio.h>
#include <iostream>

#include "MathUtil.h"
#include "vec3.h"
#include "eAng.h"
#include "rMat.h"
#include "ObjFile.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono> 

using namespace std;
using namespace chrono;

int main()
{ 

    string line;
    string v, x, y, z;
    vec3 vvv;
    vector<vec3> vertexArray();
    
    int n = 0;
    auto start = high_resolution_clock::now();
    ObjFile obj("objTest.obj");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << duration.count() << endl;

     start = high_resolution_clock::now();
     obj.Export("objTestOut.obj");
     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);
    cout << endl << duration.count() << endl;
    
    
    system("pause");
	return 0;
}