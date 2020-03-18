#include "vect.h"
#include "MathUtil.h"

class rmat
{
public:
	 rmat();
	~rmat();
	
    float 	
        m11, m12, m13,
        m21, m22, m23,
        m31, m32, m33;

	void orientation(float, float, float);
    void rotate(/*const*/ vect&);

private:

};
