/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Shape.h"

class Cylinder : public Shape
{
public:
	Cylinder( double baseRadius, double topRadius, double height,
			  bool closed = true, int slices = 15, int stacks = 10 );

    virtual void draw();

private:
	double _baseRadius;
	double _topRadius;
	double _height;
	bool _closed;
	int _slices, _stacks;
};
