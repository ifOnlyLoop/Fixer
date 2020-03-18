#ifndef MATHUTILS_H
#define MATHUTILS_H

// Declare a global constant for pi and a few multiples.
const static float kPi = 3.14159265f;
const static float k2Pi = kPi * 2.0f;
const static float kPiOver2 = kPi / 2.0f;
const static float k1OverPi = 1.0f / kPi;
const static float k1Over2Pi = 1.0f / k2Pi;

// "Wrap" an angle in range �pi...pi by adding the correct multiple
// of 2 pi
float wrapPi(float theta);

// "Safe" inverse trig functions
float safeAcos(float x);

// Compute the sin and cosine of an angle. On some platforms, if we know
// that we need both values, it can be computed faster than computing
// the two values seperately.
void sinCos(float& returnSin, float& returnCos, float theta);

#endif // MATHUTILS_H
