#ifndef RMAT_H
#define RMAT_H
 
#include"MathUtil.h"

/* Forward Decleration*/
class vec3;
class eAng;

//---------------------------------------------------------------------------
// class RotationMatrix
//
// matrix is assumed to be orthogonal. The direction of transformation
// is specified at the time of transformation.
class rMat 
{
public:
	float 	m11, m12, m13,
			m21, m22, m23,
			m31, m32, m33;
	
	/* Public operations */
	
	// Set to identity
	void identity();
	
	// Setup the matrix with a specified orientation
	void set(const eAng& orientation);
	// Perform vector/point rotations
	// rMat::inertialToObject
//
// Rotate a vector from inertial to object space
	vec3 inertialToObject(const vec3& v);
	//---------------------------------------------------------------------------
	// rMat::objectToInertial
	//
	// Rotate a vector from object to inertial space
	vec3 objectToInertial(const vec3& v);
};
#endif