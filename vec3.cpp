#include "vec3.h"
#include<math.h>

/* Constructors */

// Default constructor
vec3::vec3() :x(0), y(0), z(0) 
{
}

// Copy constructor
vec3::vec3(const vec3& a) : 
	x(a.x),
	y(a.y),
	z(a.z) 
{
}

// Construct given three values
vec3::vec3(float nx, float ny, float nz) :
	x(nx), y(ny), z(nz) 
{
}

// Standard object maintenance
// return reference to the lvalue
vec3& vec3::operator =(const vec3& a)
{
	x = a.x; y = a.y; z = a.z;
	return *this;
}

/* Boolian Operations */
bool vec3::operator ==(const vec3& a) const
{
	return x == a.x && y == a.y && z == a.z;
}

bool vec3::operator !=(const vec3& a) const
{
	return x != a.x || y != a.y || z != a.z;
}

/* Vector operations */

// Set the vector to zero
void vec3::zero() 
{ 
	x = y = z = 0.0f;
}
	
// Unary minus returns the negative of the vector
vec3 vec3::operator -() const 
{ 
	return vec3(-x, -y, -z);
}

// Binary + and - add and subtract vectors
vec3 vec3::operator +(const vec3& a) const
{
	return vec3(x + a.x, y + a.y, z + a.z);
}

vec3 vec3::operator -(const vec3& a) const 
{
	return vec3(x - a.x, y - a.y, z - a.z);
}
	
// Multiplication and division by scalar
vec3 vec3::operator *(float a) const 
{
	return vec3(x * a, y * a, z * a);
}

vec3 vec3::operator /(float a) const 
{
	float oneOverA = 1.0f / a; // NOTE: no check for divide by zero here ADD TRY CATCH
	return vec3(x * oneOverA, y * oneOverA, z * oneOverA);
}

/* Assignment operations */

vec3& vec3::operator +=(const vec3& a) 
{
	x += a.x; y += a.y; z += a.z;
	return *this;
}

vec3& vec3::operator -= (const vec3& a) 
{
	x -= a.x; y -= a.y; z -= a.z;
	return *this;
}

vec3& vec3::operator *=(float a)
{
	x *= a; y *= a; z *= a;
	return *this;
}

vec3& vec3::operator /=(float a) 
{
	float oneOverA = 1.0f / a; // NOTE: no check for divide by zero here ADD TRY CATCH
	x *= oneOverA; y *= oneOverA; z *= oneOverA;
	return *this;
}

/* Normalize the vector */

void vec3::normalize()
{
	float magSq = x * x + y * y + z * z;
	if (magSq > 0.0f) { // check for divide-by-zero
		float oneOverMag = 1.0f / sqrt(magSq);
		x *= oneOverMag; y *= oneOverMag; z *= oneOverMag;
	}
}

/* Vector dot product */
float vec3::operator *(const vec3& a) const
{ // overload
	return x * a.x + y * a.y + z * a.z;
}


/*
 * Nonmember functions
 */

 // Compute the magnitude of a vector vectorMag
float norm(const vec3& a) 
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

// Compute the cross product of two vectors
vec3 cross(const vec3& a, const vec3& b)
{
	return vec3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

// Scalar on the left multiplication, for symmetry
vec3 operator *(float k, const vec3& v) 
{
	return vec3(k * v.x, k * v.y, k * v.z);
}

// Compute the distance between two points
float dist(const vec3& a, const vec3& b) 
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
} 
