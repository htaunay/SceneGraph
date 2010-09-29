#include "Sphere.h"

void Sphere::draw()
{
	glutSolidSphere( _radius, _slices, _stacks );
}
