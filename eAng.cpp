#include "eAng.h"
#include "rMat.h"
#include <math.h>

// Public operations
	// Default constructor does nothing
eAng::eAng() 
{
}

// Construct from three values
eAng::eAng(float h, float p, float b) :
	heading(h), pitch(p), bank(b) 
{
}

// Set to identity triple (all zeros)
void eAng::identity()
{ 
	pitch = bank = heading = 0.0f; 
}

// Determine "canonical" Euler angle triple
void eAng::canonize()
{
	// First, wrap pitch in range -pi ... pi
	pitch = wrapPi(pitch);
	// Now, check for "the back side" of the matrix pitch outside
	// the canonical range of -pi/2 ... pi/2

	if (pitch < -kPiOver2) {
		pitch = -kPi - pitch;
		heading += kPi;
		bank += kPi;
	}
	else if (pitch > kPiOver2) {
		pitch = kPi - pitch;
		heading += kPi;
		bank += kPi;
	}
	// Now check for the gimbel lock case (within a slight tolerance)
	if (fabs(pitch) > kPiOver2 - 1e-4) 
	{
		// We are in gimbel lock. Assign all rotation
		// about the vertical axis to heading
		heading += bank;
		bank = 0.0f;
	}
	else {
		// Not in gimbel lock. Wrap the bank angle in
		// canonical range
		bank = wrapPi(bank);
	}
	// Wrap heading in canonical range
	heading = wrapPi(heading);
}
 
// Convert a rotation matrix to Euler Angle form.
void eAng::fromRotationMatrix(const rMat& m)
{
	// Extract sin(pitch) from m23.
	float sp = -m.m23;
	// Check for Gimbel lock
	if (fabs(sp) > 0.9999f) {
		// Looking straight up or down
		pitch = kPiOver2 * sp;
		// Compute heading, slam bank to zero
		heading = atan2(-m.m31, m.m11);
		bank = 0.0f;
	}
	else {
		// Compute angles. We don't have to use the "safe" asin
		// function because we already checked for range errors when
		// checking for Gimbel lock
		heading = atan2(m.m13, m.m33);
		pitch = asin(sp);
		bank = atan2(m.m21, m.m22);
	}
}