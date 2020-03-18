#include "rmat.h"


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

