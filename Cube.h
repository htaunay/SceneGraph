#include "Shape.h"

class Cube : public Shape
{
public:
	Cube( float x, float y, float z): _x(x), _y(y), _z(z){}

    virtual void draw();

private:
	float _x, _y, _z;
};
