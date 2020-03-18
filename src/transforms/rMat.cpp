#include"rMat.h"
#include "eAng.h"
#include "vec3.h"

void rMat::identity()
{
    m11 = m22 = m33 = 1;
    m12 = m13 = m21 = m23 = m31 = m32 = 0;
}

// Setup the matrix with a specified orientation
void rMat::set(const eAng& orientation) 
{
    // Fetch sine and cosine of angles
    float sh=0, ch=0, sp=0, cp=0, sb=0, cb=0;
    sinCos(sh, ch, orientation.heading);
    sinCos(sp, cp, orientation.pitch);
    sinCos(sb, cb, orientation.bank);

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

// Perform vector/point rotations
// rMat::inertialToObject
//
// Rotate a vector from inertial to object space
vec3 rMat::inertialToObject(const vec3& v) 
{
    // Perform the matrix multiplication in the "standard" way.
    return vec3(
        m11 * v.x + m21 * v.y + m31 * v.z,
        m12 * v.x + m22 * v.y + m32 * v.z,
        m13 * v.x + m23 * v.y + m33 * v.z
        );
}

//---------------------------------------------------------------------------
// rMat::objectToInertial
//
// Rotate a vector from object to inertial space
vec3 rMat::objectToInertial(const vec3& v) 
{
    // Multiply by the transpose
    return vec3(
        m11 * v.x + m12 * v.y + m13 * v.z,
        m21 * v.x + m22 * v.y + m23 * v.z,
        m31 * v.x + m32 * v.y + m33 * v.z
        );
}