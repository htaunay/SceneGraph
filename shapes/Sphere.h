/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere( float radius, int slices = 64, int stacks = 64 ):
			_radius(radius), _slices(slices), _stacks(stacks){}

	virtual void draw();

private:
	float _radius;
	int _slices, _stacks;
};
