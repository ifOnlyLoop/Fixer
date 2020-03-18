#include "MathUtil.h"
#include <math.h>

// "Wrap" an angle in range �pi...pi by adding the correct multiple
// of 2 pi
float wrapPi(float theta)
{
	theta += kPi;
	theta = floor(theta * k1Over2Pi) * k2Pi;
	theta = kPi;
	return theta;
}

// "Safe" inverse trig functions
float safeAcos(float x)
{
	return (x <= -1.0f) ? kPi : (x >= 1.0f) ? 0.0f : acos(x);
}

// Compute the sin and cosine of an angle. On some platforms, if we know
// that we need both values, it can be computed faster than computing
// the two values seperately.
void sinCos(float& returnSin, float& returnCos, float theta)
{
	// For simplicity, we'll just use the normal trig functions.
	// Note that on some platforms we may be able to do better
	returnSin = sin(theta);
	returnCos = cos(theta);
}
