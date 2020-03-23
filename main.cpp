//#include <stdio.h>
#include <iostream>

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono> 

#include "./quat.h"
#include "./src/objElements/ObjFile.h"

using namespace std;
using namespace chrono;

int main()
{ 

    int n = 0;
    // measure import time
    auto start = high_resolution_clock::now();
    // import file
    ObjFile obj("objTest1.obj");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << duration.count() / 1e6 << endl;
    
    
    // Rotate
    start = high_resolution_clock::now();
    //for (int i = 0; i < 37; i++)
    {
        //obj.ROTATE(1+i,0.5*i,7.0/i);
    }
    obj.ROTATE(1,1,1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << endl << duration.count() / 1e6 << endl;
    
    // measure export time
    start = high_resolution_clock::now();
    // export file
    obj.EXPORT("objRes.obj");
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << endl << duration.count() / 1e6 << endl;
    
    
    system("pause");
	return 0;
}