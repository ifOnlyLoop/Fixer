#ifndef EANG_H
#define EANG_H

#include"MathUtil.h" 

class rMat;

//---------------------------------------------------------------------------
// class eAng
//
// This class represents a heading-pitch-bank Euler angle triple.
class eAng {
public:
	// Public data
	// Straightforward representation. Store the three angles, in
	// radians
	float heading;
	float pitch;
	float bank;

	// Public operations
	// Default constructor does nothing
	eAng();

	// Construct from three values
	eAng(float h, float p, float b);

	// Set to identity triple (all zeros)
	void identity();
	 
	// Determine "canonical" Euler angle triple
	void canonize();
	 
	// Convert a rotation matrix to Euler Angle form.
	void fromRotationMatrix(const rMat& m);
};
// A global "identity" Euler angle constant
const eAng keAngIdentity;
#endif