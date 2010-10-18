/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Shape.h"

//! Shape object in the from of a Sphere
class Sphere : public Shape
{
public:
	//! Draws a solid sphere in the scene, with the origin at the center of the object.
	virtual void draw();

public:
	//! Sphere constructor. The number of slices/stacks can be specified, but
	//! by default they are 64 both.
	Sphere( float radius, int slices = 64, int stacks = 64 ):
			_radius(radius), _slices(slices), _stacks(stacks){}

private:
	float _radius;
	int _slices, _stacks;
};
