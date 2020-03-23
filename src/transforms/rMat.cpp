#include "rmat.h"
#include <math.h>

rmat::rmat()
{
    m11 = m22 = m33 = 1;
    m12 = m13 = m21 = m23 = m31 = m32 = 0;
}

rmat::~rmat()
{
}

void rmat::orientation(float heading, float pitch, float bank)
{
	canonize(heading, pitch, bank);

    float sh = 0, ch = 0, sp = 0, cp = 0, sb = 0, cb = 0;
    sinCos(sh, ch, heading);
    sinCos(sp, cp, pitch);
    sinCos(sb, cb, bank);

    // Fill in the matrix elements
    m11 = ch * cb + sh * sp * sb;
    m12 = -ch * sb + sh * sp * cb;
    m13 = sh * cp;
    m21 = sb * cp;
    m22 = cb * cp;
    m23 = -sp;
    m31 = -sh * cb + ch * sp * sb;
    m32 = sb * sh + ch * sp * cb;
    m33 = ch * cp;
}

void rmat::rotate(/*const*/ vect& v)
{
    // Perform the matrix multiplication in the "standard" way.
    v.x = m11 * v.x + m21 * v.y + m31 * v.z;
    v.y = m12 * v.x + m22 * v.y + m32 * v.z;
    v.z = m13 * v.x + m23 * v.y + m33 * v.z;
}

// Determine "canonical" Euler angle triple
void rmat::canonize(float& heading, float& pitch, float& bank)
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