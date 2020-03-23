#include "vect.h"
#include<math.h>

//using namespace vect;
/* Constructors */

// Default constructor
vect::vect() :x(0), y(0), z(0), w(0)
{
}

// Copy constructor
vect::vect(const vect& a) : 
	x(a.x),
	y(a.y),
	z(a.z),
	w(a.w)
{
}

// Construct given three values
vect::vect(float nx, float ny, float nz) :
	x(nx), y(ny), z(nz) 
{
}

// Standard object maintenance
// return reference to the lvalue
vect& vect::operator =(const vect& a)
{
	x = a.x; y = a.y; z = a.z;
	return *this;
}

/* Boolian Operations */
bool vect::operator ==(const vect& a) const
{
	return x == a.x && y == a.y && z == a.z;
}

bool vect::operator !=(const vect& a) const
{
	return x != a.x || y != a.y || z != a.z;
}

/* Vector operations */

// Set the vector to zero
void vect::zero() 
{ 
	x = y = z = 0.0f;
}
	
// Unary minus returns the negative of the vector
vect vect::operator -() const 
{ 
	return vect(-x, -y, -z);
}

// Binary + and - add and subtract vectors
vect vect::operator +(const vect& a) const
{
	return vect(x + a.x, y + a.y, z + a.z);
}

vect vect::operator -(const vect& a) const 
{
	return vect(x - a.x, y - a.y, z - a.z);
}
	
// Multiplication and division by scalar
vect vect::operator *(float a) const 
{
	return vect(x * a, y * a, z * a);
}

vect vect::operator /(float a) const 
{
	float oneOverA = 1.0f / a; // NOTE: no check for divide by zero here ADD TRY CATCH
	return vect(x * oneOverA, y * oneOverA, z * oneOverA);
}

/* Assignment operations */

vect& vect::operator +=(const vect& a) 
{
	x += a.x; y += a.y; z += a.z;
	return *this;
}

vect& vect::operator -= (const vect& a) 
{
	x -= a.x; y -= a.y; z -= a.z;
	return *this;
}

vect& vect::operator *=(float a)
{
	x *= a; y *= a; z *= a;
	return *this;
}

vect& vect::operator /=(float a) 
{
	float oneOverA = 1.0f / a; // NOTE: no check for divide by zero here ADD TRY CATCH
	x *= oneOverA; y *= oneOverA; z *= oneOverA;
	return *this;
}

/* Normalize the vector */

void vect::normalize()
{
	float magSq = x * x + y * y + z * z;
	if (magSq > 0.0f) { // check for divide-by-zero
		float oneOverMag = 1.0f / sqrt(magSq);
		x *= oneOverMag; y *= oneOverMag; z *= oneOverMag;
	}
}

// rotate here 


/* Vector dot product */
float vect::operator *(const vect& a) const
{ // overload
	return x * a.x + y * a.y + z * a.z;
}


/*
 * Nonmember functions
 */

 // Compute the magnitude of a vector vectorMag
float norm(const vect& a) 
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

// Compute the cross product of two vectors
vect cross(const vect& a, const vect& b)
{
	return vect(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

// Scalar on the left multiplication, for symmetry
vect operator *(float k, const vect& v) 
{
	return vect(k * v.x, k * v.y, k * v.z);
}

// Compute the distance between two points
float dist(const vect& a, const vect& b) 
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
} 
