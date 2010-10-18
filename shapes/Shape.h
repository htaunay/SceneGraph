/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _SHAPE_H_
#define _SHAPE_H_

//! Virtual generic class for all shapes that are used in the Entity nodes
class Shape
{
public:
	Shape() {};

	virtual void draw() = 0;
};

#endif
