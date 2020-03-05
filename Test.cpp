#include <stdio.h>
#include <iostream>

#include "MathUtil.h"
#include "vec3.h"
#include "eAng.h"
#include "rMat.h"

int main()
{ 
    vec3 v(3,1,0);
    printf("%f %f %f\n",v.x,v.y,v.z); 
    
    eAng a(0,0,kPiOver2);
    a.canonize();
    printf("%f %f %f\n",a.heading,a.pitch,a.bank); 
    
    rMat m; 
    m.identity();
    std::cout<<m.m11<<m.m12;
    m.set(a); 
    v=m.objectToInertial(v);
    printf("%f %f %f\n",v.x,v.y,v.z); 

	return 0;
}