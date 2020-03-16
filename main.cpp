#include <stdio.h>
#include <iostream>

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono> 

#include "ObjFile.h"

using namespace std;
using namespace chrono;

int main()
{ 

    int n = 0;
    auto start = high_resolution_clock::now();
    ObjFile obj("objTest.obj");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << duration.count() << endl;

     start = high_resolution_clock::now();
     obj.EXPORT("RESULT.obj");
     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);
     cout << endl << duration.count() << endl;
    
    
    system("pause");
	return 0;
}