/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Shape.h"

//! Shape object in the from of a Cylinder, which can present its top and bottom
//! closed or open.
class Cylinder : public Shape
{
public:
	//! Draws a solid cylinder in the scene, with the origin at the bottom of the object.
	virtual void draw();

public:
	/*!
		Cylinder constructor. The number of slices/stacks can be specified, but
		by default they are 15 and 10, pespectively. The user can define if the
		Cylinders top/bottom are closed or open.
	*/
	Cylinder( double baseRadius, double topRadius, double height,
			  bool closed = true, int slices = 15, int stacks = 10 );

private:
	double _baseRadius;
	double _topRadius;
	double _height;
	bool _closed;
	int _slices, _stacks;
};
