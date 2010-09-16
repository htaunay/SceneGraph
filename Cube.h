#include "Shape.h"

class Cube : public Shape
{
public:
	Cube( float x, float y, float z, int slices = 50 );

    virtual void draw();

private:
	float _x, _y, _z;
	int _slices;
};
