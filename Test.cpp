#include <stdio.h>
#include <iostream>

#include "MathUtil.h"
#include "vec3.h"
#include "eAng.h"
#include "rMat.h"

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{ 

    string line;
    int x, y, z;
    string v, valuesX[8], valuesY[8], valuesZ[8];
    int n = 0;

    ifstream obj("objTest.obj");
    vector<vec3> poi;

    while (!obj.eof())
    {
        getline(obj, line);
        obj >> v;
        cout << v;
        if (0&&line[0] == 'v')
            {
                obj >> v >> valuesX[n] >> valuesY[n] >> valuesZ[n];
                cout << v << "\t" << valuesX[n] << "\t" << valuesY[n] << "\t" << valuesZ[n] << endl;
                n++;
            }
        
        //cout <<"T\t"<< line <<endl;
        //
    }
    
    /*
    vec3 v(3,1,0);
    printf("%f %f %f\n",v.x,v.y,v.z); 
    
    eAng a(0,0,kPiOver2/2);
    a.canonize();
    printf("%f %f %f\n",a.heading,a.pitch,a.bank); 
    
    rMat m; 
    m.identity();
    //std::cout<<m.m11<<m.m12;
    m.set(a); 
    v=m.objectToInertial(v);
    printf("%f %f %f\n",v.x,v.y,v.z); */
    system("pause");
	return 0;
}