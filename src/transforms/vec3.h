#ifndef VEC3_H
#define VEC3_H

// class vec3 a simple 3D vector class
class vec3 { // float: Data Type 

public:
	// Public representation: Not many options here.
	float x, y, z;
	bool isRowVector = 1;

	/* Constructors */

	// Default constructor
	vec3();

	// Copy constructor
	vec3(const vec3& a);

	// Construct given three values
	vec3(float nx, float ny, float nz);

	// Standard object maintenance
	// return reference to the lvalue
	vec3& operator =(const vec3& a);

	/* Boolian Operations */ 
	bool operator ==(const vec3& a) const;
	bool operator !=(const vec3& a) const;

	/* Vector operations */

	// Set the vector to zero
	void zero();

	// Unary minus returns the negative of the vector
	vec3 operator -() const;

	// Binary + and - add and subtract vectors
	vec3 operator +(const vec3& a) const;
	vec3 operator -(const vec3& a) const;

	// Multiplication and division by scalar
	vec3 operator *(float a) const;
	vec3 operator /(float a) const;

	/* Assignment operations */ 
	vec3& operator +=(const vec3& a);
	vec3& operator -= (const vec3& a);
	vec3& operator *=(float a);
	vec3& operator /=(float a);

	/* Normalize the vector */ 
	void normalize();

	/* Vector dot product */
	float operator *(const vec3& a) const;
};
 
/*
 * Nonmember functions
 */

 // Compute the magnitude of a vector vectorMag
float norm(const vec3& a);

// Compute the cross product of two vectors
vec3 cross(const vec3& a, const vec3& b);

// Scalar on the left multiplication, for symmetry
vec3 operator *(float k, const vec3& v);

// Compute the distance between two points
float dist(const vec3& a, const vec3& b);

/*
 *Global variables
 */

 // We provide a global zero vector constant
const vec3 kZeroVector;

#endif // VEC3_H
